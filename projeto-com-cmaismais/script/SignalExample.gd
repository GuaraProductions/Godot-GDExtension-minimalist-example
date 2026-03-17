extends Node
class_name SignalExample

# Declaração de sinal usando a sintaxe do Godot 4 (com tipagem)
signal custom_signal(value: int, text: String)

func _ready() -> void:
	# Conectar o sinal ao método deste mesmo objeto (string API)
	connect("custom_signal", self, "on_custom_signal")

	# Conectar usando Callable (API preferida em Godot 4)
	# `custom_signal` é um objeto de sinal e expõe `connect(Callable)`.
	custom_signal.connect(on_custom_signal)

	# Emissão de sinal (sintaxe antiga)
	# emit_signal("custom_signal", 123, "hello from GDScript")
	# Emissão de sinal (sintaxe nova)
	custom_signal.emit(123, "hello from GDScript")

	# Exemplo: conectar o sinal deste nó ao método de outro nó (se existir)
	var other := get_node_or_null("../Other")
	if other:
		# Conecta o sinal deste nó ao método `on_custom_signal` do outro nó
		custom_signal.connect(other.on_custom_signal)

	# Também é possível conectar usando o sinal do outro nó ao método deste
	# se o outro nó declarar o mesmo sinal:
	# if other:
	#     other.custom_signal.connect(Callable(self, "on_custom_signal"))

func emit_example() -> void:
	# Método público para emitir o sinal manualmente
	custom_signal.emit(123, 999, "hello from GDScript")

func on_custom_signal(value: int, text: String) -> void:
	print("on_custom_signal fired:", value, text)
