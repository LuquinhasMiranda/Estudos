# Leitura do número de partidas
from turtle import pos


N = int(input())

for _ in range (N):
# Leitura das peças 1 e 2
    P1 = [int(i) for i in input().split()]
    P2 = [int(i) for i in input().split()]
    print(P1)
    print(P2)

# Processamento das possibilidades de encaixe
possibilidades = []

altura_P1 = max(P1)
altura_P2 = max(P2)
altura_grade = max(altura_P1, altura_P2)

largura_P1 = len(P1)
largura_P2 = len(P2)
largura_grade = max(largura_P1, largura_P2)

possibilidades = []

for y in range(altura_P2+1):
    for x in range(largura_P2-largura_P1+1):
        a = {}
        pontuacao = []
        a["orientacao"] = "Normal   "
        a["posicao"] = x+1
        a["yOFF"] = y
        for i in range(largura_P1):
            pontuacao.append(altura_grade-y-P1[i]+P2[i+x])
        if min(pontuacao) >= 0:
            a["pontuacao"] = sum(pontuacao)
            possibilidades.append(a)

aux = P1
for i in range(len(P1)):
    P1[i] = aux[i-len(P1)]

for y in range(altura_P2+1):
    for x in range(largura_P2-largura_P1+1):
        a = {}
        pontuacao = []
        a["orientacao"] = "Invertida"
        a["posicao"] = x+1
        a["yOFF"] = y
        for i in range(largura_P1):
            pontuacao.append(altura_grade-y-P1[i]+P2[i+x])
        if min(pontuacao) >= 0:
            a["pontuacao"] = sum(pontuacao)
            possibilidades.append(a)

resultado = possibilidades[0]
for i in possibilidades:
    print(i)
    if i["pontuacao"] < resultado["pontuacao"]:
        resultado = i

P = resultado["pontuacao"]
R = resultado["posicao"]
S = resultado["orientacao"]

# Impressão da saída esperada para cada partida
if P == 0:
    print("Encaixe Perfeito!")
else:
    print("Pontuacao:", P)
print("Posicao de Encaixe:", R)
print("Peca 1:", S)