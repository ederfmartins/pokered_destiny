DragoniteIsle_MapScripts::
	.byte 0

DragoniteIsle_Lance::
	lock
	faceplayer
	msgbox DragoniteIsle_Lance_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DragoniteIsle_Lance_2
	msgbox DragoniteIsle_Lance_Text_3
DragoniteIsle_Lance_1:
	release
	end

DragoniteIsle_Lance_2:
	trainerbattle_single TRAINER_LANCE_GYMLEADER, DragoniteIsle_Lance_Text_1, DragoniteIsle_Lance_Text_2, DragoniteIsle_afterbattle
	goto DragoniteIsle_Lance_1


DragoniteIsle_afterbattle::
	setflag FLAG_BADGE15_GET
	msgbox DragoniteIsle_afterbattle_Text_0
	release
	end


DragoniteIsle_Lance_Text_0:
	.string "Oh! It is a great deed to find this\n"
	.string "place. Sometimes, I went here to relax\l"
	.string "and allow my POKéMON to be with other\l"
	.string "of their kind. This island has some\l"
	.string "special power. I have a gift for you. Do\l"
	.string "you want to battle me?$"

DragoniteIsle_Lance_Text_1:
	.string "Let see if you are able to feel the\n"
	.string "Dragon Heart.$"

DragoniteIsle_Lance_Text_2:
	.string "I feel nostalgic. It is being long time I\n"
	.string "don't battle in my GYM.$"

DragoniteIsle_Lance_Text_3:
	.string "Sorry, but we already battle before. If\n"
	.string "you want to do it again, the Indigo\l"
	.string "Plateau is the perfect place.$"

DragoniteIsle_afterbattle_Text_0:
	.string "You got the DRAGON HEART BADGE$"
