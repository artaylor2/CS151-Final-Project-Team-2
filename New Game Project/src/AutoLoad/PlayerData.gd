extends Node

signal monster_tick
var forest: = []
var fire: = []
var rock: = []
var ice: = []
var ocean: = []
var cave: = []

# Level file name for spawn button to transition to correct scene
var levels : = ["res://src/Levels/ForestLevel.tscn", "res://src/Levels/FireLevel.tscn", "res://src/Levels/RockLevel.tscn",
				"res://src/Levels/IceLevel.tscn", "res://src/Levels/OceanLevel.tscn", "res://src/Levels/GhostLevel.tscn"]

# Array to store all of the monsters with their data
var monster_array = [] setget set_monster

func set_monster(monster: MonsterBase) -> void:
	monster_array.push_back(monster)
	for x in monster_array:
		print(x.getName())
	

