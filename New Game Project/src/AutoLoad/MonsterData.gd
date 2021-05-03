extends Node

var num_monsters = 0

var file_names = [] setget set_codex
# Level file name for spawn button to transition to correct scene
var levels : = ["res://src/Levels/ForestLevel.tscn", "res://src/Levels/FireLevel.tscn", "res://src/Levels/RockLevel.tscn",
				"res://src/Levels/IceLevel.tscn", "res://src/Levels/OceanLevel.tscn", "res://src/Levels/GhostLevel.tscn"]

# Array to store all of the monsters with their data
var monster_array = [] setget set_monster

func set_monster(monster) -> void:
	monster_array.push_back(monster)

func set_codex(file: String) -> void:
	file_names.push_back(file)

