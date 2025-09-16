import matplotlib.pyplot as plt

x1 = [1, 2, 3, 4, 5, 6, 7]
y1 = [12, 28, 60, 124, 252, 508, 1020]
plt.plot(x1, y1, color = "green")

plt.xlabel('Quantidade de Discos')
plt.ylabel('Número de Variáveis Criadas')
plt.title('Gráfico PRÁTICA 3: Recursão - Variáveis')
plt.savefig('Tarefa3TinosRecursãoparte2')