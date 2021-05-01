extends Control

var x : = 75
var temp = MonsterData.monster_array[0]

onready var monster_name: Label = get_node("SkillBox/MonsterName")
onready var happiness: Label = get_node("StatusBox/CanvasLayer/Happiness/Counter/HappinessLabel")
onready var happybar: TextureProgress = get_node("StatusBox/CanvasLayer/Happiness/HappinessBar")
onready var hunger: Label = get_node("StatusBox/CanvasLayer/Hunger/Counter/HungerLabel")
onready var hungerbar: TextureProgress = get_node("StatusBox/CanvasLayer/Hunger/HungerBar")

func _ready():
	for button in $CloseContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	update_hapbar() # Called when scene is ready, so that right happiness value is called
	update_hunbar()

func set_name_menu(name) -> void:
	monster_name.text = "Monster name: %s" % name
	
func update_hapbar() -> void:
	happiness.text = "%s/100" % temp.getHappy() # Use the mod here to update the /100. Use the game tick function?
	#get_node("StatusBox/CanvasLayer/Happiness/HappinessBar").value = temp.getHappy() # Grab the nodes value and update it with the value of x

# Update the hunger bar and value for the monster. Call this to update when the tick is called
func update_hunbar() -> void:
	hunger.text = "%s/100" % temp.getHunger()
	#get_node("StatusBox/CanvasLayer/Hunger/HungerBar").value = temp.getHunger() # Grab the nodes value and update it with the value of x
	
func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)
	
func _process(delta):
	#Get server tick
	temp.doTick()
	update_hapbar() # Called when scene is ready, so that right happiness value is called
	update_hunbar()
