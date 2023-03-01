PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn SPAWN_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
	special Script_SetHelpContext
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special AnimatePcTurnOff
	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_GivePokemon::
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	settrainerflag TRAINER_YAZ_LEADER
	settrainerflag TRAINER_BLACK_BELT_KOICHI
	additem ITEM_HM01
	additem ITEM_HM02
	additem ITEM_HM03
	additem ITEM_HM04
	additem ITEM_HM05
	additem ITEM_HM06
	additem ITEM_HM07
	additem ITEM_HM08
	additem ITEM_POKE_FLUTE
	additem ITEM_BICYCLE
	
	givemon SPECIES_KADABRA, 35
	givemon SPECIES_NINETALES, 35
	givemon SPECIES_IVYSAUR, 36
	givemon SPECIES_STARYU, 35
	givemon SPECIES_PIDGEOTTO, 36
	givemon SPECIES_PRIMEAPE, 40
	givemon SPECIES_RAICHU, 36
	setflag FLAG_SYS_POKEMON_GET
	end
