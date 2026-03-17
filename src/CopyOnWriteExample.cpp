#include "CopyOnWriteExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>

using namespace godot;

void CopyOnWriteExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("demo_cow"), &CopyOnWriteExample::demo_cow);
    ClassDB::bind_method(D_METHOD("passing_array", "b"), &CopyOnWriteExample::passing_array);
}

void CopyOnWriteExample::demo_cow() {
    // Array e String no Godot usam semântica Copy-On-Write.
    Array a;
    a.append(1);
    a.append(2);
    UtilityFunctions::print("a (inicial):", a);

    // Cópia rasa (compartilhada internamente até ser modificada)
    Array b = a;
    UtilityFunctions::print("b após cópia:", b);

    // Modificar 'b' não deve alterar 'a' por causa do CoW
    passing_array(b);
    UtilityFunctions::print("b após adicionar:", b);
    UtilityFunctions::print("a permanece inalterado:", a);

    // O mesmo vale para String
    String s1 = "hello";
    String s2 = s1; // Compartilham memória
    s2 += " world"; // Ativa copy-on-write internamente
    UtilityFunctions::print("s1:", s1);
    UtilityFunctions::print("s2:", s2);
}

void CopyOnWriteExample::passing_array(Array b) {
    // Modificar 'b' não altera outros Arrays que compartilhavam os dados
    b.append(3);
}
