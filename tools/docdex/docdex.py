import argparse
import json
from typing import Dict, List, Any, Set
import re
import pyparsing


class StatsParser:
    name = pyparsing.Word(pyparsing.alphanums + "_")
    abilities = pyparsing.Char("{") + name + pyparsing.Char(",") + name + pyparsing.Char("}")
    func = name + pyparsing.Optional(pyparsing.Char("(") + pyparsing.Word(pyparsing.nums + ".") + pyparsing.Char(")"))
    attr_val = func | pyparsing.Word(pyparsing.nums + ".") | abilities
    attr = pyparsing.Char(".") + name + pyparsing.Char("=") + attr_val + pyparsing.Char(",")
    attr_list = pyparsing.OneOrMore(attr)
    attr_void = pyparsing.Word("0")
    attr_list_or_void = attr_list | attr_void
    attr_dict = pyparsing.Char("{") + attr_list_or_void + pyparsing.Char("}")
    mon_def = pyparsing.Char("[") + name + pyparsing.Char("]") + pyparsing.Char("=") + attr_dict + pyparsing.Char(",")
    mon_dict = pyparsing.OneOrMore(mon_def)
    comment = pyparsing.Char("/") + pyparsing.Char("*") + mon_dict + pyparsing.Char("*") + pyparsing.Char("/")
    base_stats = pyparsing.OneOrMore(mon_dict | comment)
    

    @name.setParseAction
    def emite_name(results: pyparsing.ParseResults):
        return results[0]
    
    @abilities.setParseAction
    def emite_abilities(results: pyparsing.ParseResults):
        return [results[1], results[3]]
    
    @func.setParseAction
    def emite_func(results: pyparsing.ParseResults):
        return "".join(results)
    
    @attr_val.setParseAction
    def emite_attr_val(results: pyparsing.ParseResults):
        return results[0]
    
    @attr_list.setParseAction
    def emite_attr_list(results: pyparsing.ParseResults):
        return results
    
    @attr.setParseAction
    def emite_attr(results: pyparsing.ParseResults):
        return [results[1], results[3]]
    
    @attr_void.setParseAction
    def emite_attr_void(results: pyparsing.ParseResults):
        return []
    
    @attr_list_or_void.setParseAction
    def emite_attr_list_or_void(results: pyparsing.ParseResults):
        return results
    
    @attr_dict.setParseAction
    def emite_attr_dict(results: pyparsing.ParseResults):
        return {
            results[idx]: results[idx + 1]
            for idx in range(1, len(results) - 1, 2)
        }
    
    @mon_def.setParseAction
    def emite_mon_def(results: pyparsing.ParseResults):
        return {results[1]: results[4]}
    
    @mon_dict.setParseAction
    def emite_mon_dict(results: pyparsing.ParseResults):
        all_mons = {}
        for mon in results:
            for k, v in mon.items():
                all_mons[k] = v
        return all_mons
    
    @comment.setParseAction
    def emite_comment(results: pyparsing.ParseResults):
        return {}
    
    @base_stats.setParseAction
    def emite_base_stats(results: pyparsing.ParseResults):
        all_mons = {}
        for mon in results:
            for k, v in mon.items():
                all_mons[k] = v
        return all_mons
    
    def parse(self, text):
        return self.base_stats.parseString(text)[0]


class Learnsets:
    static = pyparsing.Keyword("static")
    const = pyparsing.Keyword("const")
    u16 = pyparsing.Keyword("u16")
    move_word = pyparsing.Keyword("LEVEL_UP_MOVE")
    move_end = pyparsing.Keyword("LEVEL_UP_END")
    name = pyparsing.Word(pyparsing.alphanums + "_")
    comment_line = pyparsing.Char("#") + pyparsing.Regex(".*") + pyparsing.lineEnd()
    move = move_word + pyparsing.Char("(") + name + pyparsing.Char(",") + name + pyparsing.Char(")") + pyparsing.Char(",")
    move_list = pyparsing.OneOrMore(move | comment_line)
    learnset = static + const + u16 + name + pyparsing.Char("[") + pyparsing.Char("]") + pyparsing.Char("=") + pyparsing.Char("{") + move_list + move_end + pyparsing.Char("}") + pyparsing.Char(";")
    learnset_list = pyparsing.OneOrMore(learnset)

    @name.setParseAction
    def emite_name(results: pyparsing.ParseResults):
        return results[0]

    @move.setParseAction
    def emite_move(results: pyparsing.ParseResults):
        move_name = results[4].replace("MOVE_", "").replace("_", " ").capitalize()
        return [results[2], move_name]
    
    @move_list.setParseAction
    def emite_move_list(results: pyparsing.ParseResults):
        return {
            results[idx]: results[idx + 1]
            for idx in range(0, len(results) - 1, 2)
        }
    
    @learnset.setParseAction
    def emite_learnset(results: pyparsing.ParseResults):
        # Change sBulbasaurLevelUpLearnset to SPECIES_BULBASAUR
        mon_name = "SPECIES_" + results[3].replace("LevelUpLearnset", "")[1:].upper()
        
        return {mon_name: results[8]}
    
    @learnset_list.setParseAction
    def emite_learnset_list(results: pyparsing.ParseResults):
        all_mons = {}
        for mon in results:
            for k, v in mon.items():
                all_mons[k] = v
        return all_mons
    
    @comment_line.setParseAction
    def emite_comment(results: pyparsing.ParseResults):
        return []
    
    def __init__(self, file_path: str):
        self.raw_learnsets = "".join(open(file_path).readlines()[2:])
    
    def parse(self) -> Dict[str, Dict[str, str]]:
        return self.learnset_list.parseString(self.raw_learnsets)[0]


class TmHmLearnsets:
    name = pyparsing.Word(pyparsing.alphanums + "_")
    tmhm = pyparsing.Keyword("TMHM")
    tmhm_def = tmhm + pyparsing.Char("(") + name + pyparsing.Char(")")
    tmhm_list = pyparsing.Char("0") | pyparsing.infixNotation(tmhm_def, [("|", 2, pyparsing.opAssoc.LEFT)])
    tmhm_learnset = pyparsing.Keyword("TMHM_LEARNSET")
    mon_def = pyparsing.Char("[") + name + pyparsing.Char("]") + pyparsing.Char("=") + tmhm_learnset + pyparsing.Char("(") + tmhm_list + pyparsing.Char(")") + pyparsing.Char(",")
    mon_dict = pyparsing.OneOrMore(mon_def)
    comment = pyparsing.Char("/") + pyparsing.Char("*") + mon_dict + pyparsing.Char("*") + pyparsing.Char("/")
    base_stats = pyparsing.OneOrMore(mon_dict | comment)

    @name.setParseAction
    def emite_name(results: pyparsing.ParseResults):
        return results[0]

    @tmhm_def.setParseAction
    def emite_tmhm_def(results: pyparsing.ParseResults):
        move_name = results[2].replace("_", " ").capitalize()
        return [move_name]
    
    @tmhm_list.setParseAction
    def emite_tmhm_list(results: pyparsing.ParseResults):
        return [[move for move in results[0] if move not in ["|", "0"]]]
    
    @mon_def.setParseAction
    def emite_mon_def(results: pyparsing.ParseResults):
        return {results[1]: results[6]}
    
    @mon_dict.setParseAction
    def emite_mon_dict(results: pyparsing.ParseResults):
        all_mons = {}
        for mon in results:
            for k, v in mon.items():
                all_mons[k] = v
        return all_mons
    
    @comment.setParseAction
    def emite_comment(results: pyparsing.ParseResults):
        return {}
    
    @base_stats.setParseAction
    def emite_base_stats(results: pyparsing.ParseResults):
        all_mons = {}
        for mon in results:
            for k, v in mon.items():
                all_mons[k] = v
        return all_mons
    
    def __init__(self, file_path: str):
        self.raw_learnsets = "".join(open(file_path).readlines()[9:])
    
    def parse(self) -> Dict[str, Dict[str, str]]:
        return self.base_stats.parseString(self.raw_learnsets)[0]


class WildEncounters:
    def __init__(self, file_path: str) -> None:
        self.wild_encounters = json.load(open(file_path))
        if "wild_encounter_groups" not in self.wild_encounters:
            raise ValueError("Invalid wild encounters file. It should contain wild_encounter_groups field.")
        if "encounters" not in self.wild_encounters["wild_encounter_groups"][0]:
            raise ValueError("Invalid wild encounters file. It should contain encounters field.")
        
    def get_pokemon_by_map(self) -> Dict[str, Dict[str, Any]]:
        ret = {}
        for map_desc in self.wild_encounters["wild_encounter_groups"][0]["encounters"]:
            if "FireRed" in map_desc["base_label"]:
                the_map = self.parse_map_from_wild_encounters(map_desc)
                ret[the_map["map"]] = the_map
        return ret

    def parse_map_from_wild_encounters(self, map_desc: Dict[str, Any]):
        data = {
            "map": map_desc["map"],
        }
        for land_type in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
            data[land_type] = map_desc.get(land_type, {}).get("mons", [])
            data[land_type] = [mon["species"] for mon in data[land_type]]
            data[land_type] = list(set(data[land_type]))
        return data
    
    def get_map_by_pokemon(self) -> Dict[str, Set[str]]:
        pokemon_by_map = self.get_pokemon_by_map()
        pokemons = {}
        for map_name in pokemon_by_map:
            for land_type in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
                for pokemon in pokemon_by_map[map_name].get(land_type, []):
                    if pokemon not in pokemons:
                        pokemons[pokemon] = set()
                    pokemons[pokemon].add(map_name)
        return pokemons



def generate_pokedex_markdown(wild_encounters: WildEncounters, base_stats: Dict[str, Any], learnsets: Learnsets, tmhm_learnsets: TmHmLearnsets) -> str:
    text = ["# POKEMON Stats, Locations & Move sets"]
    map_by_pokemon = wild_encounters.get_map_by_pokemon()
    for mon_name, mon_stats in base_stats.items():
        if len(mon_stats) == 0:
            continue
        name = mon_name.replace("SPECIES_", "")
        text.append(f"### {name}")
        text.append(f"![{name}](graphics/pokemon/{name.lower()}/front.png)")
        text.append(f"**XP**: {mon_stats['expYield']} / {mon_stats['genderRatio']}")
        mon_table = build_mon_stats_table(mon_stats)
        text.append("\n".join(mon_table))
        text.extend(build_mon_location(mon_name, map_by_pokemon))
        mon_learnset = build_mon_mon_learnset_table(mon_name, learnsets)
        text.append("\n".join(mon_learnset))
        mon_learnset = build_mon_mon_tmhm_table(mon_name, tmhm_learnsets)
        text.append("\n".join(mon_learnset))
        
    return "\n\n".join(text)


def build_mon_stats_table(mon_stats) -> List[str]:
    mon_table = []
    mon_table.append("|         |         |         |         |         |         |         |         |")
    mon_table.append("|---------|---------|---------|---------|---------|---------|---------|---------|")
    mon_table.append(f"| **type1** | {mon_stats['type1']} | **type2** | {mon_stats['type2']} | **catchRate** | {mon_stats['catchRate']} | **safariZoneFleeRate** | {mon_stats['safariZoneFleeRate']} |")
    mon_table.append(f"| **baseAttack** | {mon_stats['baseAttack']} | **baseSpAttack** | {mon_stats['baseSpAttack']} | **evYield_Attack** | {mon_stats['evYield_Attack']} | **evYield_SpAttack** | {mon_stats['evYield_SpAttack']} |")
    mon_table.append(f"| **baseDefense** | {mon_stats['baseDefense']} | **baseSpDefense** | {mon_stats['baseSpDefense']} | **evYield_Defense** | {mon_stats['evYield_Defense']} | **evYield_SpDefense** | {mon_stats['evYield_SpDefense']} |")
    mon_table.append(f"| **baseHP** | {mon_stats['baseHP']} | **baseSpeed** | {mon_stats['baseSpeed']} | **evYield_HP** | {mon_stats['evYield_HP']} | **evYield_SpDefense** | {mon_stats['evYield_SpDefense']} |")
    mon_table.append(f"| **eggGroup1** | {mon_stats['eggGroup1']} | **eggGroup2** | {mon_stats['eggGroup2']} | **eggCycles** | {mon_stats['eggCycles']} | **friendship** | {mon_stats['friendship']} |")
    mon_table.append(f"| **item1** | {mon_stats['item1']} | **item2** | {mon_stats['item2']} | **abilities** | {mon_stats['abilities']} | **growthRate** | {mon_stats['growthRate']} |")
    return mon_table


def build_mon_location(mon_name, map_by_pokemon) -> List[str]:
    return [f"**Found at:** {', '.join(map_by_pokemon.get(mon_name, []))}"]


def build_mon_mon_learnset_table(mon_name, learnsets) -> List[str]:
    table = []
    if mon_name in learnsets:
        table.append("| Level | Move Name |")
        table.append("|---------|---------|")
        for level, move in learnsets[mon_name].items():
            table.append(f"| {level} | {move} |")
    return table


def build_mon_mon_tmhm_table(mon_name, learnsets) -> List[str]:
    table = []
    if mon_name in learnsets:
        table.append("| TM or HM |")
        table.append("|---------|")
        for move in learnsets[mon_name]:
            table.append(f"| {move} |")
    return table


def parse_base_stats(file_path: str) -> Dict[str, Any]:
    raw_base_stats = open(file_path).readlines()#[38:]
    raw_base_stats = " ".join(raw_base_stats)
    raw_base_stats = re.sub(r"\s+", " ", raw_base_stats)
    pokemon_stats_pattern = re.compile("\[[a-zA-Z_]+\] = \{.*},")
    text = re.findall(pokemon_stats_pattern, raw_base_stats)[0]
    return StatsParser().parse(text)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="""
    Generate markdown file containing the location of each POKEMONs in your hack as well has all stats from those
    POKEMONS.
    This tool assumes you are using firered or leafgreen source code. That means you need to have a file named 
    wild_encounters.json in your hack, as well as, some c files containing the pokemon status.
    """)

    parser.add_argument("--wild_encounters", default="src/data/wild_encounters.json", required=True)
    parser.add_argument("--base_stats", default="src/data/pokemon/base_stats.h", required=True)
    parser.add_argument("--learnsets", default="src/data/pokemon/level_up_learnsets.h", required=True)
    parser.add_argument("--tmhm", default="src/data/pokemon/tmhm_learnsets.h", required=True)
    args = parser.parse_args()

    wild_encounters = WildEncounters(args.wild_encounters)
    learnsets = Learnsets(args.learnsets).parse()
    tmhm_learnsets = TmHmLearnsets(args.tmhm).parse()
    base_stats = parse_base_stats(args.base_stats)
    print(generate_pokedex_markdown(
        wild_encounters=wild_encounters, 
        base_stats=base_stats, 
        learnsets=learnsets, 
        tmhm_learnsets=tmhm_learnsets
    ))

