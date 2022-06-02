arquivo = open("Corona_genomic.fasta")
texto = arquivo.read()

mRNA = ""
for i in texto:
    if i=="A": mRNA += "U"
    elif i=="G": mRNA += "C"
    elif i=="T": mRNA += "A"
    elif i=="C": mRNA += "G"

print("mRNA = ", mRNA)