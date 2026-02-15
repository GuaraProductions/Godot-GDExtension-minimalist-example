#include "GDExample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    // Ligar a função personalizada para ser chamável no GDScript
    // D_METHOD("nome_no_gdscript") liga ao ponteiro da função no C++
    ClassDB::bind_method(D_METHOD("minha_funcao"), &GDExample::minha_funcao);

    // Ligar os Getters e Setters da variável exportada
    // É obrigatório ligar os métodos get/set antes de registrar a propriedade
    ClassDB::bind_method(D_METHOD("get_variavel_do_export"), &GDExample::get_variavel_do_export);
    ClassDB::bind_method(D_METHOD("set_variavel_do_export", "p_value"), &GDExample::set_variavel_do_export);

    // Registrar a propriedade para aparecer no Inspetor do Editor
    // PropertyInfo define o tipo (INT) e o nome que aparece no editor ("variavel_do_export")
    ADD_PROPERTY(PropertyInfo(Variant::INT, "variavel_do_export"), "set_variavel_do_export", "get_variavel_do_export");
}

GDExample::GDExample() {
	// Inicialização das variáveis
	time_passed = 0.0;
}

GDExample::~GDExample() {
	// Limpeza da classe
}

void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position =
     Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

	set_position(new_position);
}

void GDExample::minha_funcao() {
    // UtilityFunctions funciona como o print() do GDScript/Python
    UtilityFunctions::print("Minha função foi chamada via C++! Valor atual: ", variavel_do_export);
}

// Implementação do Getter
int GDExample::get_variavel_do_export() const {
    return variavel_do_export;
}

// Implementação do Setter
void GDExample::set_variavel_do_export(int p_variavel_do_export) {
    variavel_do_export = p_variavel_do_export;
}