import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path
import csv

path1 = Path.home() / '.local/share/godot/app_userdata/Physics_Simulation' / 'posicoesp1PrimeiraIteracao.txt'
path2 = Path.home() / '.local/share/godot/app_userdata/Physics_Simulation' / 'posicoesp2PrimeiraIteracao.txt'
path3 = Path.home() / '.local/share/godot/app_userdata/Physics_Simulation' / 'posicoesp3PrimeiraIteracao.txt'

x_vals = []
y_vals = []
x2_vals = []
y2_vals = []
x3_vals = []
y3_vals = []

with open(path1, newline='') as file:
    reader = csv.reader(file)
    next(reader)  # pula o cabeçalho
    for row in reader:
        if len(row) == 2:
            x_vals.append(float(row[0]))
            y_vals.append(float(row[1]))

plt.plot(x_vals, y_vals, marker='o', color = 'red', markersize = 3, label = "Planeta 1")

with open(path2, newline='') as file:
    reader = csv.reader(file)
    next(reader)  # pula o cabeçalho
    for row in reader:
        if len(row) == 2:
            x2_vals.append(float(row[0]))
            y2_vals.append(float(row[1]))

plt.plot(x2_vals, y2_vals, marker= 'o', color = 'cyan', markersize = 3, label = 'Planeta 2')

with open(path3, newline='') as file:
    reader = csv.reader(file)
    next(reader)  # pula o cabeçalho
    for row in reader:
        if len(row) == 2:
            x3_vals.append(float(row[0]))
            y3_vals.append(float(row[1]))

plt.plot(x3_vals, y3_vals, marker= 'o', color = 'purple', markersize = 3, label = 'Planeta 3')


plt.title("Trajetórias - Todos os Planetas")
plt.xlabel("Posição X")
plt.ylabel("Posição Y")
plt.grid(True)
plt.axis("equal")
plt.legend()
plt.savefig('TrajetóriasPlanetas.png')