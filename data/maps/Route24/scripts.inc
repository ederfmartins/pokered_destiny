.equ LOCALID_ROCKET, 1

Route24_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, Route24_SetTrap
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
    setvar VAR_TEMP_0, 0
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROCKET
    setvar VAR_TEMP_1, 0
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_EventScript_Cale::
	trainerbattle_enforce_set TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleIntro, Route24_Text_CaleDefeat, Route24_ActivateTrap
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route24_EventScript_CaleRematch
	msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_CaleRematch::
	trainerbattle_rematch TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleRematchIntro, Route24_Text_CaleDefeat
	msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route24_SetTrap::
	setvar VAR_TEMP_0, 0
	return


Route24_ActivateTrap::
	setvar VAR_TEMP_0, 1
	end


Route24_Trap::
	compare VAR_TEMP_0, 1
	goto_if_eq Route24_Trap_4
Route24_Trap_3:
	setvar VAR_TEMP_0, 0
Route24_Trap_1:
	end

Route24_Trap_2:
	lockall
	msgbox Route24_Trap_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Trap_ForceMove
	goto Route24_Trap_1

Route24_Trap_4:
	goto_if_unset TRAINER_FLAGS_START + TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Trap_2
	goto Route24_Trap_3


Route24_Trap_ForceMove:
	walk_up
	walk_up
	face_down
	step_end

Route24_Trap_Text_0:
	.string "I forgot to mention, you should defeat\n"
	.string "all the trainers now!$"
