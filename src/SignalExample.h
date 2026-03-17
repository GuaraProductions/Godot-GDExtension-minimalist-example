#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

class SignalExample : public Node {
	GDCLASS(SignalExample, Node)

protected:
	static void _bind_methods();

public:
	SignalExample();
	~SignalExample();

	// Emite um sinal de exemplo com dois parâmetros (int, String)
	void emit_custom_signal();

	// Conecta o próprio objeto ao seu sinal (liga o sinal ao método interno)
	void connect_to_self();

	// Conecta o sinal deste objeto a um método de outro `Object`
	void connect_to_node(Object *p_target, String p_method_name);

	// Método que será chamado quando o sinal for recebido
	void on_custom_signal(int p_value, String p_text);
};

} // namespace godot
