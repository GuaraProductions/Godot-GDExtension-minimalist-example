# Godot C++ Extension Example

A minimalist setup for creating Godot GDExtensions using C++.

## Project Structure

```
godot-cpp-exemplo/
├── godot-cpp/              # Godot C++ bindings
├── src/                    # C++ source files
│   ├── GDExample.cpp       # Example class implementation
│   ├── GDExample.h         # Example class header
│   ├── register_types.cpp  # Extension registration
│   └── register_types.h
├── projeto-com-cmaismais/  # Godot project
│   └── addons/
│       └── meu-plugin-em-cpp/
│           ├── bin/        # Compiled libraries
│           └── meu-plugin.gdextension
└── SConstruct              # Build configuration
```

## Prerequisites

- Python 3.6+
- SCons build system
- C++ compiler (GCC, Clang, or MSVC)
- Git

## Setup

1. Clone the repository with submodules:
```bash
git clone --recursive <repository-url>
```

If you already cloned without `--recursive`:
```bash
git submodule update --init --recursive
```

2. Build the C++ extension:
```bash
scons
```

For release builds:
```bash
scons target=template_release
```

## Usage

The compiled library will be placed in `projeto-com-cmaismais/addons/meu-plugin-em-cpp/bin/`.

Open the `projeto-com-cmaismais` folder in Godot Editor and the GDExtension will be automatically loaded.

### Example Class

The `GDExample` class extends `Sprite2D` and demonstrates:
- Custom methods callable from GDScript
- Exported properties visible in the Inspector
- Process loop integration

Use it in GDScript:
```gdscript
var example = GDExample.new()
example.variavel_do_export = 42
example.minha_funcao()  # Prints the value
```

## Development

### Adding New Classes

1. Create header and implementation files in `src/`
2. Register the class in `register_types.cpp`:
```cpp
ClassDB::register_class<YourClass>();
```
3. Rebuild with `scons`

### Build Options

- `target=template_debug` or `target=template_release`
- `platform=linux`, `platform=windows`, `platform=macos`
- `arch=x86_64`, `arch=arm64`, etc.

Example:
```bash
scons platform=linux target=template_release arch=x86_64
```

## License

MIT
