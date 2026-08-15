NormalCity_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NormalCity_House1_OnTransition
	.byte 0

NormalCity_House1_OnTransition::
	random 2
	goto_if_eq VAR_RESULT, 0, NormalCity_House1_OnTransition_BerryRipe
	setvar VAR_TEMP_0, 0
	end

NormalCity_House1_OnTransition_BerryRipe::
	setvar VAR_TEMP_0, 1
	end

NormalCity_House1_EventScript_Gentleman::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox NormalCity_House1_Text_HelpMonEvolve, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NormalCity_House1_EventScript_Bye

NormalCity_House1_EventScript_ChooseMon::
	msgbox NormalCity_House1_Text_WhichMon
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	goto_if_ge VAR_0x8004, PARTY_SIZE, NormalCity_House1_EventScript_Bye
	specialvar VAR_RESULT, IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, NormalCity_House1_EventScript_CantEvolveMon
	specialvar VAR_RESULT, CanSelectedMonEvolve
	goto_if_eq VAR_RESULT, FALSE, NormalCity_House1_EventScript_CantEvolveMon
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox NormalCity_House1_Text_EvolveFor5000, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NormalCity_House1_EventScript_Bye
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, NormalCity_House1_EventScript_NoMoney
	removemoney 5000, 0
	updatemoneybox
	special EvolveSelectedMon
	waitstate
	msgbox NormalCity_House1_Text_Success
	goto NormalCity_House1_EventScript_Bye
	end

NormalCity_House1_EventScript_CantEvolveMon::
	msgbox NormalCity_House1_Text_NotReadyToEvolve
	goto NormalCity_House1_EventScript_Bye
	end

NormalCity_House1_EventScript_NoMoney::
	msgbox NormalCity_House1_Text_NotEnoughMoney
	goto NormalCity_House1_EventScript_Bye
	end

NormalCity_House1_EventScript_Bye::
	hidemoneybox
	release
	end

NormalCity_House1_EventScript_Chef::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_0, 1, NormalCity_House1_EventScript_BerryRipe
	msgbox NormalCity_House1_Text_NoBerryReady
	release
	end

NormalCity_House1_EventScript_BerryRipe::
	msgbox NormalCity_House1_Text_BerryRipe
	random 10
	copyvar VAR_0x8000, VAR_RESULT 
	addvar VAR_0x8000, ITEM_CHERI_BERRY
	setvar VAR_0x8001, 1
	
	callstd STD_OBTAIN_ITEM
	goto_if_eq VAR_RESULT, FALSE, NormalCity_House1_EventScript_BerryPouchFull
	setvar VAR_TEMP_0, 0
	release
	end

NormalCity_House1_EventScript_BerryPouchFull::
	msgbox NormalCity_House1_Text_BerryPouchFull
	release
	end

NormalCity_House1_EventScript_Scientist::
	lock
	faceplayer
	msgbox NormalCity_House1_Text_QuizIntro, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	goto NormalCity_House1_EventScript_QuizLoop
	end

NormalCity_House1_EventScript_QuizLoop::
	goto_if_ge VAR_TEMP_2, 3, NormalCity_House1_EventScript_QuizResults
	random NUM_SPECIES_NORMAL_POKEMON
	addvar VAR_RESULT, 1
	copyvar VAR_TEMP_3, VAR_RESULT @ var 3 has the first mon number (added 1 because random is 0 based)
	random 2 @ select the path (answer will be true or false)
	goto_if_eq VAR_RESULT, 0, NormalCity_House1_EventScript_QuizClaimTrue
	goto NormalCity_House1_EventScript_QuizPickB

NormalCity_House1_EventScript_QuizPickB::
	random NUM_SPECIES_NORMAL_POKEMON
	addvar VAR_RESULT, 1
	copyvar VAR_TEMP_4, VAR_RESULT
	goto_if_eq VAR_TEMP_4, VAR_TEMP_3, NormalCity_House1_EventScript_QuizPickB
	goto NormalCity_House1_EventScript_QuizShow

NormalCity_House1_EventScript_QuizClaimTrue::
	copyvar VAR_TEMP_4, VAR_TEMP_3

NormalCity_House1_EventScript_QuizShow::
	copyvar VAR_0x8005, VAR_TEMP_3
	special BufferPokedexDescription
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	bufferspeciesname STR_VAR_1, VAR_TEMP_4
	msgbox NormalCity_House1_Text_QuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_TEMP_4, VAR_TEMP_3, NormalCity_House1_EventScript_QuizCheckTrue
	goto NormalCity_House1_EventScript_QuizCheckFalse

NormalCity_House1_EventScript_QuizCheckTrue::
	goto_if_eq VAR_RESULT, YES, NormalCity_House1_EventScript_QuizCorrect
	goto NormalCity_House1_EventScript_QuizWrong

NormalCity_House1_EventScript_QuizCheckFalse::
	goto_if_eq VAR_RESULT, NO, NormalCity_House1_EventScript_QuizCorrect
	goto NormalCity_House1_EventScript_QuizWrong

NormalCity_House1_EventScript_QuizCorrect::
	addvar VAR_TEMP_1, 1
	msgbox NormalCity_House1_Text_QuizCorrect
	addvar VAR_TEMP_2, 1
	goto NormalCity_House1_EventScript_QuizLoop
	end

NormalCity_House1_EventScript_QuizWrong::
	msgbox NormalCity_House1_Text_QuizWrong
	addvar VAR_TEMP_2, 1
	goto NormalCity_House1_EventScript_QuizLoop
	end

NormalCity_House1_EventScript_QuizResults::
	goto_if_ge VAR_TEMP_1, 2, NormalCity_House1_EventScript_QuizWin
	msgbox NormalCity_House1_Text_QuizLose
	release
	end

NormalCity_House1_EventScript_QuizWin::
	giveitem ITEM_RARE_CANDY, 5
	msgbox NormalCity_House1_Text_QuizWin
	release
	end

NormalCity_House1_EventScript_ProjGreen_Sign::
	lock
	faceplayer
	msgbox NormalCity_House1_Text_Proj_Green, MSGBOX_SIGN
	release
	end

NormalCity_House1_EventScript_Incident_Sign::
	lock
	faceplayer
	msgbox NormalCity_House1_Text_Incident, MSGBOX_SIGN
	release
	end

NormalCity_House1_EventScript_SubjectX_Sign::
	lock
	faceplayer
	msgbox NormalCity_House1_Text_SubjectX, MSGBOX_SIGN
	release
	end

NormalCity_House1_EventScript_AbilitySwapper::
	lock
	faceplayer
	msgbox NormalCity_House1_Text_AbilitySwapperIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NormalCity_House1_EventScript_AbilitySwapperBye
	msgbox NormalCity_House1_Text_AbilitySwapperChooseMon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, NormalCity_House1_EventScript_AbilitySwapperBye
	specialvar VAR_RESULT, IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, NormalCity_House1_EventScript_AbilitySwapperEgg
	specialvar VAR_RESULT, SwapSelectedMonAbility
	goto_if_eq VAR_RESULT, 1, NormalCity_House1_EventScript_AbilitySwapperOneAbility
	msgbox NormalCity_House1_Text_AbilitySwapperDone
	goto NormalCity_House1_EventScript_AbilitySwapperBye
	end

NormalCity_House1_EventScript_AbilitySwapperOneAbility::
	msgbox NormalCity_House1_Text_AbilitySwapperOneAbility
	release
	end

NormalCity_House1_EventScript_AbilitySwapperEgg::
	msgbox NormalCity_House1_Text_AbilitySwapperEgg
	release
	end

NormalCity_House1_EventScript_AbilitySwapperBye::
	release
	end
