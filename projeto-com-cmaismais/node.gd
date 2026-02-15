extends Node

@onready var gd_example: GDExample = $GDExample

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	gd_example.minha_funcao()
