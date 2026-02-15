#pragma once

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

private:
	double time_passed;
    int variavel_do_export;

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();

	void _process(double delta) override;
    void minha_funcao();

    int get_variavel_do_export() const;
    void set_variavel_do_export(int p_variavel_do_export);
};

} // namespace godot