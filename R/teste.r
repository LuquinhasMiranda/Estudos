dist <- as.numeric(readline(prompt="Qual a distancia da viagem em KM: "))
print("Preco: ")
if (dist <= 200) {
    print(dist*0.5)
} else {
    print(dist*0.45)
}