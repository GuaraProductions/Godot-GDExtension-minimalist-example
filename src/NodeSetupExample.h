#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/utility_functions.hpp>

namespace godot {

class NodeSetupExample : public Node {
    GDCLASS(NodeSetupExample, Node)

private:
    NodePath child_path;
    Node *child_ptr = nullptr;

protected:
    static void _bind_methods();

public:
    void set_child_path(NodePath p_path);
    void setup_child();
    void use_child();
};

} // namespace godot
