#ifndef GUARD_CONSTANTS_BATTLE_AI_H
#define GUARD_CONSTANTS_BATTLE_AI_H

// battlers
#define AI_TARGET 0
#define AI_USER 1
#define AI_TARGET_PARTNER 2
#define AI_USER_PARTNER 3

// get_type command
#define AI_TYPE1_TARGET 0
#define AI_TYPE1_USER 1
#define AI_TYPE2_TARGET 2
#define AI_TYPE2_USER 3
#define AI_TYPE_MOVE 4

// type effectiveness
#define AI_EFFECTIVENESS_x4     160
#define AI_EFFECTIVENESS_x2     80
#define AI_EFFECTIVENESS_x1     40
#define AI_EFFECTIVENESS_x0_5   20
#define AI_EFFECTIVENESS_x0_25  10
#define AI_EFFECTIVENESS_x0     0

// ai weather
#define AI_WEATHER_SUN       0
#define AI_WEATHER_RAIN      1
#define AI_WEATHER_SANDSTORM 2
#define AI_WEATHER_HAIL      3

// get_how_powerful_move_is
#define MOVE_POWER_DISCOURAGED  0
#define MOVE_NOT_MOST_POWERFUL  1
#define MOVE_MOST_POWERFUL      2

// script's table id to bit
/**
 * With this flag the AI ​​will be able to check if an attack is not going to be effective (a water type attack against a pokemon with water absorption, 
 * or an earthquake against a flying pokemon, etc). 
 * In addition, it will also give a little more priority to the attacks that are more effective (x2/x4).
*/
#define AI_SCRIPT_CHECK_BAD_MOVE (1 << 0)
/**
 * It is probably the most important flag of AI. It checks a lot of things, and practically any AI that we want to be decent must have this flag activated.
 * Check that an attack that causes a status change is not launched on a Pokémon that is already suffering one, 
 * if the conditions to use some movements are met (nightmare, snore...), 
 * if we increase the evasion a lot it will try to use an attack with Infinite precision... really, it checks a lot of things.
*/
#define AI_SCRIPT_CHECK_VIABILITY (1 << 1)
/**
 * If an attack is going to weaken the enemy Pokémon in all cases, it will use it. 
 * It also gives priority to the use of attacks with <high ​​priority> if they can weaken the opponent.
*/
#define AI_SCRIPT_TRY_TO_FAINT (1 << 2)
/**
 * When this flag is activated, during the first turn priority will be given to status attacks that modify statistics, reflection type walls, etc.
 * Here is the list of attacks that are given priority:
 * EFFECT_ATTACK_UP, EFFECT_DEFENSE_UP, EFFECT_SPEED_UP, EFFECT_SPECIAL_ATTACK_UP, EFFECT_SPECIAL_DEFENSE_UP, EFFECT_ACCURACY_UP, EFFECT_EVASION_UP, 
 * EFFECT_ATTACK_DOWN, EFFECT_DEFENSE_DOWN, EFFECT_SPEED_DOWN, EFFECT_SPECIAL_ATTACK_DOWN, EFFECT_SPECIAL_DEFENSE_DOWN, EFFECT_ACCURACY_DOWN, 
 * EFFECT_EVASION_DOWN, EFFECT_CONVERSION, EFFECT_LIGHT_SCREEN, EFFECT_SPECIAL_DEFENSE_UP_2, EFFECT_FOCUS_ENERGY, EFFECT_CONFUSE, EFFECT_ATTACK_UP_2, 
 * EFFECT_DEFENSE_UP_2, EFFECT_SPEED_UP_2, EFFECT_SPECIAL_ATTACK_UP_2, EFFECT_SPECIAL_DEFENSE_UP_2, EFFECT_ACCURACY_UP_2, EFFECT_EVASION_UP_2, 
 * EFFECT_ATTACK_DOWN_2, EFFECT_DEFENSE_DOWN_2, EFFECT_SPEED_DOWN_2, EFFECT_SPECIAL_ATTACK_DOWN_2, EFFECT_SPECIAL_DEFENSE_DOWN_2, EFFECT_ACCURACY_DOWN_2, 
 * EFFECT_EVASION_DOWN_2, EFFECT_REFLECT, EFFECT_POISON, EFFECT_PARALYZE, EFFECT_SUBSTITUTE, EFFECT_LEECH_SEED, EFFECT_MINIMIZE, EFFECT_CURSE, 
 * EFFECT_SWAGGER, EFFECT_CAMOUFLAGE, EFFECT_YAWN, EFFECT_DEFENSE_CURL, EFFECT_TORMENT, EFFECT_FLATTER, EFFECT_WILL_O_WISP, EFFECT_INGRAIN, 
 * EFFECT_IMPRISON, EFFECT_TEETER_DANCE, EFFECT_TICKLE, EFFECT_COSMIC_POWER, EFFECT_BULK_UP, EFFECT_CALM_MIND, EFFECT_CAMOUFLAGE
*/
#define AI_SCRIPT_SETUP_FIRST_TURN (1 << 3)
/**
 * This flag favors the use of 'risky' attacks such as 1 hit KO, self-destruct, metronome, attacks with a high critical chance. Wow, in general it 
 * favors that the AI ​​tries to use risky things (high risk - high reward). Here is a list of attack effects that are favored by this flag:
 * EFFECT_SLEEP, EFFECT_EXPLOSION, EFFECT_MIRROR_MOVE, EFFECT_OHKO, EFFECT_HIGH_CRITICAL, EFFECT_CONFUSE, EFFECT_METRONOME, 
 * EFFECT_PSYWAVE, EFFECT_COUNTER, EFFECT_DESTINY_BOND, EFFECT_SWAGGER, EFFECT_ATTRACT, EFFECT_PRESENT, EFFECT_ALL_STATS_UP_HIT, EFFECT_BELLY_DRUM, 
 * EFFECT_MIRROR_COAT, EFFECT_FOCUS_PUNCH, EFFECT_REVENGE, EFFECT_TEETER_DANCE
*/
#define AI_SCRIPT_RISKY (1 << 4)
/**
 * Give priority to the strongest attacks.
*/
#define AI_SCRIPT_PREFER_STRONGEST_MOVE (1 << 5)
/**
 * Give priority to the use of relay (BatonPass).
*/
#define AI_SCRIPT_PREFER_BATON_PASS (1 << 6)
#define AI_SCRIPT_DOUBLE_BATTLE (1 << 7)
/**
 * This flag makes the AI ​​take into account the amount of HP of the Pokémon in combat, fundamentally its usefulness lies in choosing a target to 
 * attack in double battles. It also favors the use of moves such as recovery or explosion when the pokemon has low HP and disfavors it when it has a lot 
 * of HP. (to summarize it all a bit).
*/
#define AI_SCRIPT_HP_AWARE (1 << 8)
#define AI_SCRIPT_UNKNOWN (1 << 9)
// 10 - 28 are not used - not anymore :P
// thus new AI strategies take advantage of that flags
/**
 * This flag removes bad moves from consideration and also apply AI_SCRIPT_CHECK_BAD_MOVE.
 * This is the list of bad moves:
 * MOVE_GROWL, MOVE_ROAR, MOVE_LEER, MOVE_SAND_ATTACK, MOVE_TAIL_WHIP, MOVE_GROWTH, MOVE_STRING_SHOT, MOVE_AGILITY, MOVE_HARDEN, MOVE_DEFENSE_CURL, 
 * MOVE_FOCUS_ENERGY, MOVE_SCARY_FACE, MOVE_SWEET_SCENT, MOVE_SCREECH, MOVE_SNORE, MOVE_UPROAR, MOVE_METAL_SOUND, MOVE_GRASS_WHISTLE, MOVE_CHARGE, 
 */
#define AI_SCRIPT_AVOID_INEFFICIENT_MOVE (1 << 10)

#define AI_SCRIPT_ROAMING (1 << 29)
#define AI_SCRIPT_SAFARI (1 << 30)
#define AI_SCRIPT_FIRST_BATTLE (1 << 31)

// AI Strategies are combinations of of AI_SCRIPT_ flags ain to allow a strategy for the trainer.
#define AI_STRATEGY_OK_TRAINER (AI_SCRIPT_AVOID_INEFFICIENT_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_HP_AWARE | AI_SCRIPT_TRY_TO_FAINT) 

#endif // GUARD_CONSTANTS_BATTLE_AI_H
