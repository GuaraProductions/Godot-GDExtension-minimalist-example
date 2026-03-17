#pragma once

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/core/utility_functions.hpp>

namespace godot {

class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

private:
	double time_passed;
	int variavel_do_export;
	// Coleção de cenas (PackedScene) que podem ser configuradas no Inspector
	Array scenes;

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();

	void _process(double delta) override;
    void minha_funcao();

	// Acesso à lista de cenas exportada no Inspector
	Array get_scenes() const;
	void set_scenes(Array p_scenes);

	// Retorna uma cena aleatória da lista `scenes` (pode ser vazia)
	Ref<PackedScene> get_random_dungeon();

    int get_variavel_do_export() const;
    void set_variavel_do_export(int p_variavel_do_export);
};

} // namespace godot