LavenderTown_House3_MapScripts::
	.byte 0

LavenderTown_House3_girl::
	lock
	faceplayer
	msgbox LavenderTown_House3_girl_Text_0
	release
	end


LavenderTown_House3_agatha::
	lock
	faceplayer
	goto_if_set FLAG_BADGE12_GET, LavenderTown_House3_agatha_2
	specialvar VAR_RESULT, TrainerMetGhostGymPrereq
	compare VAR_RESULT, 1
	goto_if_eq LavenderTown_House3_agatha_5
	msgbox LavenderTown_House3_agatha_Text_6
LavenderTown_House3_agatha_1:
	release
	end

LavenderTown_House3_agatha_2:
	msgbox LavenderTown_House3_agatha_Text_0
	goto LavenderTown_House3_agatha_1

LavenderTown_House3_agatha_5:
	msgbox LavenderTown_House3_agatha_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LavenderTown_House3_agatha_8
	msgbox LavenderTown_House3_agatha_Text_5
	goto LavenderTown_House3_agatha_1

LavenderTown_House3_agatha_8:
	msgbox LavenderTown_House3_agatha_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LavenderTown_House3_agatha_11
	goto LavenderTown_House3_agatha_1

LavenderTown_House3_agatha_11:
	trainerbattle_single TRAINER_AGATHA_GYMLEADER, LavenderTown_House3_agatha_Text_3, LavenderTown_House3_agatha_Text_4, LavenderTown_House3_afterbattle
	goto LavenderTown_House3_agatha_1


LavenderTown_House3_afterbattle::
	setflag FLAG_BADGE12_GET
	msgbox LavenderTown_House3_afterbattle_Text_0
	return


LavenderTown_House3_girl_Text_0:
	.string "I'm studing with my grand mother to\n"
	.string "became the best gym leader of all time.\l"
	.string "I'm not affraid of ghosts anymore.$"

LavenderTown_House3_agatha_Text_0:
	.string "It was nice to\n"
	.string "battle with you.\p"
	.string "I see what the old duff sees in\n"
	.string "you.\p"
	.string "I belive we will meet again\n"
	.string "in the Indigo Plateau.$"

LavenderTown_House3_agatha_Text_1:
	.string "I belive POKéMON are for battling!\p"
	.string "What do you think?$"

LavenderTown_House3_agatha_Text_2:
	.string "As a GHOST type lover, can you help me\n"
	.string "with my grand daugther.$"

LavenderTown_House3_agatha_Text_3:
	.string "Let see what you can do!$"

LavenderTown_House3_agatha_Text_4:
	.string "Well done! I have a special gift for you.$"

LavenderTown_House3_agatha_Text_5:
	.string "I don't know what the old duff sees in\n"
	.string "you.$"

LavenderTown_House3_agatha_Text_6:
	.string "Due to my duties, I had to put the GHOST\n"
	.string "Gym into a pause. One day it will be\l"
	.string "available again.$"

LavenderTown_House3_afterbattle_Text_0:
	.string "You got the DARK SOUL BADGE$"
