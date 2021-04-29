extends Node

var monster_array = [] setget set_monster

func set_monster(monster: Actor) -> void:
	monster_array.push_back(monster)
	for x in monster_array:
		print(x.happiness)
