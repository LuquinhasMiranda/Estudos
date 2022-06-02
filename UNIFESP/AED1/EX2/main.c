#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[20];
    int prioridade;
    struct no *prox;
} no;

no *CriarLista() {
    no *lista = malloc(sizeof(no));
    lista->prox = NULL;
    return lista;
}

void Adicionar(no *lista, char nome[20], int prioridade) {
    no *p0 = lista->prox;
    no *p1 = lista;
    no *novo = (no*) malloc(sizeof(no));

    while (p0 != NULL) {
        if (strcmp(p0->nome, nome) == 0) return;
        p0 = p0->prox;
    }

    p0 = lista->prox;
    while (p0 != NULL && p0->prioridade <= prioridade) {
        p1 = p0;
        p0 = p0->prox;
    }

    strcpy(novo->nome, nome);
    novo->prioridade = prioridade;
    
    novo->prox = p1->prox;
    p1->prox = novo;
}

void Remover(no *lista, char nome[20]) {
    no *p0 = lista->prox;
    no *p1 = lista;

    while (p0 != NULL) {
        if (strcmp(p0->nome, nome) == 0) {
            if (p0 == NULL) p1->prox = NULL;
            else p1->prox = p0->prox;
             
            free(p0);
            return;
        }
        p1 = p0;
        p0 = p0->prox;
    }
    
}

void ListarELimpar(no *lista) {
    no *p0 = lista->prox;
    no *p1 = p0;
    while (p0 != NULL) {
        p1 = p0;
        p0 = p0->prox;

        printf("%s\n", p1->nome);
        free(p1);
    }
    free(lista);
}

int main () {
    char nome[20];
    int prioridade;

    no* lista = CriarLista();

    while (scanf("%s", nome) && strcmp(nome, "-1") != 0) {
        if (strcmp(nome, "UNIFESPSJC") == 0) {
            scanf("%s", nome);
            Remover(lista, nome);
        }
        else {
            scanf("%d", &prioridade);
            Adicionar(lista, nome, prioridade);
        }
    }

    ListarELimpar(lista);
}