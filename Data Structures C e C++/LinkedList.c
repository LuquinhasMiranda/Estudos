#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;

int main() {
    Inserir(0,0);
    Inserir(1,-1);
    Inserir(2,-1);
    Inserir(3,-1);
    Inserir(4,-1);
    Imprimir();
    while (1) {
        printf("Inserir: ");
        int num, pos;
        scanf(" %d %d", &num, &pos);
        Inserir(num, pos);
        Imprimir();
    }
}

void Inserir(int input, int target_position) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = input;
    if (target_position == 0) {
        temp->link = head;
        head = temp;
    }
    else if (target_position == -1) {
        temp->link = NULL;
        struct node *editor = head;
        while (editor->link != NULL) editor = editor->link;
        editor->link = temp;
    }
    else {
        struct node *editor = head;
        int count = 0;
        while (count < target_position-1 && editor->link != NULL) {
            editor = editor->link;
            count++;
        }
        struct node *cache = editor;
        editor = editor->link;
        cache->link = temp;
        temp->link = editor;
    }
}

void Deletar(int input, int target_position) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = input;
    if (target_position == 0) {
        temp->link = head;
        head = temp;
    }
    else if (target_position == -1) {
        temp->link = NULL;
        struct node *editor = head;
        while (editor->link != NULL) editor = editor->link;
        editor->link = temp;
    }
    else {
        struct node *editor = head;
        int count = 0;
        while (count < target_position-1 && editor->link != NULL) {
            editor = editor->link;
            count++;
        }
        struct node *cache = editor;
        editor = editor->link;
        cache->link = temp;
        temp->link = editor;
    }
}

void Imprimir() {
    struct node *ponteiro = NULL;
    ponteiro = head;
    while(1) {
        printf("%d ", ponteiro->data);
        if (ponteiro->link == NULL) break;
        ponteiro = ponteiro->link;
    }
    printf("\n");
}
