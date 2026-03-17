#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

class ResourceRefExample : public Node {
    GDCLASS(ResourceRefExample, Node)

private:
    Ref<Texture2D> texture_ref;

protected:
    static void _bind_methods();

public:
    void set_texture(Ref<Texture2D> t);
    Ref<Texture2D> get_texture() const;
    void load_and_inspect(String path);
    void demo_ref_behavior();
};

} // namespace godot
