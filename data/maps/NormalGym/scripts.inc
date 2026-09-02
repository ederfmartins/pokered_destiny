NormalGym_MapScripts::
	.byte 0

NormalGym_LeaderNorman::
	lock
	faceplayer
	trainerbattle_enforce_set TRAINER_LIDER_NORMAN, NormalGym_LeaderNorman_Text_0, NormalGym_LeaderNorman_Text_1, NormalGym_LeaderNorman_afterbattle
	msgbox NormalGym_LeaderNorman_Text_2, MSGBOX_AUTOCLOSE
	end


NormalGym_LeaderNorman_afterbattle::
	setflag FLAG_BADGE13_GET
	giveitem ITEM_TM10_SWORDS_DANCE
	msgbox NormalGym_LeaderNorman_afterbattle_Text_0
	msgbox NormalGym_LeaderNorman_afterbattle_Text_1
	release
	end


NormalGym_LeaderNorman_Text_0:
	.string "Let's see if Oak is right about you!$"

NormalGym_LeaderNorman_Text_1:
	.string "Nice done. You really is ready to become\n"
	.string "a champion.$"

NormalGym_LeaderNorman_Text_2:
	.string "It was a memorable battle, last time.\n"
	.string "Nice to see you back. We should try\l"
	.string "again in the future.$"

NormalGym_LeaderNorman_afterbattle_Text_0:
	.string "You got the CUPPERBADGE$"

NormalGym_LeaderNorman_afterbattle_Text_1:
	.string "TM10 contains SWORDS DANCE.\n"
	.string "It sharply raises the ATTACK of your\l"
	.string "POKéMON in battle.$"
