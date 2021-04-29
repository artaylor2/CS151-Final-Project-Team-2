extends KinematicBody2D		# Extend the node that is the base class of the parent node
class_name Actor		# Name of the class

const FLOOR_NORMAL: = Vector2.UP

var velocity: = Vector2.ZERO  # : = is how you assign and note that vector 2 is for 2 dimensions (x,y). Here we move 300 pixels on x
export var gravity: = 3000.0	# Add the decimal to turn it into a float and not an int. Note that this is pixels/s^2
export var speed: = Vector2(300.0, 1000.0)
export var health: = 100.0
export var hunger: = 100.0
export var happiness: = 100.0


# func _physics_process(delta: float) -> void:	# This is a function that constantly calls every frame to move actor
# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
