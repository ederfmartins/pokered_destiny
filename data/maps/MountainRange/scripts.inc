MountainRange_MapScripts::
	.byte 0

MountainRange_Old_Woman::
	lock
	faceplayer
	msgbox MountainRange_Old_Woman_Text_0
	release
	end


MountainRange_Door::
	lock
	msgbox MountainRange_Door_Text_0
	release
	return


MountainRange_Gym_Sign::
	lock
	msgbox MountainRange_Gym_Sign_Text_0
	release
	return


MountainRange_Old_Woman_Text_0:
	.string "Nuzlockers are not welcome here.$"

MountainRange_Door_Text_0:
	.string "This door is locked.$"

MountainRange_Gym_Sign_Text_0:
	.string "MOUNTAIN RAGE CITY POKéMON GYM\n"
	.string "LEADER: KAHILI\l"
	.string "The freedon POKéMON TRAINER!$"
