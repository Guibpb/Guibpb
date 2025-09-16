import matplotlib.pyplot as plt
import numpy as np  # Para manipulação de posições no eixo x

# Dados
x1 = [1000, 2500, 5000, 10000, 50000]

Insertion = [3,22,96,310,7810]
BinaryInsertion = [3.07,18.06,64.91,224.29,5479.28]
Selection = [5.51,34.75,125.84,458.59,11.32]
Bubble = [8.90,59.56,241.62,1020.14,26611.30]
Heap = [0.51,1.45,3.07,4.87,30.22]
Merge = [0.41,1.14,2.49,4.17,21.72]
Quick = [0.30,0.68,1.42,2.82,18.30]

# Definindo a largura das barras
bar_width = 0.1

# Calculando os deslocamentos para as barras
index = np.arange(len(x1))  # Posições no eixo X para os valores

# Criando o gráfico de barras
plt.bar(index - 2 * bar_width, Insertion, width=bar_width, label="Inserção")
plt.bar(index - bar_width, BinaryInsertion, width=bar_width, label="Inserção Binária")
plt.bar(index, Selection, width=bar_width, label="Seleção")
plt.bar(index + bar_width, Bubble, width=bar_width, label="Bolha")
plt.bar(index + 2 * bar_width, Heap, width=bar_width, label="Heap")
plt.bar(index + 3 * bar_width, Merge, width=bar_width, label="Fusão")
plt.bar(index + 4 * bar_width, Quick, width=bar_width, label="QuickSort")

# Ajustando os eixos e o título
plt.title('Quantidade de Tempo Para Vetores em Ordem Aleatória')
plt.xlabel('Grandeza do Vetor')
plt.ylabel('Tempo (Em Milissegundos)')

# Configurando o eixo Y para escala logarítmica
plt.yscale('log')

# Ajustando os rótulos do eixo x para os valores de x1
plt.xticks(index, x1)

# Exibindo a legenda
plt.legend()

# Salvando o gráfico em um arquivo de imagem
plt.savefig('grafico_tempo_aleatoria.png')
