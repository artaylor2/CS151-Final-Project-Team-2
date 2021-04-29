extends Control


func _ready():
	for button in $MonsterList.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Sandwhich.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $Spawn.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])



func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)
