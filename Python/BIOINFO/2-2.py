# Lucas Miranda Giannella 159324

s1 = input('string 1:')

s2 = input('string 2:')

s3 = ''
for i in range(0,s2.__len__()):
    if s1.find(s2[i]):
        s3 += s2[i]
print(s3)