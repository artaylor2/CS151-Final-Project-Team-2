extends Control

# Test variable to ensure that we can re direct into the right scene based upon sniffer
var rng = RandomNumberGenerator.new()

onready var codex = preload("res://src/Menus/CodexParent.tscn")

func _ready():
	rng.randomize()
	var my_random_number = rng.randf_range(0, 5)
	for button in $MonsterList.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Sandwhich.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Spawn.get_children():
		button.connect("pressed", self, "spawn_button", [my_random_number])
	
# Create a function call that sets monster caught to true, passing it to the monster list 
# script so that we can display the found monster
func spawn_button(my_random_number):
	var r = RfRancher.new()
	var m = r.getMonster("HiveMind")
	var name = m.getName()
	var type = m.getType()
	print(m.getHunger())
	
	# Push the monster object into an array
	MonsterData.set_monster(m)
	
	var instance_codex = codex.instance()
	instance_codex.save_scene()
	
	# Swap scenes to appropriate level
	get_tree().change_scene(MonsterData.levels[my_random_number])

func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)


