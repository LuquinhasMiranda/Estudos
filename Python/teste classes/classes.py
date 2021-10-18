class Vela:
    def __init__(self, minutagem, abertura, fechamento):
        self.minutagem = minutagem

        if abertura>fechamento:
            self.direcao = 'H'
            
        elif abertura<fechamento:
            self.direcao = 'L'

        else:
            self.direcao = 'N'