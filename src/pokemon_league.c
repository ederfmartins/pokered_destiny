#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_transition.h"
#include "data.h"
#include "event_data.h"
#include "overworld.h"
#include "pokemon_league.h"
#include "random.h"
#include "string_util.h"
#include "task.h"

// The extra 6-mon trainer parties are random, but the opponent's class, name,
// sprite and battle quotes come from these existing game trainers.
static const u16 sPokemonLeagueTrainerRoster[] =
{
    TRAINER_COOLTRAINER_ALEXA,
    TRAINER_SWIMMER_MALE_LUIS,
    TRAINER_SWIMMER_FEMALE_ABIGAIL,
    TRAINER_SUPER_NERD_JOVAN,
    TRAINER_BLACK_BELT_AARON,
    TRAINER_BEAUTY_BRIDGET,
    TRAINER_BIRD_KEEPER_BECK,
    TRAINER_EXPERT_M,
    TRAINER_TAMER_COLE,
    TRAINER_SCIENTIST_BEAU,
    TRAINER_POKEMANIAC_ASHTON,
    TRAINER_JUGGLER_DALTON,
    TRAINER_GENTLEMAN_ARTHUR,
    TRAINER_LADY_JACKI,
    TRAINER_ROCKER_LUCA,
    TRAINER_SAILOR_DUNCAN,
};

static struct PokemonLeagueRun
{
    u16 trainerIds[POKEMON_LEAGUE_BATTLES];
    bool8 initialized;
} sPokemonLeagueRun;

static void PokemonLeague_TryInitRun(void)
{
    s32 i, j;

    if (sPokemonLeagueRun.initialized)
        return;

    for (i = 0; i < POKEMON_LEAGUE_BATTLES; i++)
    {
        s32 index;
        s32 attempts = 0;

        do
        {
            index = Random() % NELEMS(sPokemonLeagueTrainerRoster);
            attempts++;
            for (j = 0; j < i; j++)
            {
                if (sPokemonLeagueRun.trainerIds[j] == sPokemonLeagueTrainerRoster[index])
                    break;
            }
        } while (j != i && attempts < 10);

        sPokemonLeagueRun.trainerIds[i] = sPokemonLeagueTrainerRoster[index];
    }

    sPokemonLeagueRun.initialized = TRUE;
}

static u8 PokemonLeague_GetBattleNum(void)
{
    u8 battleNum = gSpecialVar_0x8004;

    if (battleNum < 1 || battleNum > POKEMON_LEAGUE_BATTLES)
        battleNum = 1;

    return battleNum;
}

void ResetPokemonLeagueRun(void)
{
    sPokemonLeagueRun.initialized = FALSE;
}

void GetPokemonLeagueOpponentInfo(void)
{
    u8 battleNum = PokemonLeague_GetBattleNum();
    u16 trainerId;

    PokemonLeague_TryInitRun();
    trainerId = sPokemonLeagueRun.trainerIds[battleNum - 1];

    StringCopy(gStringVar1, gTrainers[trainerId].trainerName);
    StringCopy(gStringVar2, gTrainerClassNames[gTrainers[trainerId].trainerClass]);
}

static void CB2_EndPokemonLeagueBattle(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_WaitStartPokemonLeagueBattle(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = CB2_EndPokemonLeagueBattle;
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

void StartPokemonLeagueBattle(void)
{
    u8 battleNum = PokemonLeague_GetBattleNum();

    PokemonLeague_TryInitRun();

    gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_POKEMON_LEAGUE;
    gTrainerBattleOpponent_A = sPokemonLeagueRun.trainerIds[battleNum - 1];

    FillPokemonLeagueEnemyParty();

    CreateTask(Task_WaitStartPokemonLeagueBattle, 1);
    PlayMapChosenOrBattleBGM(0);
    BattleTransition_StartOnField(BattleSetup_GetBattleTowerBattleTransition());
}