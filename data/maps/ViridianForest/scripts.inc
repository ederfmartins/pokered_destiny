ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ViridianForest_OnLoadWeather
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_OnLoadWeather::
	random 10
	compare VAR_RESULT, 3
	goto_if_le ViridianForest_EventScript_ChangeWeather
	setflag FLAG_TEMP_1
	end

ViridianForest_EventScript_ChangeWeather::
	setweather WEATHER_DOWNPOUR
	doweather
	end

ViridianForest_EventScript_BugGymWarp::
	lockall
	faceplayer
	specialvar VAR_RESULT, TrainerMetBugGymPrereq
	compare VAR_RESULT, 1
	goto_if_eq ViridianForest_EventScript_BugGymWarp_2
	msgbox ViridianForest_EventScript_BugGymWarp_Text_0
ViridianForest_EventScript_BugGymWarp_1:
	releaseall
	end

ViridianForest_EventScript_BugGymWarp_2:
	msgbox ViridianForest_Text_BugGymWarp, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq ViridianForest_EventScript_BugGymWarp_5
	goto ViridianForest_EventScript_BugGymWarp_1

ViridianForest_EventScript_BugGymWarp_5:
	warp MAP_VIRIDIAN_FOREST_HIDDEN_GYM, 7, 7
	goto ViridianForest_EventScript_BugGymWarp_1


ViridianForest_EventScript_BugGymWarp_Text_0:
	.string "I love Bugs, if you are able to show the\n"
	.string "right one to me, I will tell you a very\l"
	.string "special secret.$"
