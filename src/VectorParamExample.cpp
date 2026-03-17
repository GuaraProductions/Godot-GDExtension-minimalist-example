#include "VectorParamExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>

using namespace godot;

void VectorParamExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("demo_vector_param"), &VectorParamExample::demo_vector_param);
    ClassDB::bind_method(D_METHOD("pass_by_value", "v"), &VectorParamExample::pass_by_value);
    ClassDB::bind_method(D_METHOD("pass_by_ref", "v"), &VectorParamExample::pass_by_ref);
}

void VectorParamExample::pass_by_value(std::vector<int> v) {
    if (!v.empty()) v[0] = 999;
    uintptr_t ptr = (v.empty() ? 0 : (uintptr_t)v.data());
    UtilityFunctions::print("inside pass_by_value first:", (v.empty() ? -1 : v[0]), " ptr:", (int64_t)ptr);
}

void VectorParamExample::pass_by_ref(std::vector<int> &v) {
    if (!v.empty()) v[0] = 111;
    uintptr_t ptr = (v.empty() ? 0 : (uintptr_t)v.data());
    UtilityFunctions::print("inside pass_by_ref first:", (v.empty() ? -1 : v[0]), " ptr:", (int64_t)ptr);
}

void VectorParamExample::demo_vector_param() {
    std::vector<int> vec = {1,2,3};
    uintptr_t before_ptr = (uintptr_t)vec.data();
    UtilityFunctions::print("vec antes - primeiro:", vec[0], " ponteiro:", (int64_t)before_ptr);
    pass_by_value(vec);
    UtilityFunctions::print("vec depois de pass_by_value - primeiro:", vec[0], " ponteiro:", (int64_t)before_ptr);
    pass_by_ref(vec);
    UtilityFunctions::print("vec depois de pass_by_ref - primeiro:", vec[0], " ponteiro:", (int64_t)before_ptr);
}
