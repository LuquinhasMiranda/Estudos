#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Os valores digitados inicialmente sao: %d %d\n", a, b); // a=15, b=20

    a = a* b; // a= 300, b=20
    b = a / b;// a= 300, b= 15
    a= a / b; // a=20, b= 15

    printf("Os valores atuais sao: %d %d", a, b);
}
