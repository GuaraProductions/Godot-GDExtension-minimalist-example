#include "ExportExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

void ExportExample::_bind_methods() {
    // Inteiros
    ClassDB::bind_method(
        D_METHOD("get_exported_int"),
        &ExportExample::get_exported_int
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_int", "v"),
        &ExportExample::set_exported_int
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::INT, "exported_int"),
        "set_exported_int",
        "get_exported_int"
    );

    // Float (double)
    ClassDB::bind_method(
        D_METHOD("get_exported_float"),
        &ExportExample::get_exported_float
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_float", "v"),
        &ExportExample::set_exported_float
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::REAL, "exported_float"),
        "set_exported_float",
        "get_exported_float"
    );

    // Boolean
    ClassDB::bind_method(
        D_METHOD("get_exported_bool"),
        &ExportExample::get_exported_bool
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_bool", "v"),
        &ExportExample::set_exported_bool
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::BOOL, "exported_bool"),
        "set_exported_bool",
        "get_exported_bool"
    );

    // Vector2
    ClassDB::bind_method(
        D_METHOD("get_exported_vector2"),
        &ExportExample::get_exported_vector2
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_vector2", "v"),
        &ExportExample::set_exported_vector2
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::VECTOR2, "exported_vector2"),
        "set_exported_vector2",
        "get_exported_vector2"
    );

    // NodePath
    ClassDB::bind_method(
        D_METHOD("get_exported_node_path"),
        &ExportExample::get_exported_node_path
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_node_path", "p"),
        &ExportExample::set_exported_node_path
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::NODE_PATH, "exported_node_path"),
        "set_exported_node_path",
        "get_exported_node_path"
    );

    // PackedScene (Resource)
    ClassDB::bind_method(
        D_METHOD("get_exported_scene"),
        &ExportExample::get_exported_scene
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_scene", "s"),
        &ExportExample::set_exported_scene
    );
    ADD_PROPERTY(
        PropertyInfo(Variant::OBJECT, "exported_scene", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"),
        "set_exported_scene",
        "get_exported_scene"
    );

    // Array de PackedScene
    ClassDB::bind_method(
        D_METHOD("get_exported_scene_list"),
        &ExportExample::get_exported_scene_list
    );
    ClassDB::bind_method(
        D_METHOD("set_exported_scene_list", "a"),
        &ExportExample::set_exported_scene_list
    );
    ADD_PROPERTY(
        PropertyInfo(
            Variant::ARRAY,
            "exported_scene_list",
            PROPERTY_HINT_TYPE_STRING,
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PackedScene"
        ),
        "set_exported_scene_list",
        "get_exported_scene_list"
    );
}

ExportExample::ExportExample() {
    // valores default já inicializados no header
}

ExportExample::~ExportExample() {}

int ExportExample::get_exported_int() const { return exported_int; }
void ExportExample::set_exported_int(int v) { exported_int = v; }

double ExportExample::get_exported_float() const { return exported_float; }
void ExportExample::set_exported_float(double v) { exported_float = v; }

bool ExportExample::get_exported_bool() const { return exported_bool; }
void ExportExample::set_exported_bool(bool v) { exported_bool = v; }

Vector2 ExportExample::get_exported_vector2() const { return exported_vector2; }
void ExportExample::set_exported_vector2(Vector2 v) { exported_vector2 = v; }

NodePath ExportExample::get_exported_node_path() const { return exported_node_path; }
void ExportExample::set_exported_node_path(NodePath p) { exported_node_path = p; }

Ref<PackedScene> ExportExample::get_exported_scene() const { return exported_scene; }
void ExportExample::set_exported_scene(Ref<PackedScene> s) { exported_scene = s; }

Array ExportExample::get_exported_scene_list() const { return exported_scene_list; }
void ExportExample::set_exported_scene_list(Array a) { exported_scene_list = a; }
