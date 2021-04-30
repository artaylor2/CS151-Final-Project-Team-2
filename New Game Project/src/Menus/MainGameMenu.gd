extends Control

var test
var environmentInt
# Test variable to ensure that we can re direct into the right scene based upon sniffer
var rng = RandomNumberGenerator.new()

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
	test = Actor.new()
	test.happiness = 100
	test.hunger = 50
	get_tree().change_scene(MonsterData.levels[my_random_number])

func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)

# Called every frame while in scene. Use this to constantly update the health and happiness of monsters
func _process(delta):
	#Get server tick
	
	pass
