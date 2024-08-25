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
	@ additem ITEM_REPEL, 3
	@ additem ITEM_GREAT_BALL, 10
	@ additem ITEM_POKE_BALL, 10
	@ additem ITEM_POTION, 10
	@ additem ITEM_FULL_HEAL, 3
	@ additem ITEM_REVIVE, 3
	givemon SPECIES_IVYSAUR, 30
	givemon SPECIES_CHARMELEON, 30
	givemon SPECIES_WARTORTLE, 30
	givemon SPECIES_PIKACHU, 30
	givemon SPECIES_PIDGEOTTO, 30
	givemon SPECIES_PERSIAN, 30
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET

	giveitem ITEM_HM01
	setflag FLAG_GOT_HM01

	giveitem ITEM_HM02
	setflag FLAG_GOT_HM02

	giveitem ITEM_HM03
	setflag FLAG_GOT_HM03

	giveitem ITEM_HM04
	setflag FLAG_GOT_HM04

	giveitem ITEM_HM05
	setflag FLAG_GOT_HM05

	lockall
	msgbox PalletTown_PlayersHouse_2F_Text_Give_Item
	giveitem_msg PalletTown_PlayersHouse_2F_Text_Give_Item1, ITEM_RARE_CANDY, 20
	closemessage
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_REPELL::
	msgbox PalletTown_PlayersHouse_2F_Text_Repell
	closemessage
	releaseall
	finditem ITEM_REPEL, 10
	end
