ViridianForest_HiddenGym_MapScripts::
	.byte 0

ViridianForest_HiddenGym_BugGymWarp::
	lockall
	faceplayer
	msgbox ViridianForest_HiddenGym_BugGymWarp_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq ViridianForest_HiddenGym_BugGymWarp_2
ViridianForest_HiddenGym_BugGymWarp_1:
	releaseall
	end

ViridianForest_HiddenGym_BugGymWarp_2:
	warp MAP_VIRIDIAN_FOREST, 29, 61
	goto ViridianForest_HiddenGym_BugGymWarp_1


ViridianForest_HiddenGym_GymSign::
	lockall
	faceplayer
	msgbox ViridianForest_HiddenGym_GymSign_Text_0
	releaseall
	end


ViridianForest_HiddenGym_BugGymWarp_Text_0:
	.string "Should we come back?$"

ViridianForest_HiddenGym_GymSign_Text_0:
	.string "Viridian hidden Bug Gym$"
