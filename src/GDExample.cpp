#include "GDExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <cstdlib>
#include <ctime>

using namespace godot;

void GDExample::_bind_methods() {
    // Ligar a função personalizada para ser chamável no GDScript
    // D_METHOD("nome_no_gdscript") liga ao ponteiro da função no C++
    ClassDB::bind_method(D_METHOD("minha_funcao"), &GDExample::minha_funcao);

    // Ligar os Getters e Setters da variável exportada
    // É obrigatório ligar os métodos get/set antes de registrar a propriedade
    ClassDB::bind_method(D_METHOD("get_variavel_do_export"), 
                         &GDExample::get_variavel_do_export);
    ClassDB::bind_method(D_METHOD("set_variavel_do_export", "p_value"), 
                        &GDExample::set_variavel_do_export);

    // Registrar a propriedade para aparecer no Inspetor do Editor
    // PropertyInfo define o tipo (INT) e o nome que aparece no editor 
    // ("variavel_do_export")
    ADD_PROPERTY(
        PropertyInfo(Variant::INT, "variavel_do_export"), 
        "set_variavel_do_export", 
        "get_variavel_do_export");

    // Registra o sinal "position_changed" para uso em GDScript/C++.
    // Parâmetros (em sequência):
    // 1) node (Variant::OBJECT) - nó relacionado ao evento.
    // 2) new_pos (Variant::VECTOR2) - nova posição associada ao evento.
    // Uso: emit_signal("position_changed", node, new_pos);
    // `MethodInfo` descreve o nome e os parâmetros do sinal.
    ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), 
               PropertyInfo(Variant::VECTOR2, "new_pos")));

    // Métodos que expõem a lista de cenas e selecionam uma cena aleatória
    ClassDB::bind_method(D_METHOD("get_random_dungeon"), &GDExample::get_random_dungeon);
    ClassDB::bind_method(D_METHOD("get_scenes"), &GDExample::get_scenes);
    ClassDB::bind_method(D_METHOD("set_scenes", "p_scenes"), &GDExample::set_scenes);

    // Registra a propriedade `scenes` (Array) no Inspector.
    // PropertyInfo argumentos (em sequência):
    // 1) Variant::ARRAY - tipo da propriedade (Array).
    // 2) "scenes" - nome exibido no Inspector.
    // 3) PROPERTY_HINT_TYPE_STRING - indica que o quarto parâmetro é uma hint string.
    // 4) hint string - descreve o tipo de elemento do Array. Aqui usamos:
    //    String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PackedScene"
    //    que significa: cada item é um Resource do tipo PackedScene.
    // As funções registradas a seguir são: setter "set_scenes" e getter "get_scenes".
    ADD_PROPERTY(
    PropertyInfo(
        Variant::ARRAY,
        "scenes",
        PROPERTY_HINT_TYPE_STRING,
        String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PackedScene"
    ), "set_scenes", "get_scenes");
}

GDExample::GDExample() {
	// Inicialização das variáveis
    time_passed = 0.0;
    // Seed para seleção aleatória de cenas
    std::srand((unsigned)std::time(nullptr));
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

// Retorna a lista atual de cenas exportada no Inspector
Array GDExample::get_scenes() const {
    return scenes;
}

// Define a lista de cenas (cada elemento deve ser um PackedScene)
void GDExample::set_scenes(Array p_scenes) {
    scenes = p_scenes;
}

// Retorna uma cena aleatória da lista `scenes` ou um Ref vazio se não houver cenas
Ref<PackedScene> GDExample::get_random_dungeon() {
    Ref<PackedScene> empty_ref;
    if (scenes.is_empty()) {
        return empty_ref;
    }

    int count = scenes.size();
    int idx = (count > 1) ? (std::rand() % count) : 0;

    // Tentativa de conversão direta para Ref<PackedScene>
    Variant v = scenes[idx];
    Ref<PackedScene> ps = v;
    return ps;
}

// Implementação do Getter
int GDExample::get_variavel_do_export() const {
    return variavel_do_export;
}

// Implementação do Setter
void GDExample::set_variavel_do_export(int p_variavel_do_export) {
    variavel_do_export = p_variavel_do_export;
}