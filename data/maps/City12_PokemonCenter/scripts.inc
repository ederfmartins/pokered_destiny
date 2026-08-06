City12_PokemonCenter_MapScripts::
	.byte 0

City12_PokemonCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
