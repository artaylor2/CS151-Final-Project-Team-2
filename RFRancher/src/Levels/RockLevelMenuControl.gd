extends Control


var file_res = "res://src/Menus/"
var file_end = ".tscn"
var monname = "MonsterTestCodex"

var fileload = load("res://src/Menus/CodexTemplate.tscn")

# Called when the node enters the scene tree for the first time.
func _ready():
	for button in $CloseContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])

func _on_Button_pressed(scene_to_load):
	var newCodex = fileload.instance()
	newCodex.hide()
	newCodex.save_scene()
	get_tree().change_scene(scene_to_load)
