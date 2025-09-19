#_*_ coding: utf-8 _*_
import numpy as np
import pandas as pd
from sklearn.datasets import fetch_california_housing

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
        "Média": serie.mean(),
        "Mediana": serie.median(),
        "Moda": serie.mode().iloc[0] if not serie.mode().empty else np.nan,
        "Variância": serie.var(),
        "Desvio Padrão": serie.std(),
        "Quantis (25%, 50%, 75%)": serie.quantile([0.25, 0.5, 0.75]).to_dict(),
        "IQR": serie.quantile(0.75) - serie.quantile(0.25)
    }

# Transformar em DataFrame para visualização
resultados_df = pd.DataFrame(resultados).T

# Exibir resultados
print("Metricas Estatisticas:\n")
print(resultados_df)