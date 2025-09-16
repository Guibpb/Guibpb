print("Sequencia de números primos de 2 até 50000: ")

lista = []

for i in range (2,50000):
	for x in range (2, i):
		if(i%x == 0):
			break
	else:
		lista.append(i)

print(lista)
