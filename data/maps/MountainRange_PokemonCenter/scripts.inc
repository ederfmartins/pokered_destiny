MountainRange_PokemonCenter_MapScripts::
	.byte 0

MountainRange_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
