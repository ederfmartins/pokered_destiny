Dark_city_yaz_gym_MapScripts::
	.byte 0

Dark_city_yaz_gym_man1::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_YAZ_MAN1, 0, Dark_city_yaz_gym_man1_start, Dark_city_yaz_gym_man1_end
	closemessage
	releaseall
	end


Dark_city_yaz_gym_man2::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_YAZ_MAN2, 0, Dark_city_yaz_gym_man2_start, Dark_city_yaz_gym_man2_end
	closemessage
	releaseall
	end


Dark_city_yaz_gym_leader::
	lock
	faceplayer
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_YAZ_LEADER, 0, Dark_city_yaz_gym_leader_start, Dark_city_yaz_gym_leader_end
	closemessage
	releaseall
	end


Dark_city_yaz_gym_man1_start::
	.string "This is my martial style!$"

Dark_city_yaz_gym_man1_end::
	.string "Our boss will have a superior fight style!$"

Dark_city_yaz_gym_man2_start::
	.string "Yas! Yas! Yas!$"

Dark_city_yaz_gym_man2_end::
	.string "Yaz forever!$"

Dark_city_yaz_gym_leader_start::
	.string "This gym is only for the strongest.$"

Dark_city_yaz_gym_leader_end::
	.string "Yas will never surrender!$"
