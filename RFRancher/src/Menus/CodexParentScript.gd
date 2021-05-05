extends Node

# File strings to help create a new scene
var file_res = "res://src/Menus/"
var file_end = ".tscn"

# Save the monster information in a brandnew codex page
func save_scene() -> void:
	var monster_name_label: Label = get_node("CodexTemplate/SkillBox/MonsterName")
	var monster_type_label: Label = get_node("CodexTemplate/SkillBox/MonsterType")
	var monster_color_sprite: Sprite = get_node("CodexTemplate/MonsterSprite")
	var monster_index: Control = get_node("CodexTemplate")
	var i_hope_this_works = MonsterData.monster_array[MonsterData.monster_array.size() - 1]
	var monster_name = i_hope_this_works.getName()
	var type_index = i_hope_this_works.getType()
	var monster_type = MonsterData.types[type_index]
	
	# Populate the type and name fields on the codex
	monster_index._index = MonsterData.num_monsters
	monster_name_label.text = "Name: %s" % monster_name
	monster_type_label.text = "Type: %s" % monster_type
	# Create new file name for the monster codex and store it in global array
	var file = file_res + monster_name + file_end
	
	# Push file name into codex array
	MonsterData.set_codex(file)
	MonsterData.num_monsters += 1
	
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
