NormalGymCity_MapScripts::
	.byte 0

NormalGymCity_EventScripts_DoorLocked::
	lockall
	msgbox NormalGymCity_EventScripts_DoorLocked_Text
	closemessage
	releaseall
	end

NormalGymCity_EventScripts_Gym_Sign::
	lockall
	msgbox NormalGymCity_EventScripts_Gym_Sign_Text
	closemessage
	releaseall
	end
