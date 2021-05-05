extends Control

export(int) var index = 0

onready var last_index = MonsterData.monster_array.size() - 1
onready var monster = MonsterData.monster_array[index]

onready var go_back = get_node("Backwards_Container")
onready var go_back_button: Button = get_node("Backwards_Container/GoBack")
onready var go_next = get_node("Forwards_Container")
onready var go_next_button: Button = get_node("Forwards_Container/GoNext")

onready var hunger_update: Label = get_node("StatusBox/CanvasLayer/Happiness/Counter/HappinessLabel")
onready var happy_update: Label = get_node("StatusBox/CanvasLayer/Hunger/Counter/HungerLabel")
onready var health_update: Label = get_node("StatusBox/CanvasLayer/Health/Counter/HealthBarLabel")

onready var hunger_progress = get_node("StatusBox/CanvasLayer/Hunger/HungerBar")
onready var happy_progress = get_node("StatusBox/CanvasLayer/Happiness/HappinessBar")
onready var health_progress = get_node("StatusBox/CanvasLayer/Health/HealthBar")

onready var monster_name: Label = get_node("SkillBox/MonsterName")
onready var monster_type: Label = get_node("SkillBox/MonsterType")

# Called when the node enters the scene tree for the first time.
func _ready():
	print(index)

	# Determine if codex forward needs to be activiated
	if index != 0:
		$Backwards_Container/GoBack.visible = true
		go_back_button.scene_to_load = MonsterData.file_names[index - 1]
	
	# Determine if codex backward needs to be activated
	if index != last_index && MonsterData.num_monsters != 1:
		$Forwards_Container/GoNext.visible = true
		go_next_button.scene_to_load = MonsterData.file_names[index + 1]

	# Set monster name and status in label space
	monster_name.text = "Name: %s" % monster.getName()	
	hunger_progress.max_value = monster.getMaxHunger()
	happy_progress.max_value = monster.getMaxHappy()
	health_progress.max_value = monster.getMaxHealth()
	
	update_status()
	
	# Button connections
	for button in $Backwards_Container.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
		
	for button in $Forwards_Container.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	
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
	monster.eat(5)
	update_status()
	
func _play():
	monster.play()
	update_status()
	
func update_status():
	# Update various status bars
	health_update.text = String(monster.getHealth()) + "/" + String(monster.getMaxHealth())
	hunger_update.text = String(monster.getHunger()) + "/" + String(monster.getMaxHunger())
	happy_update.text = String(monster.getHappy()) + "/" + String(monster.getMaxHappy()) 
	
	hunger_progress.value = monster.getHunger()
	health_progress.value = monster.getHealth()
	happy_progress.value = monster.getHappy()
