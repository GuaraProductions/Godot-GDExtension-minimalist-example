extends Node
class_name CollectionExample

# Exemplo comparável a `CollectionExample.cpp` em GDScript (Godot 4)
func _ready() -> void:
	demo_collections()

func demo_collections() -> void:
	# Declarações centralizadas (tipadas quando aplicável)
	var example_array: Array = [1, "two", 3.0]
	var example_dict: Dictionary = {
		"answer": 42,
		"name": "Godot",
		1: "numeric key"
	}
	var typed: PackedInt32Array = PackedInt32Array([10, 20, 30])
	var example_typed_array: Array[int] = []
	example_typed_array.resize(3)
	example_typed_array[0] = 10;
	example_typed_array[1] = 20;	
	example_typed_array[2] = 30;
			
	var from_array: PackedInt32Array = PackedInt32Array()

	# Uso das coleções
	# Array: permite misturar tipos (Variant-based)
	print("example_array:", example_array)

	# Dictionary: mapeamento chave -> valor (chave/valor podem ser Variant)
	print("example_dict:", example_dict)

	# Typed array (PackedInt32Array) — armazena apenas ints
	print("typed (PackedInt32Array):", typed)

	# Array tipado de String
	print("string_array (Array[String]):", string_array)

	# Acesso e modificação
	typed.append(40)
	print("typed after append:", typed)
	print("typed[0]:", typed[0])

	# Converter Array -> PackedInt32Array (quando todos os elementos são ints)
	for e in example_array:
		if typeof(e) == TYPE_INT:
			from_array.append(e)
	print("from_array (ints only):", from_array)
