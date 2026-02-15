# Exemplo de Extensão C++ para Godot

Um projeto minimalista usando GDExtension do Godot com C++.

## Estrutura do Projeto

```
godot-cpp-exemplo/
├── godot-cpp/              # Bindings C++ do Godot
├── src/                    # Arquivos fonte C++
│   ├── GDExample.cpp       # Implementação da classe exemplo
│   ├── GDExample.h         # Cabeçalho da classe exemplo
│   ├── register_types.cpp  # Registro da extensão
│   └── register_types.h
├── projeto-com-cmaismais/  # Projeto Godot
│   └── addons/
│       └── meu-plugin-em-cpp/
│           ├── bin/        # Bibliotecas compiladas
│           └── meu-plugin.gdextension
└── SConstruct              # Configuração de build
```

## Pré-requisitos

- Python 3.6+
- Sistema de build SCons
- Compilador C++ (GCC, Clang ou MSVC)
- Git

## Configuração

1. Clone o repositório com submódulos:
```bash
git clone --recursive <url-do-repositório>
```

Se você já clonou sem `--recursive`:
```bash
git submodule update --init --recursive
```

2. Compile a extensão C++:
```bash
scons
```

Para builds de release:
```bash
scons target=template_release
```

## Uso

A biblioteca compilada será colocada em `projeto-com-cmaismais/addons/meu-plugin-em-cpp/bin/`.

Abra a pasta `projeto-com-cmaismais` no Editor Godot e a GDExtension será carregada automaticamente.

### Classe de Exemplo

A classe `GDExample` estende `Sprite2D` e demonstra:
- Métodos personalizados chamáveis via GDScript
- Propriedades exportadas visíveis no Inspetor
- Integração com o loop de processo

Use no GDScript:
```gdscript
var example = GDExample.new()
example.variavel_do_export = 42
example.minha_funcao()  # Imprime o valor
```

## Desenvolvimento

### Adicionando Novas Classes

1. Crie os arquivos de cabeçalho e implementação em `src/`
2. Registre a classe em `register_types.cpp`:
```cpp
ClassDB::register_class<SuaClasse>();
```
3. Recompile com `scons`

### Opções de Build

- `target=template_debug` ou `target=template_release`
- `platform=linux`, `platform=windows`, `platform=macos`
- `arch=x86_64`, `arch=arm64`, etc.

Exemplo:
```bash
scons platform=linux target=template_release arch=x86_64
```

## Licença

MIT
