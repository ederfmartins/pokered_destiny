.equ LOCALID_KARATE_MASTER, 5

SaffronCity_Dojo_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, SaffronCity_Dojo_BadgeEvent
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end

SaffronCity_Dojo_BadgeEvent::
	goto_if_unset FLAG_BADGE10_GET, SaffronCity_Dojo_BadgeEvent_2
SaffronCity_Dojo_BadgeEvent_1:
	setflag FLAG_TEMP_1
	return

SaffronCity_Dojo_BadgeEvent_2:
	goto_if_set TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_BadgeEvent_4
	goto SaffronCity_Dojo_BadgeEvent_1

SaffronCity_Dojo_BadgeEvent_4:
	clearflag FLAG_TEMP_1
	return


SaffronCity_Dojo_Bruno::
	lock
	faceplayer
	goto_if_set FLAG_BADGE10_GET, SaffronCity_Dojo_Bruno_2
	goto_if_set TRAINER_FLAGS_START + TRAINER_YAZ_LEADER, SaffronCity_Dojo_Bruno_5
	msgbox SaffronCity_Dojo_Bruno_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_Bruno_8
	msgbox SaffronCity_Dojo_Bruno_Text_5
SaffronCity_Dojo_Bruno_7:
	release
	end

SaffronCity_Dojo_Bruno_2:
	msgbox SaffronCity_Dojo_Bruno_Text_0
	release
	end

SaffronCity_Dojo_Bruno_5:
	trainerbattle_enforce_set TRAINER_BRUNO_GYMLEADER, SaffronCity_Dojo_Bruno_Text_1, SaffronCity_Dojo_Bruno_Text_2, SaffronCity_Dojo_afterbattle
	release
	end

SaffronCity_Dojo_Bruno_8:
	msgbox SaffronCity_Dojo_Bruno_Text_4
	goto SaffronCity_Dojo_Bruno_7


SaffronCity_Dojo_afterbattle::
	setflag FLAG_BADGE10_GET
	giveitem ITEM_TM08
	msgbox SaffronCity_Dojo_afterbattle_Text_0
	msgbox SaffronCity_Dojo_Text_ExplainTM
	release
	end


SaffronCity_Dojo_Bruno_Text_0:
	.string "I will see you in the leagues.$"

SaffronCity_Dojo_Bruno_Text_1:
	.string "I see your value.\n"
	.string "Be part of the rebirth of our Gym!$"

SaffronCity_Dojo_Bruno_Text_2:
	.string "Tank you! Take this to prove your valor.$"

SaffronCity_Dojo_Bruno_Text_3:
	.string "The two Pseudo Gyms of DARK CITY are\n"
	.string "at war.\n"
	.string "Do you, help me solve this problem?$"

SaffronCity_Dojo_Bruno_Text_4:
	.string "OK. I will leave it to you.$"

SaffronCity_Dojo_Bruno_Text_5:
	.string "You are not ready yet.$"

SaffronCity_Dojo_afterbattle_Text_0:
	.string "You got the FIGHTING VALOR BADGE$"

SaffronCity_Dojo_Text_ExplainTM:
	.string "TM08 contains BULK UP.\n"
	.string "It raises your ATTACK and DEFENSE\n"
	.string "stats during battle.$"
