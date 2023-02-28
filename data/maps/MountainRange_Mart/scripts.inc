.set LOCALID_CLERK, 1

MountainRange_Mart_MapScripts::
	.byte 0

MountainRange_Mart_EventScript_HideQuestionnaire::
	setmetatile 1, 3, METATILE_Mart_CounterMid_Top, 1
	setmetatile 1, 4, METATILE_Mart_CounterMid_Bottom, 1
	end


MountainRange_Mart_EventScript_Clerk::
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart MountainRange_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
MountainRange_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE
	release
	end

MountainRange_Mart_EventScript_Woman::
	msgbox MountainRange_Mart_Text_ShopDoesGoodBusinessInAntidotes, MSGBOX_NPC
	end

MountainRange_Mart_EventScript_Youngster::
	msgbox MountainRange_Mart_Text_GotToBuySomePotions, MSGBOX_NPC
	end
