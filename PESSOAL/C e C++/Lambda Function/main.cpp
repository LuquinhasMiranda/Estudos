#include <stdio.h>
#include <stdlib.h>

void(*func)(int);

int main() {
    func = [](int x){ printf("numero printado por uma funcao lambda -> %d", x); };

    int x;
    scanf("%d", &x);
    func(x);
    scanf("%d");
}