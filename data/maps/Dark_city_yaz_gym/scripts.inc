Dark_city_yaz_gym_MapScripts::
	.byte 0

Dark_city_yaz_gym_man1::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_YAZ_MAN1, 0, Dark_city_yaz_gym_man1_start, Dark_city_yaz_gym_man1_end
	closemessage
	msgbox Dark_city_yaz_gym_man1_after
	releaseall
	end


Dark_city_yaz_gym_man2::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_YAZ_MAN2, 0, Dark_city_yaz_gym_man2_start, Dark_city_yaz_gym_man2_end
	closemessage
	msgbox Dark_city_yaz_gym_man2_after
	releaseall
	end


Dark_city_yaz_gym_leader::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE_ENFORCE_SET_MODE, TRAINER_YAZ_LEADER, 0, Dark_city_yaz_gym_leader_start, Dark_city_yaz_gym_leader_end
	closemessage
	msgbox Dark_city_yaz_gym_leader_after
	releaseall
	end


Dark_city_yaz_gym_man1_start::
	.string "This is my martial style!$"

Dark_city_yaz_gym_man1_end::
	.string "Our boss will have a superior fight style!$"

Dark_city_yaz_gym_man1_after::
	.string "I lost. I will behave better next time.$"

Dark_city_yaz_gym_man2_start::
	.string "Yas! Yas! Yas!$"

Dark_city_yaz_gym_man2_end::
	.string "Yaz forever!$"

Dark_city_yaz_gym_man2_after::
	.string "I lost. I will behave better from now on.$"

Dark_city_yaz_gym_leader_start::
	.string "This gym is only for the strongest.$"

Dark_city_yaz_gym_leader_end::
	.string "Yas will never surrender!$"

Dark_city_yaz_gym_leader_after::
	.string "I lost. I will behave better and train harder.$"
