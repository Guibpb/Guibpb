import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path
import csv

path1 = Path.home() / '.local/share/godot/app_userdata/Physics_Simulation' / 'posicoesp3PrimeiraIteracao.txt'
path2 = Path.home() / '.local/share/godot/app_userdata/Physics_Simulation' / 'posicoesp3SegundaIteracao.txt'

x_vals = []
y_vals = []
x2_vals = []
y2_vals = []

with open(path1, newline='') as file:
    reader = csv.reader(file)
    next(reader)  # pula o cabeçalho
    for row in reader:
        if len(row) == 2:
            x_vals.append(float(row[0]))
            y_vals.append(float(row[1]))

plt.plot(x_vals, y_vals, marker='o', color = 'purple', label = "1ª Trajetória")

with open(path2, newline='') as file:
    reader = csv.reader(file)
    next(reader)  # pula o cabeçalho
    for row in reader:
        if len(row) == 2:
            x2_vals.append(float(row[0]))
            y2_vals.append(float(row[1]))

plt.plot(x2_vals, y2_vals, marker= 'o', color = 'gray', label = '2ª Trajetória')


plt.title("Trajetórias - Planeta 3")
plt.xlabel("Posição X")
plt.ylabel("Posição Y")
plt.grid(True)
plt.axis("equal")
plt.legend()
plt.savefig('TrajetóriasPlaneta3.png')