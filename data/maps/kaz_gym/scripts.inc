kaz_gym_MapScripts::
	.byte 0

kaz_gym_woman::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_KAZ_LADY, 0, kaz_gym_woman_start, kaz_gym_woman_end
	closemessage
	releaseall
	end


kaz_gym_man1::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_KAZ_MAN1, 0, kaz_gym_man1_start, kaz_gym_man1_end
	closemessage
	releaseall
	end


kaz_gym_man2::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_KAZ_MAN2, 0, kaz_gym_man2_start, kaz_gym_man2_end
	closemessage
	releaseall
	end


kaz_gym_leader::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_KAZ_LEADER, 0, kaz_gym_leader_start, kaz_gym_leader_end
	closemessage
	releaseall
	end


kaz_gym_woman_start::
	.string "It is time to teach you how lick the floor!$"

kaz_gym_woman_end::
	.string "Fuck you!$"

kaz_gym_man1_start::
	.string "It is show time!$"

kaz_gym_man1_end::
	.string "Our boss will teach you a lesson!$"

kaz_gym_man2_start::
	.string "Kaz! Kaz! Kaz!$"

kaz_gym_man2_end::
	.string "Kaz forever!$"

kaz_gym_leader_start::
	.string "This is the power of our style.$"

kaz_gym_leader_end::
	.string "Kaz forever!$"
