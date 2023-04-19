import argparse
import json
from typing import Dict, List, Any
import re
import pyparsing


def parse_wild_encounters(file_path: str) -> List[Dict[str, Any]]:
    wild_encounters = json.load(open(file_path))
    if "wild_encounter_groups" not in wild_encounters:
        raise ValueError("Invalid wild encounters file. It should contain wild_encounter_groups field.")
    if "encounters" not in wild_encounters["wild_encounter_groups"][0]:
        raise ValueError("Invalid wild encounters file. It should contain encounters field.")
    return [
        parse_map_from_wild_encounters(map_desc)
        for map_desc in wild_encounters["wild_encounter_groups"][0]["encounters"]
        if "FireRed" in map_desc["base_label"]
    ]

def parse_map_from_wild_encounters(map_desc: Dict[str, Any]):
    data = {
        "map": map_desc["map"],
    }
    for land_type in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
        data[land_type] = map_desc.get(land_type, {}).get("mons", [])
        data[land_type] = [mon["species"] for mon in data[land_type]]
        data[land_type] = list(set(data[land_type]))
    return data


def generate_pokedex_markdown(wild_encounters: List[Dict[str, Any]], base_stats: Dict[str, Any]) -> str:
    text = ["# POKEMON Stats, Locations & Move sets", "##Locations"]
    for location in wild_encounters:
        if len(location) > 1:
            text.append(f"### {location['map']}")
            for land_type in location:
                if land_type != "map" and len(location[land_type]) > 0:
                    text.append(f"**{land_type}:** {', '.join(location[land_type])}")
    text.append("##Stats")
    for mon_name, mon_stats in base_stats.items():
        if len(mon_stats) == 0:
            continue
        text.append(f"### {mon_name}")
        text.append(f"**XP**: {mon_stats['expYield']} / {mon_stats['genderRatio']}")
        mon_table = []
        mon_table.append("|         |         |         |         |         |         |         |         |")
        mon_table.append("|---------|---------|---------|---------|---------|---------|---------|---------|")
        mon_table.append(f"| **type1** | {mon_stats['type1']} | **type2** | {mon_stats['type2']} | **catchRate** | {mon_stats['catchRate']} | **safariZoneFleeRate** | {mon_stats['safariZoneFleeRate']} |")
        mon_table.append(f"| **baseAttack** | {mon_stats['baseAttack']} | **baseSpAttack** | {mon_stats['baseSpAttack']} | **evYield_Attack** | {mon_stats['evYield_Attack']} | **evYield_SpAttack** | {mon_stats['evYield_SpAttack']} |")
        mon_table.append(f"| **baseDefense** | {mon_stats['baseDefense']} | **baseSpDefense** | {mon_stats['baseSpDefense']} | **evYield_Defense** | {mon_stats['evYield_Defense']} | **evYield_SpDefense** | {mon_stats['evYield_SpDefense']} |")
        mon_table.append(f"| **baseHP** | {mon_stats['baseHP']} | **baseSpeed** | {mon_stats['baseSpeed']} | **evYield_HP** | {mon_stats['evYield_HP']} | **evYield_SpDefense** | {mon_stats['evYield_SpDefense']} |")
        mon_table.append(f"| **eggGroup1** | {mon_stats['eggGroup1']} | **eggGroup2** | {mon_stats['eggGroup2']} | **eggCycles** | {mon_stats['eggCycles']} | **friendship** | {mon_stats['friendship']} |")
        mon_table.append(f"| **item1** | {mon_stats['item1']} | **item2** | {mon_stats['item2']} | **abilities** | {mon_stats['abilities']} | **growthRate** | {mon_stats['growthRate']} |")
        text.append("\n".join(mon_table))
        
    return "\n\n".join(text)

def parse_base_stats(file_path: str) -> Dict[str, Any]:
    raw_base_stats = open(file_path).readlines()#[38:]
    raw_base_stats = " ".join(raw_base_stats)
    raw_base_stats = re.sub(r"\s+", " ", raw_base_stats)
    pokemon_stats_pattern = re.compile("\[[a-zA-Z_]+\] = \{.*},")
    text = re.findall(pokemon_stats_pattern, raw_base_stats)[0]
    return StatsParser().parse(text)

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
        


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="""
    Generate markdown file containing the location of each POKEMONs in your hack as well has all stats from those
    POKEMONS.
    This tool assumes you are using firered or leafgreen source code. That means you need to have a file named 
    wild_encounters.json in your hack, as well as, some c files containing the pokemon status.
    """)

    parser.add_argument("--wild_encounters", default="src/data/wild_encounters.json", required=True)
    parser.add_argument("--base_stats", default="src/data/pokemon/base_stats.h", required=True)
    args = parser.parse_args()

    wild_encounters = parse_wild_encounters(args.wild_encounters)
    base_stats = parse_base_stats(args.base_stats)
    print(generate_pokedex_markdown(wild_encounters=wild_encounters, base_stats=base_stats))

