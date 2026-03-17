#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/core/utility_functions.hpp>

namespace godot {

class GetNodeCastExample : public Node {
    GDCLASS(GetNodeCastExample, Node)

protected:
    static void _bind_methods();

public:
    // Demonstra get_node_or_null + Object::cast_to para Node2D
    void demo_get_node_cast(NodePath p_path);
};

} // namespace godot
