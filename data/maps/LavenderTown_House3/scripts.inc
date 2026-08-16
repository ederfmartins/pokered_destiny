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
	trainerbattle_enforce_set TRAINER_AGATHA_GYMLEADER, LavenderTown_House3_agatha_Text_3, LavenderTown_House3_agatha_Text_4, LavenderTown_House3_afterbattle
	goto LavenderTown_House3_agatha_1


LavenderTown_House3_afterbattle::
	setflag FLAG_BADGE12_GET
	giveitem ITEM_TM30
	msgbox LavenderTown_House3_afterbattle_Text_0
	msgbox LavenderTown_House3_Text_ExplainTM
	release
	end


LavenderTown_House3_girl_Text_0:
	.string "I'm studying hard with my grandma.\nI'm not affraid of GHOSTS.\pDo you have one with you?$"

LavenderTown_House3_agatha_Text_0:
	.string "It was nice to\nbattle with you.\pI see what the old duff sees in\nyou.\pI belive we will meet again\n in the Indigo Plateau.$"

LavenderTown_House3_agatha_Text_1:
	.string "I belive POKéMON are for battling!\p"
	.string "What do you think?$"

LavenderTown_House3_agatha_Text_2:
	.string "Can you help me with my\ngranddaugther?$"

LavenderTown_House3_agatha_Text_3:
	.string "Let see what you can do!$"

LavenderTown_House3_agatha_Text_4:
	.string "Well done! I have a special gift for you.$"

LavenderTown_House3_agatha_Text_5:
	.string "I don't know what the old duff sees in\n"
	.string "you.$"

LavenderTown_House3_agatha_Text_6:
	.string "I had to put the GHOST GYM on hold.\pI can see your POKéMON are not at\nthe destined moment.\pNot as green as a TENTACOOL...\nNot as seasoned as a VENUSAUR.$"

LavenderTown_House3_afterbattle_Text_0:
	.string "You got the DARK SOUL BADGE$"

LavenderTown_House3_Text_ExplainTM:
	.string "TM30 contains SHADOW BALL.\n"
	.string "A sinister GHOST-type attack that\n"
	.string "may lower SP. DEF.$"
