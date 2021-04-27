extends Control


func _ready():
	for button in $MonsterList.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Sandwhich.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Spawn.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])


# Create a function call that sets monster caught to true, passing it to the monster list 
# script so that we can display the found monster

func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)
