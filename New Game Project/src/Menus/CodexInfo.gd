extends Control

var created_back = false
var created_forward = false

export(int) var index = 0
onready var monster = MonsterData.monster_array[index]
onready var go_back = get_node("Backwards_Container")
onready var go_back_button: Button = get_node("Backwards_Container/GoBack")
onready var go_next = get_node("Forwards_Container")
onready var go_next_button: Button = get_node("Forwards_Container/GoNext")
onready var hunger_update: Label = get_node("StatusBox/CanvasLayer/Happiness/Counter/HappinessLabel")
onready var happy_update: Label = get_node("StatusBox/CanvasLayer/Hunger/Counter/HungerLabel")
onready var last_index = MonsterData.monster_array.size() - 1
onready var monster_name: Label = get_node("SkillBox/MonsterName")
onready var monster_type: Label = get_node("SkillBox/MonsterType")

# Called when the node enters the scene tree for the first time.
func _ready():
	print(index)

	if index != 0:
		created_back = true
		$Backwards_Container/GoBack.visible = created_back
		go_back_button.scene_to_load = MonsterData.file_names[index - 1]
	
	if !created_forward:
		if index != last_index:
			$Forwards_Container/GoNext.visible = true
			go_next_button.scene_to_load = MonsterData.file_names[last_index]
			created_forward = true
	
	monster_name.text = "Name: %s" % monster.getName()
	
	hunger_update.text = String(monster.getHunger()) + "/" + String(monster.getMaxHunger())
	happy_update.text = String(monster.getHappy()) + "/" + String(monster.getMaxHappy()) 
	
	
	# Close button connection
	for button in $CloseContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	
	# Feed button connection
	for button in $FeedContainer.get_children():
		button.connect("pressed", self, "_feed_Monster")
	
	# Play button connection
	for button in $PlayContainer.get_children():
		button.connect("pressed", self, "_play")

# Close button function
func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)

func _feed_Monster():
	monster.eat(25)
	
func _play():
	monster.play()
