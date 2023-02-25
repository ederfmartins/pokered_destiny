TwoIsland_CapeBrink_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TwoIsland_CapeBrink_BadgeEvent
	.byte 0

TwoIsland_CapeBrink_gilr::
	lock
	faceplayer
	msgbox TwoIsland_CapeBrink_gilr_Text_0
	release
	end


TwoIsland_CapeBrink_gilr2::
	lock
	faceplayer
	msgbox TwoIsland_CapeBrink_gilr2_Text_0
	release
	end


TwoIsland_CapeBrink_boy::
	lock
	faceplayer
	msgbox TwoIsland_CapeBrink_boy_Text_0
	release
	end


TwoIsland_CapeBrink_lorelei::
	lock
	faceplayer
	msgbox TwoIsland_CapeBrink_lorelei_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq TwoIsland_CapeBrink_lorelei_2
	msgbox TwoIsland_CapeBrink_lorelei_Text_3
TwoIsland_CapeBrink_lorelei_1:
	release
	end

TwoIsland_CapeBrink_lorelei_2:
	trainerbattle_single TRAINER_LORELEI_GYMLEADER, TwoIsland_CapeBrink_lorelei_Text_1, TwoIsland_CapeBrink_lorelei_Text_2, TwoIsland_CapeBrink_afterbattle
	goto TwoIsland_CapeBrink_lorelei_1


TwoIsland_CapeBrink_afterbattle::
	setflag FLAG_BADGE09_GET
	msgbox TwoIsland_CapeBrink_afterbattle_Text_0
	release
	end


TwoIsland_CapeBrink_BadgeEvent::
	goto_if_set FLAG_BADGE09_GET, TwoIsland_CapeBrink_BadgeEvent_1
	specialvar VAR_RESULT, TrainerMetIceGymPrereq
	compare VAR_RESULT, 0
	goto_if_eq TwoIsland_CapeBrink_BadgeEvent_4
	return

TwoIsland_CapeBrink_BadgeEvent_1:
	setflag FLAG_TEMP_1
	return

TwoIsland_CapeBrink_BadgeEvent_4:
	setflag FLAG_TEMP_1
	return


TwoIsland_CapeBrink_gilr_Text_0:
	.string "I'm learning a lot with LORELEI.$"

TwoIsland_CapeBrink_gilr2_Text_0:
	.string "I love LORELEI. She is like water and\n"
	.string "teach us the secrets to be a POKéMON\l"
	.string "master.$"

TwoIsland_CapeBrink_boy_Text_0:
	.string "One day, I will battle against the ELITE\n"
	.string "FOUR!$"

TwoIsland_CapeBrink_lorelei_Text_0:
	.string "When I battle I try to be like water...\p"
	.string "Ohh, I see a powefull stream in you! Are\n"
	.string "you able to adapt in any situation?$"

TwoIsland_CapeBrink_lorelei_Text_1:
	.string "Try to follow the stream.$"

TwoIsland_CapeBrink_lorelei_Text_2:
	.string "Tank you! I have a special gift for your\n"
	.string "help.$"

TwoIsland_CapeBrink_lorelei_Text_3:
	.string "I already finished my lessons for\n"
	.string "today. Come back another day to\l"
	.string "participate.$"

TwoIsland_CapeBrink_afterbattle_Text_0:
	.string "You got the ADAPTATIVE STREAM BADGE$"
