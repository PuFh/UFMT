# Requisito 4 - Usando Series (mesma ideia do Requisito 3)

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import fetch_california_housing

# Carregar dataset
california = fetch_california_housing(as_frame=True)
df = california.frame

# Selecionar variáveis
variaveis = ["MedInc", "HouseAge", "AveRooms", "AveBedrms", "Population", "AveOccup"]
dados = df[variaveis]

# ---------------- BoxPlots ----------------
plt.figure(figsize=(14, 8))
for i, var in enumerate(variaveis, 1):
    serie = dados[var]  # <- mesmo conceito do requisito 3
    plt.subplot(2, 3, i)
    sns.boxplot(y=serie, color="skyblue")
    plt.title(f"BoxPlot - {var}")
plt.tight_layout()
plt.show()

# ---------------- Histogramas ----------------
plt.figure(figsize=(14, 8))
for i, var in enumerate(variaveis, 1):
    serie = dados[var]  # <- mesmo conceito do requisito 3
    plt.subplot(2, 3, i)
    sns.histplot(serie, kde=True, bins=30, color="orange")
    plt.title(f"Histograma - {var}")
plt.tight_layout()
plt.show()