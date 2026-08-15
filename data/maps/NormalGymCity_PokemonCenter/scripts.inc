NormalGymCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NormalGymCity_PokemonCenter_OnTransition
	.byte 0

NormalGymCity_PokemonCenter_OnTransition::
	setrespawn SPAWN_NORMAL_GYM_CITY
	end

NormalGymCity_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
