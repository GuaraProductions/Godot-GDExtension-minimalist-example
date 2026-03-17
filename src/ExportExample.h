#pragma once

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/core/utility_functions.hpp>

namespace godot {

class ExportExample : public Sprite2D {
	GDCLASS(ExportExample, Sprite2D)

private:
	// Variáveis que serão expostas/`export` no Inspector
	int exported_int = 42;
	double exported_float = 3.14;
	bool exported_bool = true;
	Vector2 exported_vector2 = Vector2(1, 2);
	NodePath exported_node_path;
	Ref<PackedScene> exported_scene;
	Array exported_scene_list; // Array de PackedScene

protected:
	static void _bind_methods();

public:
	ExportExample();
	~ExportExample();

	// Getters / Setters
	int get_exported_int() const;
	void set_exported_int(int v);

	double get_exported_float() const;
	void set_exported_float(double v);

	bool get_exported_bool() const;
	void set_exported_bool(bool v);

	Vector2 get_exported_vector2() const;
	void set_exported_vector2(Vector2 v);

	NodePath get_exported_node_path() const;
	void set_exported_node_path(NodePath p);

	Ref<PackedScene> get_exported_scene() const;
	void set_exported_scene(Ref<PackedScene> s);

	Array get_exported_scene_list() const;
	void set_exported_scene_list(Array a);
};

} // namespace godot
