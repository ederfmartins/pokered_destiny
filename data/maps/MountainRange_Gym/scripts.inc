MountainRange_Gym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MountainRange_Gym_SetTrap
	.byte 0

MountainRange_Gym_SetTrap::
	setvar VAR_TEMP_0, 0
	goto_if_unset FLAG_BADGE14_GET, MountainRange_Gym_SetTrap_1
	return

MountainRange_Gym_SetTrap_1:
	cleartrainerflag TRAINER_FLYGYM1
	cleartrainerflag TRAINER_FLYGYM2
	cleartrainerflag TRAINER_FLYGYM3
	return


MountainRange_Gym_ActivateTrap::
	setvar VAR_TEMP_0, 1
	end


MountainRange_Gym_Trap::
	compare VAR_TEMP_0, 1
	goto_if_eq MountainRange_Gym_Trap_3
MountainRange_Gym_Trap_1:
	end

MountainRange_Gym_Trap_2:
	lockall
	msgbox MountainRange_Gym_Trap_Text_0
	releaseall
	applymovement OBJ_EVENT_ID_PLAYER, MountainRange_Gym_Trap_ForceMove
	goto MountainRange_Gym_Trap_1

MountainRange_Gym_Trap_3:
	goto_if_unset FLAG_BADGE14_GET, MountainRange_Gym_Trap_2
	goto MountainRange_Gym_Trap_1


MountainRange_Gym_Trap_ForceMove:
	walk_up
	walk_up
	face_down
	step_end

MountainRange_Gym_Guy::
	lockall
	faceplayer
	msgbox MountainRange_Gym_Guy_Text_0
	releaseall
	end


MountainRange_Gym_Battle1::
	trainerbattle_single TRAINER_FLYGYM1, MountainRange_Gym_Battle1_Text_0, MountainRange_Gym_Battle1_Text_1
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MountainRange_Gym_Battle1_2
MountainRange_Gym_Battle1_1:
	msgbox MountainRange_Gym_Battle1_Text_2, MSGBOX_AUTOCLOSE
	end

MountainRange_Gym_Battle1_2:
	trainerbattle_rematch TRAINER_FLYGYM1, MountainRange_Gym_Battle1_Text_0, MountainRange_Gym_Battle1_Text_1
	goto MountainRange_Gym_Battle1_1


MountainRange_Gym_Battle2::
	trainerbattle_single TRAINER_FLYGYM2, MountainRange_Gym_Battle1_Text_0, MountainRange_Gym_Battle1_Text_1
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MountainRange_Gym_Battle2_2
MountainRange_Gym_Battle2_1:
	msgbox MountainRange_Gym_Battle2_Text_2, MSGBOX_AUTOCLOSE
	end

MountainRange_Gym_Battle2_2:
	trainerbattle_rematch TRAINER_FLYGYM2, MountainRange_Gym_Battle2_Text_0, MountainRange_Gym_Battle2_Text_1
	goto MountainRange_Gym_Battle2_1


MountainRange_Gym_Battle3::
	trainerbattle_single TRAINER_FLYGYM3, MountainRange_Gym_Battle3_Text_0, MountainRange_Gym_Battle3_Text_1
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MountainRange_Gym_Battle3_2
MountainRange_Gym_Battle3_1:
	msgbox MountainRange_Gym_Battle3_Text_4, MSGBOX_AUTOCLOSE
	end

MountainRange_Gym_Battle3_2:
	trainerbattle_rematch TRAINER_FLYGYM3, MountainRange_Gym_Battle3_Text_2, MountainRange_Gym_Battle3_Text_3
	goto MountainRange_Gym_Battle3_1


MountainRange_Gym_LeaderKahili::
	lock
	faceplayer
	trainerbattle_single TRAINER_LIDER_KAHILI, MountainRange_Gym_LeaderKahili_Text_0, MountainRange_Gym_LeaderKahili_Text_1, MountainRange_Gym_LeaderKahili_afterbattle
	msgbox MountainRange_Gym_LeaderKahili_Text_2, MSGBOX_AUTOCLOSE
	end


MountainRange_Gym_LeaderKahili_afterbattle::
	setflag FLAG_BADGE14_GET
	msgbox MountainRange_Gym_LeaderKahili_afterbattle_Text_0
	setvar VAR_TEMP_0, 2
	release
	end


MountainRange_Gym_Trap_Text_0:
	.string "A strong wind blocked your passage.$"

MountainRange_Gym_Guy_Text_0:
	.string "KAHILI has a well prepared FLYING team.\n"
	.string "Be ready!.$"

MountainRange_Gym_Battle1_Text_0:
	.string "You shall not pass!$"

MountainRange_Gym_Battle1_Text_1:
	.string "Well done, prepare yourself for the\n"
	.string "next battle.$"

MountainRange_Gym_Battle1_Text_2:
	.string "You're prepared for KAHILI$"

MountainRange_Gym_Battle2_Text_0:
	.string "Are you ready for KAHILI?$"

MountainRange_Gym_Battle2_Text_1:
	.string "At least, you are prepared for me.$"

MountainRange_Gym_Battle2_Text_2:
	.string "I did my part, now is up to KAHILI.$"

MountainRange_Gym_Battle3_Text_0:
	.string "Now it is my time$"

MountainRange_Gym_Battle3_Text_1:
	.string "You got me.$"

MountainRange_Gym_Battle3_Text_2:
	.string "This time will be different.$"

MountainRange_Gym_Battle3_Text_3:
	.string "You got me again.$"

MountainRange_Gym_Battle3_Text_4:
	.string "KAHILI will revenge me!$"

MountainRange_Gym_LeaderKahili_Text_0:
	.string "Do you want the FREEDON BADGE? Proof\n"
	.string "you are a good trainer!$"

MountainRange_Gym_LeaderKahili_Text_1:
	.string "I love this battle. We should battle in\n"
	.string "the future again.$"

MountainRange_Gym_LeaderKahili_Text_2:
	.string "We should battle in the future again.$"

MountainRange_Gym_LeaderKahili_afterbattle_Text_0:
	.string "You got the FREEDON BADGE$"
