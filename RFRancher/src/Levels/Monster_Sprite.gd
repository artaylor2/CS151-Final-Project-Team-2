extends Sprite

onready var index = MonsterData.num_monsters - 1
onready var monster = MonsterData.monster_array[index]

# Called when the node enters the scene tree for the first time.
func _ready():
	$".".modulate = monster.getColor()
