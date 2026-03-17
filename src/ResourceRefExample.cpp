#include "ResourceRefExample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

using namespace godot;

void ResourceRefExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_texture", "t"), &ResourceRefExample::set_texture);
    ClassDB::bind_method(D_METHOD("get_texture"), &ResourceRefExample::get_texture);
    ClassDB::bind_method(D_METHOD("load_and_inspect", "path"), &ResourceRefExample::load_and_inspect);
    ClassDB::bind_method(D_METHOD("demo_ref_behavior"), &ResourceRefExample::demo_ref_behavior);
}

void ResourceRefExample::set_texture(Ref<Texture2D> t) {
    texture_ref = t;
}

Ref<Texture2D> ResourceRefExample::get_texture() const {
    return texture_ref;
}

void ResourceRefExample::load_and_inspect(String path) {
    Ref<Resource> r = ResourceLoader::load(path);
    if (!r.is_valid()) {
        UtilityFunctions::print("load_and_inspect: falha ao carregar:", path);
        return;
    }

    Ref<Texture2D> t = r;
    if (!t.is_valid()) {
        UtilityFunctions::print("load_and_inspect: recurso não é um Texture2D:", path);
        return;
    }

    UtilityFunctions::print("load_and_inspect: textura carregada com sucesso:", path);
    texture_ref = t;
    demo_ref_behavior();
}

void ResourceRefExample::demo_ref_behavior() {
    if (!texture_ref.is_valid()) {
        UtilityFunctions::print("demo_ref_behavior: texture_ref está nulo");
        return;
    }
    Ref<Texture2D> another = texture_ref;
    UtilityFunctions::print("demo_ref_behavior: texture_ref é válido, another é válido");
}
