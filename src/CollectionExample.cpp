#include "CollectionExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>

#include <sstream>

using namespace godot;

void CollectionExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("demo_collections"), &CollectionExample::demo_collections);

    ClassDB::bind_method(D_METHOD("get_example_array"), &CollectionExample::get_example_array);
    ClassDB::bind_method(D_METHOD("set_example_array", "a"), &CollectionExample::set_example_array);

    ClassDB::bind_method(D_METHOD("get_example_dict"), &CollectionExample::get_example_dict);
    ClassDB::bind_method(D_METHOD("set_example_dict", "d"), &CollectionExample::set_example_dict);

    ClassDB::bind_method(D_METHOD("get_example_typed_array"), &CollectionExample::get_example_typed_array);
    ClassDB::bind_method(D_METHOD("set_example_typed_array", "t"), &CollectionExample::set_example_typed_array);
}

CollectionExample::CollectionExample() {

    //Tipo baseado em Variant
    example_array = Array();
    example_dict = Dictionary();

    // Array com tipagem estática do Godot
    example_typed_array = TypedArray<int>();

    // Inicializa exemplos da STL
    std_vector = {5, 6, 7};
    std_map = {{"one", 1}, {"two", 2}};

    // Inicializa arrays C (exemplo com ponteiros puros)
    c_int_array_size = 3;
    c_int_array = (int *)std::malloc(c_int_array_size * sizeof(int));
    if (c_int_array) {
        c_int_array[0] = 100;
        c_int_array[1] = 200;
        c_int_array[2] = 300;
    }

    c_double_array_size = 2;
    c_double_array = new double[c_double_array_size];
    c_double_array[0] = 1.5;
    c_double_array[1] = 2.5;
}

CollectionExample::~CollectionExample() {
    if (c_int_array) {
        std::free(c_int_array);
        c_int_array = nullptr;
    }
    if (c_double_array) {
        delete[] c_double_array;
        c_double_array = nullptr;
    }
}

void CollectionExample::demo_collections() {
    // Array: mistura de tipos é permitida (Variant-based)
    example_array.append(1);
    example_array.append("two");
    example_array.append(3.0);
    UtilityFunctions::print("example_array:", example_array);

    // Dictionary: mapeia chaves -> valores (ambos Variant)
    example_dict["answer"] = 42;
    example_dict["name"] = "Godot";
    example_dict[1] = "numeric key";
    UtilityFunctions::print("example_dict:", example_dict);

    // TypedArray<int>: armazena somente ints e provê acesso tipado
    example_typed_array.resize(3);
    example_typed_array[0] = 10;
    example_typed_array[1] = 20;
    example_typed_array[2] = 30;
    UtilityFunctions::print("example_typed_array:", example_typed_array);

    // --- Exemplos com a Standard Library ---
    // std::vector -> imprimir via Array conversão simples
    Array from_std_vector;
    for (int v : std_vector) {
        from_std_vector.append(v);
    }
    UtilityFunctions::print("std_vector:", from_std_vector);

    // std::map -> Dictionary
    Dictionary map_as_dict;
    for (const auto &p : std_map) {
        map_as_dict[String(p.first.c_str())] = p.second;
    }
    UtilityFunctions::print("std_map:", map_as_dict);

    // --- Exemplos com arrays C (ponteiros puros) ---
    Array c_ints;
    if (c_int_array && c_int_array_size > 0) {
        for (size_t i = 0; i < c_int_array_size; ++i) {
            c_ints.append(c_int_array[i]);
        }
    }
    UtilityFunctions::print("c_int_array:", c_ints);

    Array c_doubles;
    if (c_double_array && c_double_array_size > 0) {
        for (size_t i = 0; i < c_double_array_size; ++i) {
            c_doubles.append(c_double_array[i]);
        }
    }
    UtilityFunctions::print("c_double_array:", c_doubles);
}

Array CollectionExample::get_example_array() const { return example_array; }
void CollectionExample::set_example_array(Array a) { example_array = a; }

Dictionary CollectionExample::get_example_dict() const { return example_dict; }
void CollectionExample::set_example_dict(Dictionary d) { example_dict = d; }

TypedArray<int> CollectionExample::get_example_typed_array() const { return example_typed_array; }
void CollectionExample::set_example_typed_array(TypedArray<int> t) { example_typed_array = t; }
