# Lucas Miranda Giannella 159324

nome = input('Digite seu nome: ')
peso = int(input('Digite seu peso: '))
altura = float(input('Digite sua altura: '))
imc = peso/(altura**2)

print(nome, ' tem ',peso,' kilos e altura de ',altura,' e portanto o IMC é de ',imc)