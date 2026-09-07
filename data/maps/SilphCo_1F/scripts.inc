.set LOCALID_EXIT_GUARD, 2

SilphCo_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_1F_OnLoad
	.byte 0

SilphCo_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	end

SilphCo_1F_OnLoad::
	call SilphCo_1F_EventScript_HandleExitGuard
	end

SilphCo_1F_EventScript_HandleExitGuard::
	specialvar VAR_RESULT, GetLastUsedWarpMap
	goto_if_eq VAR_RESULT, MAP_SILPH_CO_2F, SilphCo_1F_EventScript_ExitGuardActive
	goto_if_eq VAR_RESULT, MAP_SILPH_CO_ELEVATOR, SilphCo_1F_EventScript_ExitGuardActive
	goto SilphCo_1F_EventScript_ExitGuardInactive

SilphCo_1F_EventScript_ExitGuardActive::
	goto_if_set FLAG_HIDE_SILPH_ROCKETS, SilphCo_1F_EventScript_ExitGuardInactive
	checktrainerflag TRAINER_SILPH_EXIT_GUARD
	goto_if_eq VAR_RESULT, TRUE, SilphCo_1F_EventScript_ExitGuardInactive
	clearflag FLAG_TEMP_1
	setvar VAR_TEMP_0, 1
	return

SilphCo_1F_EventScript_ExitGuardInactive::
	setflag FLAG_TEMP_1
	setvar VAR_TEMP_0, 0
	return

SilphCo_1F_EventScript_ExitAmbushElevator::
	lockall
	goto_if_set FLAG_TEMP_1, SilphCo_1F_EventScript_ExitAmbushReturn
	checktrainerflag TRAINER_SILPH_EXIT_GUARD
	goto_if_eq VAR_RESULT, TRUE, SilphCo_1F_EventScript_ExitAmbushReturn
	goto_if_set FLAG_HIDE_SILPH_ROCKETS, SilphCo_1F_EventScript_ExitAmbushReturn
	applymovement LOCALID_EXIT_GUARD, SilphCo_1F_Movement_ExitGuardFaceWest
	waitmovement 0
	trainerbattle_rocket TRAINER_SILPH_EXIT_GUARD, SilphCo_1F_Text_ExitGuardIntro, SilphCo_1F_Text_ExitGuardDefeat, SilphCo_1F_Text_ExitGuardRunAway
	releaseall
	end

SilphCo_1F_EventScript_ExitAmbushStairs::
	lockall
	goto_if_set FLAG_TEMP_1, SilphCo_1F_EventScript_ExitAmbushReturn
	checktrainerflag TRAINER_SILPH_EXIT_GUARD
	goto_if_eq VAR_RESULT, TRUE, SilphCo_1F_EventScript_ExitAmbushReturn
	goto_if_set FLAG_HIDE_SILPH_ROCKETS, SilphCo_1F_EventScript_ExitAmbushReturn
	applymovement LOCALID_EXIT_GUARD, SilphCo_1F_Movement_ExitGuardFaceEast
	waitmovement 0
	trainerbattle_rocket TRAINER_SILPH_EXIT_GUARD, SilphCo_1F_Text_ExitGuardIntro, SilphCo_1F_Text_ExitGuardDefeat, SilphCo_1F_Text_ExitGuardRunAway
	releaseall
	end

SilphCo_1F_EventScript_ExitAmbushReturn::
	releaseall
	end

SilphCo_1F_EventScript_ExitGuard::
	lock
	faceplayer
	msgbox SilphCo_1F_Text_ExitGuardTalk, MSGBOX_DEFAULT
	release
	end

SilphCo_1F_Text_ExitGuardRunAway::
	msgbox SilphCo_1F_Text_ExitGuardPostBattle
	closemessage
	applymovement LOCALID_EXIT_GUARD, SilphCo_1F_Movement_ExitGuardRunAway
	waitmovement 0
	removeobject LOCALID_EXIT_GUARD
	releaseall
	end

SilphCo_1F_Movement_ExitGuardFaceWest::
	face_left
	step_end

SilphCo_1F_Movement_ExitGuardFaceEast::
	face_right
	step_end

SilphCo_1F_Movement_ExitGuardRunAway::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end
