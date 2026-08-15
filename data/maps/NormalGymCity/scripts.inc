NormalGymCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NormalGymCity_OnTransition
	.byte 0

NormalGymCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NORMAL_GYM_CITY
	end

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

NormalGymCity_EventScripts_House1_Sign::
	lockall
	msgbox NormalGymCity_EventScripts_House1_Sign_Text
	closemessage
	releaseall
	end

