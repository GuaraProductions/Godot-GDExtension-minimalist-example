#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/utility_functions.hpp>

namespace godot {

class CopyOnWriteExample : public Node {
    GDCLASS(CopyOnWriteExample, Node)

protected:
    static void _bind_methods();

public:
    void demo_cow();
    void passing_array(Array b);
};

} // namespace godot
