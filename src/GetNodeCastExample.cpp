#include "GetNodeCastExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>

using namespace godot;

void GetNodeCastExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("demo_get_node_cast", "p_path"), &GetNodeCastExample::demo_get_node_cast);
}

void GetNodeCastExample::demo_get_node_cast(NodePath p_path) {
    if (p_path.is_empty()) {
        UtilityFunctions::print("demo_get_node_cast: NodePath vazio");
        return;
    }

    Object *obj = get_node_or_null(p_path);
    if (!obj) {
        UtilityFunctions::print("demo_get_node_cast: nó não encontrado em:", p_path);
        return;
    }

    // Tentamos converter para Sprite2D usando Object::cast_to
    Sprite2D *n2d = Object::cast_to<Node2D>(obj);
    if (n2d) {
        // Exemplo de uso: imprimir posição
        UtilityFunctions::print("demo_get_node_cast: nó é Sprite2D, posição:", n2d->get_position());
        return;
    }

    // Se não for Node2D, informar tipo
    UtilityFunctions::print("demo_get_node_cast: nó encontrado, mas não é Sprite2D");
}
