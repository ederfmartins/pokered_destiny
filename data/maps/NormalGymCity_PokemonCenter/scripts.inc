NormalGymCity_PokemonCenter_MapScripts::
	.byte 0

NormalGymCity_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
