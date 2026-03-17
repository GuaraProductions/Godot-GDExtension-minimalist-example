#include "SignalExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>

using namespace godot;

void SignalExample::_bind_methods() {
    // Registra o sinal `custom_signal` com dois parâmetros:
    // 1) value (Variant::INT)
    // 2) text  (Variant::STRING)
    ADD_SIGNAL(MethodInfo("custom_signal",
                    PropertyInfo(Variant::INT, "value"),
                    PropertyInfo(Variant::STRING, "text"))
              );

    // Liga métodos utilitários para emitir/conectar/receber sinais
    ClassDB::bind_method(D_METHOD("emit_custom_signal"), &SignalExample::emit_custom_signal);
    ClassDB::bind_method(D_METHOD("connect_to_self"), &SignalExample::connect_to_self);
    ClassDB::bind_method(D_METHOD("connect_to_node", "target", "method_name"), &SignalExample::connect_to_node);
    ClassDB::bind_method(D_METHOD("on_custom_signal", "value", "text"), &SignalExample::on_custom_signal);
}

SignalExample::SignalExample() {}
SignalExample::~SignalExample() {}

// Exemplo simples de emissão de sinal. Emite `custom_signal` com dois parâmetros.
void SignalExample::emit_custom_signal() {
    int value = 123;
    String text = "hello from C++";
    // Emite o sinal registrado em _bind_methods
    emit_signal("custom_signal", value, text);
}

// Conecta o sinal deste objeto ao próprio método `on_custom_signal`.
// Uso: chama-se `connect_to_self()` para que `on_custom_signal` seja invocado
// sempre que `emit_custom_signal()` emitir o sinal.
void SignalExample::connect_to_self() {
    // connect(signal_name, target_object, method_name)
    connect("custom_signal", this, "on_custom_signal");
}

// Conecta o sinal deste objeto a um método de outro `Object`.
// Parâmetros em sequência:
//  - p_target: ponteiro para o objeto que receberá o callback
//  - p_method_name: nome do método no `p_target` que será chamado
void SignalExample::connect_to_node(Object *p_target, String p_method_name) {
    if (!p_target) {
        UtilityFunctions::print("connect_to_node: target is null");
        return;
    }
    connect("custom_signal", p_target, p_method_name);
}

// Callback que demonstra tratamento do sinal.
void SignalExample::on_custom_signal(int p_value, String p_text) {
    UtilityFunctions::print("on_custom_signal fired:", p_value, p_text);
}
