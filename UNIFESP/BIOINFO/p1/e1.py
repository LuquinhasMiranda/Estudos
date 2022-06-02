lista = []
p1 = 0
p2 = 0
p3 = 0

while (1):
    pessoa = {}
    pessoa["nome"] = input()
    if pessoa["nome"] == "-1":
        break
    pessoa["peso"] = float(input())
    pessoa["altura"] = float(input())

    pessoa["imc"] = pessoa["peso"]/(pessoa["altura"]**2)
    print("--", pessoa["imc"])
    
    if pessoa["imc"] < 25:
        p1 += 1
    elif pessoa["imc"] < 30:
        p2 += 1
    else:
        p3 += 1

    lista.append(pessoa)

print(len(lista), " pessoas cadastradas")

peso_medio = 0
altura_media = 0
imc_medio = 0
for i in lista:
    peso_medio += i["peso"]
    altura_media += i["altura"]
    imc_medio += i["imc"]

peso_medio = peso_medio/len(lista)
altura_media = altura_media/len(lista)
imc_medio = imc_medio/len(lista)

print("Peso medio: ", str(round(peso_medio, 4)))
print("Altura media: ", str(round(altura_media, 2)))
print("Imc medio: ", str(round(imc_medio, 3)))

print("\nPeso normal: ", p1)
print("Sobrepeso: ", p2)
print("Obesidade: ", p3)