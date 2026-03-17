extends Sprite2D
class_name ExportExample

@export var exported_scene_list: Array[PackedScene] = []

# Exemplo usando setget para validar/transformar ao atribuir
var with_setget: int = 0 setget set_with_setget, get_with_setget

func set_with_setget(v: int) -> void:
	# Aqui você pode validar/limitar o valor antes de armazenar
	with_setget = max(0, v)

func get_with_setget() -> int:
	return with_setget

func _ready() -> void:
	print("ExportExample ready:", exported_int, exported_float, exported_bool)
	print("Vector2:", exported_vector2)
	if exported_scene:
		print("PackedScene assigned in Inspector")
	print("Scene list size:", exported_scene_list.size())
