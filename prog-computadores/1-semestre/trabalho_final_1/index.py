import numpy as np
import pandas as pd
import seaborn as sns
import tkinter as tk

import matplotlib.pyplot as plt #bibliteca para geração de gráficos
from sklearn.datasets import fetch_california_housing
from tkinter import ttk

#REQUISITO 1

#Carregamento do conjunto de dados
california = fetch_california_housing(as_frame=True)
df = california.frame
#imprimindo informações do banco de dados
print(df.head())
descricao = df.describe()
print(descricao)

#REQUISITO 3 ---------------------
variaveis = ["MedInc", "HouseAge", "AveRooms", "AveBedrms", "Population", "AveOccup"]
dados = df[variaveis]

# Dicionário para armazenar resultados
resultados = {}
for var in variaveis:
    serie = dados[var]
    resultados[var] = {
        "Media": serie.mean(),
        "Mediana": serie.median(),
        "Moda": serie.mode().iloc[0] if not serie.mode().empty else np.nan,
        "Variancia": serie.var(),
        "Desvio Padrao": serie.std(),
        "Quantil 25%": serie.quantile(0.25),
        "Quantil 50%": serie.quantile(0.50),
        "Quantil 75%": serie.quantile(0.75),
        "IQR": serie.quantile(0.75) - serie.quantile(0.25)
    }

# Converter em DataFrame
resultados_df = pd.DataFrame(resultados).T.reset_index()
resultados_df.rename(columns={"index": "Variavel"}, inplace=True)

# Criar janela Tkinter 

# Criar a janela principal
root = tk.Tk()
root.title("Métricas Estatísticas - Requisito 3")
root.geometry("1000x400")

# Criar tabela Treeview
frame = ttk.Frame(root)
frame.pack(fill="both", expand=True)

cols = list(resultados_df.columns)
tree = ttk.Treeview(frame, columns=cols, show="headings")

# Definir cabeçalhos
for col in cols:
    tree.heading(col, text=col)
    tree.column(col, anchor="center", width=120)

# Inserir os dados na tabela
for _, row in resultados_df.iterrows():
    tree.insert("", "end", values=list(row))

# Scroll horizontal e vertical
scroll_y = ttk.Scrollbar(frame, orient="vertical", command=tree.yview)
scroll_x = ttk.Scrollbar(frame, orient="horizontal", command=tree.xview)
tree.configure(yscroll=scroll_y.set, xscroll=scroll_x.set)

scroll_y.pack(side="right", fill="y")
scroll_x.pack(side="bottom", fill="x")
tree.pack(fill="both", expand=True)

# Rodar a aplicação
root.mainloop()

#REQUISITO 2 -------------------
sns.set_style("whitegrid")
plt.figure(figsize=(10,8))
sns.scatterplot(x='Longitude', y='Latitude', data=df, alpha=0.5)
plt.show()

#REQUISITO 2 -------------------

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

# REQUISITO 5---------------
#  Matriz de Correlação 
corr = dados.corr()

plt.figure(figsize=(10, 6))
sns.heatmap(corr, annot=True, cmap="coolwarm", fmt=".2f", cbar=True)
plt.title("Matriz de Correlação")
plt.show()

#Identificar pares mais fortes 
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
#fim(finalmente)