# Requisito 3 - Cálculo das métricas estatísticas com janela Tkinter

import numpy as np
import pandas as pd
from sklearn.datasets import fetch_california_housing
import tkinter as tk
from tkinter import ttk

# Carregar o dataset da Califórnia
california = fetch_california_housing(as_frame=True)
df = california.frame

# Selecionar as 6 primeiras variáveis solicitadas
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

# ------------------- Criar janela Tkinter -------------------

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