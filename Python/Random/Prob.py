def parabola_normalizada(d):
    m = (d + 1) / 2
    return [max(-((x - m) / (m - 1))**2 + 1, 0) for x in range(1, d + 1)]

def calcula_prob_total(k, f_vals):
    prob_nao_ocorrer = 1.0
    for f in f_vals:
        p = min(k * f, 1)  # garantir que não ultrapasse 1
        prob_nao_ocorrer *= (1 - p)
    return 1 - prob_nao_ocorrer

def encontra_k(d, T, tol=1e-6, max_iter=100):
    f_vals = parabola_normalizada(d)
    k_min, k_max = 0, 10
    for _ in range(max_iter):
        k = (k_min + k_max) / 2
        prob_total = calcula_prob_total(k, f_vals)
        if abs(prob_total - T) < tol:
            return k, [min(k * f, 1) for f in f_vals]
        if prob_total < T:
            k_min = k
        else:
            k_max = k
    # Retorna melhor aproximação se não convergir completamente
    return k, [min(k * f, 1) for f in f_vals]

# Parâmetros
d = 7
T = 0.9

k, probabilidades = encontra_k(d, T)

print(f"Fator de escala k: {k:.4f}")
print("Probabilidades diárias:")
for i, p in enumerate(probabilidades, 1):
    print(f"Dia {i}: {p:.4f}")

prob_total = calcula_prob_total(k, parabola_normalizada(d))
print(f"Probabilidade total do evento ocorrer em {d} dias: {prob_total:.4f}")
