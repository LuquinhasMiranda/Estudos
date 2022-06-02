def solve(matrix, n): 
    dist = 0
    for r in matrix:
        # Cuida das pontas primeiro
        # ponta da esquerda
        i = 0
        while r[i] == 0:
            i += 1
        dist = max(dist, i)
        # ponta da direita
        j = n-1
        while r[j] == 0:
            j -= 1
        dist = max(dist, n-j-1)
        # Agora do meio
        while i < j:
            adv = i + 1
            while r[adv] == 0:
                adv += 1
                
            dist = max(dist, int(((adv-i)-((adv-i)%2))/2) )
            i = adv
    print(dist)

m, n = input().split(' ')
matrix = []
for r in range(int(m)):
    values = input().split(' ')
    matrix.append([int(x) for x in values])
solve(matrix, int(n))