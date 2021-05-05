extends Node

# File strings to help create a new scene
var file_res = "res://src/Menus/"
var file_end = ".tscn"

# Save the monster information in a brandnew codex page
func save_scene() -> void:
	var i_hope_this_works = MonsterData.monster_array[MonsterData.monster_array.size() - 1]
	var monster_name = i_hope_this_works.getName()
	var rng = RandomNumberGenerator.new()
	rng.randomize()
	var my_random_number = rng.randf_range(0, 999999999)
	
	# Create new file name for the monster codex and store it in global array
	var file = file_res + monster_name + String(my_random_number)+ file_end
	
	var codexthingy = get_child(0)
	var horrible = MonsterData.num_monsters
	MonsterData.set_codex(file)
	codexthingy.index = horrible
	MonsterData.num_monsters += 1
	print(MonsterData.num_monsters)
	
	# Save the monster codex as a new scene
	var packed_scene = PackedScene.new()
	var scene_root = $CodexTemplate
	_set_owner(scene_root, scene_root)
	packed_scene.pack(scene_root)

	ResourceSaver.save(file, packed_scene)

# Function that takes the instance and makes the new parent node owner of all children
func _set_owner(node, root):
	if node != root:
		node.owner = root
	for child in node.get_children():
		_set_owner(child, root)
