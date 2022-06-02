// Murilo Afareli Marchette Costa 12111EQU004

#include <stdio.h>
#include <stdlib.h>

typedef struct horario {
    int hora;
    int minuto;
    int segundo;
};
struct horario vetor[5];

int converter (struct horario hr) {
    return (hr.hora*3600)+(hr.minuto*60)+hr.segundo;
}

int main () {
    for (int i = 0; i < 5; i++) {
        scanf(" %d %d %d", &vetor[i].hora, &vetor[i].minuto, &vetor[i].segundo);
    }
    struct horario maior;
    maior.hora = -1;
    maior.minuto = -1;
    maior.segundo = -1;
    for (int i = 0; i < 5; i++) {
        if (converter(vetor[i]) > converter(maior))
            maior = vetor[i];
    }
    printf("%d %d %d", maior.hora, maior.minuto, maior.segundo);
}

