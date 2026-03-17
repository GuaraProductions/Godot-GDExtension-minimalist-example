#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/core/utility_functions.hpp>
#include <cstdlib>
#include <vector>
#include <map>

namespace godot {

class CollectionExample : public Node {
    GDCLASS(CollectionExample, Node)

private:
    // Exemplos mantidos como membros para retornar via getters
    Array example_array;
    Dictionary example_dict;
    TypedArray<int> example_typed_array;

    // Exemplos usando a Standard Library do C++
    std::vector<int> std_vector;
    std::map<std::string, int> std_map;

    // Exemplos de arrays em estilo C (ponteiros puros)
    int *c_int_array = nullptr;
    size_t c_int_array_size = 0;
    double *c_double_array = nullptr;
    size_t c_double_array_size = 0;

protected:
    static void _bind_methods();

public:
    CollectionExample();
    ~CollectionExample();

    // Preenche e imprime exemplos de coleções
    void demo_collections();

    // Getters / Setters
    Array get_example_array() const;
    void set_example_array(Array a);

    Dictionary get_example_dict() const;
    void set_example_dict(Dictionary d);

    TypedArray<int> get_example_typed_array() const;
    void set_example_typed_array(TypedArray<int> t);
};

} // namespace godot
