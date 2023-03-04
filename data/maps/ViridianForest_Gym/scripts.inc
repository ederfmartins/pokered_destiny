ViridianForest_Gym_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, ViridianForest_Gym_SetTrap
	.byte 0

ViridianForest_Gym_SetTrap::
	goto_if_unset FLAG_BADGE11_GET, ViridianForest_Gym_SetTrap_1
	return

ViridianForest_Gym_SetTrap_1:
	cleartrainerflag TRAINER_BUG1
	cleartrainerflag TRAINER_BUG2
	cleartrainerflag TRAINER_BUG3
	return


ViridianForest_Gym_Gymman::
	lockall
	faceplayer
	msgbox ViridianForest_Gym_Gymman_Text_0
	releaseall
	end


ViridianForest_Gym_Bug1::
	lock
	faceplayer
	trainerbattle_single TRAINER_BUG1, ViridianForest_Gym_Bug1_Text_0, ViridianForest_Gym_Bug1_Text_1
	msgbox ViridianForest_Gym_Bug1_Text_2
	release
	end


ViridianForest_Gym_Bug2::
	lock
	faceplayer
	trainerbattle_single TRAINER_BUG2, ViridianForest_Gym_Bug2_Text_0, ViridianForest_Gym_Bug2_Text_1
	msgbox ViridianForest_Gym_Bug2_Text_2
	release
	end


ViridianForest_Gym_Bug3::
	lock
	faceplayer
	trainerbattle_single TRAINER_BUG3, ViridianForest_Gym_Bug3_Text_0, ViridianForest_Gym_Bug3_Text_1
	msgbox ViridianForest_Gym_Bug3_Text_2
	release
	end


ViridianForest_Gym_BugLeader::
	lock
	faceplayer
	trainerbattle_single TRAINER_LIDER_BUG, ViridianForest_Gym_BugLeader_Text_0, ViridianForest_Gym_BugLeader_Text_1, ViridianForest_Gym_BugLeader_afterbattle
	msgbox ViridianForest_Gym_Bug3_Text_2
	release
	end


ViridianForest_Gym_BugLeader_afterbattle::
	setflag FLAG_BADGE11_GET
	msgbox ViridianForest_Gym_BugLeader_afterbattle_Text_0
	release
	end


ViridianForest_Gym_Gymman_Text_0:
	.string "This is the Hidden Bug Gym. Be carefull\n"
	.string "there are bugs everywere! Also, avoid\l"
	.string "the triple twins, they do not behave\l"
	.string "well.$"

ViridianForest_Gym_Bug1_Text_0:
	.string "Bugs are amazing and will make shit of\n"
	.string "your life.$"

ViridianForest_Gym_Bug1_Text_1:
	.string "It is impossible, I lose!$"

ViridianForest_Gym_Bug1_Text_2:
	.string "Next time, I will show the bug power to\n"
	.string "you.$"

ViridianForest_Gym_Bug2_Text_0:
	.string "I love bugs, they are fundamental to\n"
	.string "nature.$"

ViridianForest_Gym_Bug2_Text_1:
	.string "Now you are prepared for the next\n"
	.string "challenge.$"

ViridianForest_Gym_Bug2_Text_2:
	.string "Do you know that I love bugs?$"

ViridianForest_Gym_Bug3_Text_0:
	.string "Are you smeling this?$"

ViridianForest_Gym_Bug3_Text_1:
	.string "Dan it, I lose again!$"

ViridianForest_Gym_Bug3_Text_2:
	.string "It was not fare. Bug will revenge me!$"

ViridianForest_Gym_BugLeader_Text_0:
	.string "You have passed bug maze. Congrats.\n"
	.string "Now you are prepared for the hidden\l"
	.string "bug.$"

ViridianForest_Gym_BugLeader_Text_1:
	.string "You deserve that!$"

ViridianForest_Gym_BugLeader_afterbattle_Text_0:
	.string "You got the HIDDEN BUG BADGE$"
