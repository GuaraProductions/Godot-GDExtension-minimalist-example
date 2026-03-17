extends Node
class_name ThreadTaskExample

# Exemplo de tarefa executada em uma thread separada no Godot 4.
# A tarefa calcula quantos números primos existem até um limite.

var _thread: Thread
var _resultado: int = -1

func _ready() -> void:
	iniciar_tarefa_em_thread(100000)

func iniciar_tarefa_em_thread(limite: int) -> void:
	if _thread and _thread.is_alive():
		print("Já existe uma thread em execução")
		return

	_thread = Thread.new()

	# Em Godot 4, passamos um Callable para a função da thread.
	# O retorno é um Error (OK quando inicia com sucesso).
	var err: int = _thread.start(_worker_task.bind(limite))
	if err != OK:
		print("Falha ao iniciar thread. Código:", err)
		_thread = null
		return

	print("Thread iniciada para calcular primos até", limite)

# Função executada fora da thread principal.
# IMPORTANTE: evite acessar SceneTree/Nodes diretamente aqui.
func _worker_task(limite: int) -> void:
	var count: int = _contar_primos(limite)
	_resultado = count

	# Para atualizar UI/árvore de cena, volte para a thread principal.
	_on_task_finished.call_deferred(limite, count)

func _on_task_finished(limite: int, count: int) -> void:
	print("Tarefa concluída. Primos até", limite, ":", count)

	# Encerrar e coletar a thread com segurança.
	if _thread and _thread.is_alive():
		_thread.wait_to_finish()

func _exit_tree() -> void:
	# Garante limpeza caso a cena seja fechada durante execução.
	if _thread and _thread.is_alive():
		_thread.wait_to_finish()

func _contar_primos(limite: int) -> int:
	if limite < 2:
		return 0

	var is_prime: Array[bool] = []
	is_prime.resize(limite + 1)
	for i: int in range(limite + 1):
		is_prime[i] = true

	is_prime[0] = false
	is_prime[1] = false

	var p: int = 2
	while p * p <= limite:
		if is_prime[p]:
			var m: int = p * p
			while m <= limite:
				is_prime[m] = false
				m += p
		p += 1

	var total: int = 0
	for n: int in range(2, limite + 1):
		if is_prime[n]:
			total += 1

	return total
