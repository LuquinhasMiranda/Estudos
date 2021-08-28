#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;

int main() {
    for (int i = 1; i < 50; i++) Insert(i,0);
    Imprimir();
    Delete(0);
    Imprimir();
    Delete(2);
    Imprimir();
    Reverse();
    Imprimir();
}

void Insert(int input, int target_position) {
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
        for (int i = 0; i < target_position-2; i++) if (editor->link != NULL) editor = editor->link;
        struct node *cache = editor;
        editor = editor->link;
        cache->link = temp;
        temp->link = editor;
    }
}

void Delete(int target_position) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (target_position == 0) {
        temp = head;
        head = head->link;
        free(temp);
    }
    else if (target_position == -1) {
        temp->link = NULL;
        struct node *editor = head;
        while (editor->link->link != NULL) editor = editor->link;
        struct node *cache = editor;
        editor = editor->link;
        cache->link = NULL;
        free(editor);
    }
    else {
        struct node *editor = head;
        for (int i = 0; i < target_position-1; i++) {
            if (editor->link != NULL) editor = editor->link;
            else break;
        }
        struct node *cache = editor;
        editor = editor->link;
        cache->link = editor->link;
        free(editor);
    }
}

void Reverse() {
    struct node *temp = head, *temp2 = NULL, *temp3;
    while(temp->link != NULL) {
        temp3 = temp2;
        temp2 = temp;
        temp = temp->link;
        temp2->link = temp3;
    }
    temp2->link = temp3;
    temp->link = temp2;
    head = temp;
}

void Imprimir() {
    printf("\n");
    struct node *ponteiro = NULL;
    ponteiro = head;
    while(1) {
        if (ponteiro == NULL) break;
        printf("%d ", ponteiro->data);
        ponteiro = ponteiro->link;
    }
}
