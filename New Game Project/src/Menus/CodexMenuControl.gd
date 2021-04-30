extends Control

var x : = 75

onready var happiness: Label = get_node("StatusBox/CanvasLayer/Happiness/Counter/HappinessLabel")
onready var happybar: TextureProgress = get_node("StatusBox/CanvasLayer/Happiness/HappinessBar")
onready var hunger: Label = get_node("StatusBox/CanvasLayer/Hunger/Counter/HungerLabel")
onready var hungerbar: TextureProgress = get_node("StatusBox/CanvasLayer/Hunger/HungerBar")

func _ready():
	for button in $CloseContainer.get_children():
		button.connect("pressed", self, "_on_Button_pressed", [button.scene_to_load])
	update_hapbar() # Called when scene is ready, so that right happiness value is called
	update_hunbar()
# Update hunger and happiness every frame, calling the game ticks
#func _process(delta):
#	MonsterData.connect("update_happiness", self, "update_hapbar")
#	update_hapbar()
#	MonsterData.connect("update_hunger", self, "update_hunbar")
#	update_hunbar()



func update_hapbar() -> void:
	happiness.text = "%s/100" % x # Use the mod here to update the /100. Use the game tick function?
	get_node("StatusBox/CanvasLayer/Happiness/HappinessBar").value = x # Grab the nodes value and update it with the value of x

# Update the hunger bar and value for the monster. Call this to update when the tick is called
func update_hunbar() -> void:
	hunger.text = "%s/100" % x
	get_node("StatusBox/CanvasLayer/Hunger/HungerBar").value = x # Grab the nodes value and update it with the value of x
	
func _on_Button_pressed(scene_to_load):
	get_tree().change_scene(scene_to_load)
