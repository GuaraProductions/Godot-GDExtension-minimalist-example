#!/bin/sh
printf '\033c\033]0;%s\a' ProjetoComCmaismais
base_path="$(dirname "$(realpath "$0")")"
"$base_path/MeuJogo.x86_64" "$@"
