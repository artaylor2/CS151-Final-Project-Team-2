extends Actor	# Inherit everything from the Actor.gd

func _physics_process(delta: float) -> void:	# Godot will run this function along with the parent physics function
	var direction = get_direction()	# Keep variables locally in functions to prevent outside functions from messing with variables
	# Returns float and detects how far right it is between 1 and 0. Partial depressions are in between
	# Doing the subtraction ensures that we have 0 movement if the player is pressing both keys at the same time
	velocity = calculate_move_velocity(velocity, speed, direction)
# Essentially we are adding complexity to the player actor by taking the physics function call from the parent and calling this
# subroutine along with it to provide control for the x axis
	velocity = move_and_slide(velocity, FLOOR_NORMAL)	# .UP is a const that is (0, -1)

func get_direction() -> Vector2: # Gets the direction and returns a 2D vector
	return Vector2(Input.get_action_strength("move_right") - Input.get_action_strength("move_left"),
				   -1.0 if Input.is_action_just_pressed("jump") and is_on_floor() else 0.0)

func calculate_move_velocity(linear_velocity: Vector2, speed: Vector2, direction: Vector2) -> Vector2:
	var new_velocity: = linear_velocity
	new_velocity.x = speed.x * direction.x
	new_velocity.y += gravity * get_physics_process_delta_time()	# Access y value in vector and take gravity and multiply by delta to make it framerate independent
	if direction.y == -1.0:
		new_velocity.y = speed.y * direction.y
	return new_velocity
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
