City12_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, City12_OnTransition
    .byte 0

City12_OnTransition:
    setworldmapflag FLAG_WORLD_MAP_DRAGONITE_ISLE
    end

City12_EventScript_Lance::
    lock
    faceplayer
    msgbox City12_Lance_Text_0, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq City12_Lance_Battle
    msgbox City12_Lance_Text_Declined
    release
    end

City12_Lance_Battle::
    trainerbattle_enforce_set TRAINER_LANCE_GYMLEADER, City12_Lance_Text_Intro, City12_Lance_Text_Defeat, City12_Lance_AfterBattle
    release
    end

City12_Lance_AfterBattle::
    setflag FLAG_BADGE15_GET
    msgbox City12_Lance_Text_PostBattle
    release
    end

City12_EventScript_ReturnSign::
    lockall
    msgbox City12_Text_ReturnSign, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq City12_ReturnSign_Warp
    msgbox City12_Text_ReturnSign_Declined
    releaseall
    end

City12_ReturnSign_Warp:
    msgbox City12_Text_ReturnSign_Warp
    warp MAP_SSANNE_EXTERIOR, 58, 4
    waitstate
    releaseall
    end

