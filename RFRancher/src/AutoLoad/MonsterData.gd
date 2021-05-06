extends Node

var num_monsters = 0
var global_index = 0

var file_names = [] setget set_codex
# Level file name for spawn button to transition to correct scene
var levels : = ["res://src/Levels/GhostLevel.tscn", "res://src/Levels/FireLevel.tscn", "res://src/Levels/WaterLevel.tscn",
				"res://src/Levels/ForestLevel.tscn", "res://src/Levels/RockLevel.tscn", "res://src/Levels/IceLevel.tscn"]

# Arrays that hold the various types strings for the monsters
var types : = ["Ghost", "Fire", "Water", "Forest", "Rock", "Ice"]
var types_sprite : = ["res://assets/menus/Ghost_Type.png", "res://assets/menus/Fire_Type.png", "res://assets/menus/Water_Type.png",
					  "res://assets/menus/Forest_Type.png", "res://assets/menus/Rock_Type.png", "res://assets/menus/Ice_Type.png"]

# Array to store all of the monsters with their data
var monster_array = [] setget set_monster

# Push back generated monster into global monster array
func set_monster(monster) -> void:
	monster_array.push_back(monster)

# Push back generated file name into codex array
func set_codex(file: String) -> void:
	file_names.push_back(file)

