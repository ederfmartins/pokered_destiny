City12_House1_MapScripts::
	.byte 0

City12_House1_EventScript_MoveRelearner::
    lock
    faceplayer
    msgbox City12_House1_Text_Intro, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, City12_House1_EventScript_Declined
    msgbox City12_House1_Text_WhichMon
    special SelectMoveTutorMon
    waitstate
    goto_if_ge VAR_0x8004, PARTY_SIZE, City12_House1_EventScript_End
    special IsSelectedMonEgg
    goto_if_eq VAR_RESULT, TRUE, City12_House1_EventScript_Egg
    goto_if_eq VAR_0x8005, 0, City12_House1_EventScript_NoMoves
    special DisplayMoveTutorMenu
    waitstate
    goto_if_eq VAR_0x8004, 0, City12_House1_EventScript_End
    msgbox City12_House1_Text_Done, MSGBOX_NPC
    release
    end

City12_House1_EventScript_Declined::
    msgbox City12_House1_Text_Declined
    release
    end

City12_House1_EventScript_Egg::
    msgbox City12_House1_Text_Egg
    release
    end

City12_House1_EventScript_NoMoves::
    msgbox City12_House1_Text_NoMoves
    release
    end

City12_House1_EventScript_End::
    release
    end
