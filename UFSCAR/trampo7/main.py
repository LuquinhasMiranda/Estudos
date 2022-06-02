def solve(arr): # declaramos uma funcao com def
    arr.sort()
    L = 0
    R = len(arr)-1 # o indice eh zero-based, assim devemos subtrair 1
    while L <= R: # devemos usar loop para comparar varias vezes os indices
        if arr[L] + arr[R] == 42:
            return "sim"
        elif arr[L] + arr[R] > 42: # uma vez que ordenamos a lista em ordem crescente devemos checar se a soma passa
            R -= 1
        else:
            L += 1
            R = len(arr)-1 # resetamos o R para cada incremento em L
    return "nao"
    
n = int(input())
nums_entrada = input().split(' ')
nums = []
for x in nums_entrada:
    nums.append(int(x))
print(solve(nums)) # passamos a lista para a funcao