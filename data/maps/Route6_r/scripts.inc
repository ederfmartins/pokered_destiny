Route6_r_MapScripts::
	.byte 0

Route6_r_Gym_Desc::
	lock
	msgbox Route6_r_Gym_Desc_Text_0
	closemessage
	releaseall
	end


Route6_r_Door::
	lock
	msgbox Route6_r_Door_Text_0
	closemessage
	releaseall
	end


Route6_r_Wooman::
	lock
	faceplayer
	msgbox Route6_r_Wooman_Text_0
	closemessage
	releaseall
	end


Route6_r_aj::
	lock
	faceplayer
	msgbox Route6_r_aj_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route6_r_aj_2
	msgbox Route6_r_aj_Text_4
Route6_r_aj_1:
	closemessage
	releaseall
	end

Route6_r_aj_2:
	msgbox Route6_r_aj_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route6_r_aj_5
	msgbox Route6_r_aj_Text_3
	goto Route6_r_aj_1

Route6_r_aj_5:
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_AJ, 0, Route6_r_aj_Battle_Start, Route6_r_aj_Battle_End
	msgbox Route6_r_aj_Text_2
	goto Route6_r_aj_1


Route6_r_Gym_Desc_Text_0:
	.string "A. J.'s Gym\p99 defeated trainers.$"

Route6_r_Door_Text_0:
	.string "The door is locked.$"

Route6_r_Wooman_Text_0:
	.string "Look at my beautifull garden.$"

Route6_r_aj_Text_0:
	.string "Hi. My name is AJ.\p"
	.string "I belive we should be rigorous when\n"
	.string "training our POKEMONS. Do you agree?$"

Route6_r_aj_Text_1:
	.string "Would you like to test my method?$"

Route6_r_aj_Text_2:
	.string "Sorry {PLAYER} but I never battle\n"
	.string "twice with the same trainer'.$"

Route6_r_aj_Text_3:
	.string "{PLAYER}: No, I already had enouth\n"
	.string "for one live.$"

Route6_r_aj_Text_4:
	.string "When I reach my 100th victory, I will\n"
	.string "show the power of this method to the\l"
	.string "would!$"

Route6_r_aj_Battle_Start::
	.string "The secret of power relies on hard work!$"

Route6_r_aj_Battle_End::
	.string "Your POKEMONS are really strong$"
