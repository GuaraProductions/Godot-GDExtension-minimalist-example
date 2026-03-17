extends Node
class_name TypingComparisonExample

# Exemplo: Crivo de Eratóstenes com tipagem dinâmica
func sieve_dinamico(limite):
	var inicio_us = Time.get_ticks_usec()

	if limite < 2:
		var fim_us_curto = Time.get_ticks_usec()
		var duracao_us_curto = fim_us_curto - inicio_us
		print("Tempo sieve_dinamico:", duracao_us_curto, "us (", duracao_us_curto / 1000.0, "ms)")
		return []

	var is_prime = []
	for i in range(limite + 1):
		is_prime.append(true)

	is_prime[0] = false
	is_prime[1] = false

	var p = 2
	while p * p <= limite:
		if is_prime[p]:
			var multiplo = p * p
			while multiplo <= limite:
				is_prime[multiplo] = false
				multiplo += p
		p += 1

	var primos = []
	for n in range(2, limite + 1):
		if is_prime[n]:
			primos.append(n)

	var fim_us = Time.get_ticks_usec()
	var duracao_us = fim_us - inicio_us
	print("Tempo sieve_dinamico:", duracao_us, "us (", duracao_us / 1000.0, "ms)")
	return primos

# Exemplo: Crivo de Eratóstenes com tipagem estática
func sieve_estatico(limite: int) -> Array[int]:
	var inicio_us: int = Time.get_ticks_usec()

	if limite < 2:
		var fim_us_curto: int = Time.get_ticks_usec()
		var duracao_us_curto: int = fim_us_curto - inicio_us
		print("Tempo sieve_estatico:", duracao_us_curto, "us (", duracao_us_curto / 1000.0, "ms)")
		return []

	var is_prime: Array[bool] = []
	is_prime.resize(limite + 1)
	for i: int in range(limite + 1):
		is_prime[i] = true

	is_prime[0] = false
	is_prime[1] = false

	var p: int = 2
	while p * p <= limite:
		if is_prime[p]:
			var multiplo: int = p * p
			while multiplo <= limite:
				is_prime[multiplo] = false
				multiplo += p
		p += 1

	var primos: Array[int] = []
	for n: int in range(2, limite + 1):
		if is_prime[n]:
			primos.append(n)

	var fim_us: int = Time.get_ticks_usec()
	var duracao_us: int = fim_us - inicio_us
	print("Tempo sieve_estatico:", duracao_us, "us (", duracao_us / 1000.0, "ms)")
	return primos

func _ready() -> void:
	var limite: int = 50

	var primos_dinamico = sieve_dinamico(limite)
	var primos_estatico: Array[int] = sieve_estatico(limite)

	print("Primos até", limite, "(dinâmico):", primos_dinamico)
	print("Primos até", limite, "(estático):", primos_estatico)
