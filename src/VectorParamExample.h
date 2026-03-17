#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/utility_functions.hpp>

#include <vector>

namespace godot {

class VectorParamExample : public Node {
    GDCLASS(VectorParamExample, Node)

protected:
    static void _bind_methods();

public:
    void demo_vector_param();
    void pass_by_value(std::vector<int> v);
    void pass_by_ref(std::vector<int> &v);
};

} // namespace godot
