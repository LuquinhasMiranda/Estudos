class Vela:
    ativo = 'NULL'
    hora = 'NULL'
    minutagem = 'NULL'
    direcao = 'NULL'

    def __init__(self, ativo, horario, abertura, fechamento):
        self.minutagem = str(horario[3]) + str(horario[4])
        self.hora = str(horario[0]) + str(horario[1])
        self.ativo = ativo
        if abertura>fechamento:
            self.direcao = 'H'
        elif abertura<fechamento:
            self.direcao = 'L'
        else:
            self.direcao = 'N'
    
    def printar(self):
        texto = '\033[95m[' + self.ativo + ']'
        if self.direcao == 'H':
            texto += '\033[92m HIGH'
        elif self.direcao == 'L':
            texto += '\033[91m LOW'
        else:
            texto += '\033[0m NEUTRAL'
        texto += '\033[96m ' + str(self.hora)+ ':' + str(self.minutagem)
        texto += '\033[0m'

        print(texto)

class Estrategia:
    def __init__(self, nome):
        self.nome = nome

    def aplicar(self, gale0, gale1, gale2, erros, holds):
        self.gale0 = gale0
        self.gale1 = gale1
        self.gale2 = gale2
        self.erros = erros
        self.holds = holds
        self.assertividade = erros / (gale0 + gale1 + gale2 + holds)