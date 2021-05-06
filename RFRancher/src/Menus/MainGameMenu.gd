extends Control

# Test variable to ensure that we can re direct into the right scene based upon sniffer
var rng = RandomNumberGenerator.new()
var index = 0

onready var codex = preload("res://src/Menus/CodexParent.tscn")

func _ready():
	rng.randomize()
	var my_random_number = rng.randf_range(0, 5)
	for button in $MonsterList.get_children():
		button.connect("pressed", self, "monster_list", [button.scene_to_load])
	for button in $Sandwhich.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Spawn.get_children():
		button.connect("pressed", self, "spawn_button", [my_random_number])
	
# Function for spawn button that generates a monster and saves it to the codex
func spawn_button(my_random_number):
	# Create new instance of monster object and then spawn monster
	var r = RfRancher.new()
	
	# Test that accepts a random SSID
	#var m = r.testGetMonster("HiveMind")
	
	# getMonster uses sniffer and if that fails, opens file to read data
	var m = r.getMonster() 
	
	# Push the monster object into an array
	MonsterData.set_monster(m)
	
	# Grab index so that appropriate level is triggered
	var index = m.getType()
	
	# Instance the codex parent and save it
	var instance_codex = codex.instance()
	instance_codex.save_scene()
	
	# Swap scenes to appropriate level
	get_tree().change_scene(MonsterData.levels[index])

# Generic button control for rest of menu
func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)

# Monster list button control
func monster_list(scene_to_load):
	if MonsterData.file_names.size() > 0:
		var file_to_load = MonsterData.file_names[index]
		get_tree().change_scene(file_to_load)
