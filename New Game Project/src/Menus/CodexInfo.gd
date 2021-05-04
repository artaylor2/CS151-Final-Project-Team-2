extends Control
var created_forward = false
var created_back = false

export(int) var _index

onready var go_back: CenterContainer = get_node("Backwards_Container")
onready var go_back_button: Button = get_node("Backwards_Container/GoBack")
onready var go_next: CenterContainer = get_node("Forwards_Container")
onready var go_next_button: Button = get_node("Forwards_Container/GoNext")

# Called when the node enters the scene tree for the first time.
func _ready():
	# Close button connection
	for button in $CloseContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	for button in $FeedContainer.get_children():
		button.connect("pressed", self, "_feed_Monster")
	for button in $PlayContainer.get_children():
		button.connect("pressed", self, "_play")
	
	if MonsterData.num_monsters != 1:
		if MonsterData.num_monsters != 1:
			created_back = true
			var forward_button = Button.new()
			go_back.visible(true)

# Close button function
func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)

func _feed_Monster():
	var feed = MonsterData.monster_array[_index]
	
func _play():
	pass
