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
            texto += '\033[92m HIG'
        elif self.direcao == 'L':
            texto += '\033[91m LOW'
        else:
            texto += '\033[0m NEU'
        texto += '\033[96m ' + str(self.hora)+ ':' + str(self.minutagem)
        texto += '\033[0m'

        print(texto)

class Estrategia:
    def __init__(self, nome, ativo):
        self.nome = nome
        self.ativo = ativo

        self.gale0 = 0
        self.gale1 = 0
        self.gale2 = 0
        self.erros = 0
        self.holds = 0

    def aplicar_direcao(self, direcao):
        # X -> NAO ENTRAR
        # H -> ENTRAR HIGHER
        # L -> ENTRAR LOW ER
        self.direcao = direcao

    def printar(self):
        assertividade = self.calc_assertividade()
        if assertividade > 90:
            texto = '\033[96m' + str(assertividade)
        elif assertividade > 80:
            texto = '\033[92m' + str(assertividade)
        elif assertividade > 70:
            texto = '\033[93m' + str(assertividade)
        else:
            texto = '\033[91m' + str(assertividade)

        print('\033[95m[' + self.ativo + ' -> ' + self.nome + '] ASSERT%:' + texto + ' \033[95m W/G1/G2:\033[96m' + str(self.gale0) + '\033[95m|\033[92m' + str(self.gale1) + '\033[95m|\033[93m' + str(self.gale2) + ' \033[95mErros:\033[91m' + str(self.erros) + ' \033[95mHolds:\033[0m' + str(self.holds))

    def calc_assertividade(self):
        ganhos = self.gale0 + self.gale1 + self.gale2
        if ganhos == 0:
            return -1
        else:
            return (ganhos/(ganhos+self.erros)*100)

################### ESTRATEGIAS ###################
class Estrategia_c9(Estrategia):
    def __init__(self, lista_velas):
        Estrategia.__init__(self, 'C9', lista_velas[0].ativo)
        Hs = 0 # QTD VELAS HIGH
        Ls = 0 # QTD VELAS LOW
        Ns = 0 # QTD VELAS NEUTRAS
        Target = 'X'
        Gale = 0
        
        #### ALINHAMENTO DE VELAS ####
        start = False
        for vela in lista_velas:
            if vela.minutagem != '00' and start == False:
                continue
            start = True
            #### COMECO DO CALCULO ####
            if vela.minutagem == '09': # CHAMA A COMPRA
                if Hs > Ls + Ns:
                    Estrategia.aplicar_direcao(self, 'H')
                    Target = 'H'
                    Gale = 0
                    # COMPRA HIGHER
                elif Ls > Hs + Ns:
                    Estrategia.aplicar_direcao(self, 'L')
                    Target = 'L'
                    Gale = 0
                    # COMPRA LOWER
                else:
                    Estrategia.aplicar_direcao(self, 'X')
                    Target = 'X'
                    Gale = -1
                    self.holds += 1
                    # HOLD
                Hs = 0 #
                Ls = 0 # RESET CONTAGEM
                Ns = 0 #
        
            # CHECK WINS #
            if Gale == 0:
                if vela.direcao == Target:
                    self.gale0 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    Gale = 1
            elif Gale == 1:
                if vela.direcao == Target:
                    self.gale1 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    Gale = 2
            elif Gale == 2:
                if vela.direcao == Target:
                    self.gale2 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    self.erros += 1
                    Target = 'X'
                    Gale = -1

            if vela.direcao == 'H':
                Hs += 1
            elif vela.direcao == 'L':
                Ls += 1
            else:
                Ns += 1

class Estrategia_tabelado(Estrategia):
    def __init__(self, lista_velas):
        Estrategia.__init__(self, 'TABELADO', lista_velas[0].ativo)
        ordem = 
        Target = 'X'
        Gale = 0
        
        #### ALINHAMENTO DE VELAS ####
        start = False
        for vela in lista_velas:
            if vela.minutagem != '00' and start == False:
                continue
            start = True
            #### COMECO DO CALCULO ####

            # CHECK WINS #
            if Gale == 0:
                if vela.direcao == Target:
                    self.gale0 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    Gale = 1
            elif Gale == 1:
                if vela.direcao == Target:
                    self.gale1 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    Gale = 2
            elif Gale == 2:
                if vela.direcao == Target:
                    self.gale2 += 1
                    Target = 'X'
                    Gale = -1
                else:
                    self.erros += 1
                    Target = 'X'
                    Gale = -1