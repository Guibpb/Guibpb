print("Sequencia de números primos de 2 até 10000: ")

for i in range (2,10000):
	for x in range (2, i):
		if(i%x == 0):
			naoprimo *= i;
			break
	else:
		print(i)
