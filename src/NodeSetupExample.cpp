#include "NodeSetupExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>
#include <godot_cpp/core/memory.hpp>

using namespace godot;

void NodeSetupExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_child_path", "p_path"), &NodeSetupExample::set_child_path);
    ClassDB::bind_method(D_METHOD("setup_child"), &NodeSetupExample::setup_child);
    ClassDB::bind_method(D_METHOD("use_child"), &NodeSetupExample::use_child);
}

void NodeSetupExample::set_child_path(NodePath p_path) {
    child_path = p_path;
}

void NodeSetupExample::setup_child() {
    // Usa get_node com o NodePath declarado no header para atribuir o ponteiro cru
    if (child_path.is_empty()) {
        UtilityFunctions::print("setup_child: child_path está vazio");
        child_ptr = nullptr;
        return;
    }

    Node *obj = get_node_or_null(child_path);
    if (!obj) {
        UtilityFunctions::print("setup_child: nó não encontrado para o caminho:", child_path);

        // Criar um novo Node dinamicamente (equivalente ao `.new()` em GDScript)
        Node *created = memnew(Node);
        created->set_name("created_child");
        add_child(created);
        child_ptr = created;
        UtilityFunctions::print("setup_child: criado novo filho via memnew e adicionado como child:", child_ptr->get_name());
        return;
    }

    // cast para Node e armazenar ponteiro cru (sem gerenciamento automático)
    child_ptr = Object::cast_to<Node>(obj);
    if (child_ptr) {
        UtilityFunctions::print("setup_child: filho encontrado via get_node:", child_ptr->get_name());
    } else {
        UtilityFunctions::print("setup_child: objeto encontrado não é um Node");
    }
}

void NodeSetupExample::use_child() {
    if (!child_ptr) {
        UtilityFunctions::print("use_child: child_ptr é nulo");
        return;
    }
    UtilityFunctions::print("use_child: nome=", child_ptr->get_name());
}
