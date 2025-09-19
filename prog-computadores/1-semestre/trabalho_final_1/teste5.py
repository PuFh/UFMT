# Requisito 5 - Correlações

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import fetch_california_housing

# Carregar dataset
california = fetch_california_housing(as_frame=True)
df = california.frame

# Selecionar variáveis
variaveis = ["MedInc", "HouseAge", "AveRooms", "AveBedrms", "Population", "AveOccup", "MedHouseVal"]
dados = df[variaveis]

# ---------------- Matriz de Correlação ----------------
corr = dados.corr()

plt.figure(figsize=(10, 6))
sns.heatmap(corr, annot=True, cmap="coolwarm", fmt=".2f", cbar=True)
plt.title("Matriz de Correlação")
plt.show()

# ---------------- Identificar pares mais fortes ----------------
pares = []
for i, var1 in enumerate(variaveis):
    for j, var2 in enumerate(variaveis):
        if i < j:  # evitar repetição
            pares.append((var1, var2, corr.loc[var1, var2]))

# Ordenar pelos maiores valores absolutos
pares_ordenados = sorted(pares, key=lambda x: abs(x[2]), reverse=True)

print("\nTop 5 correlações encontradas:\n")
for p in pares_ordenados[:5]:
    print(f"{p[0]} ↔ {p[1]} = {p[2]:.3f}")