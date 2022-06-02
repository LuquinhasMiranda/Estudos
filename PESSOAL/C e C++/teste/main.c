#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char str1[8], str2[8];
    scanf("%s", str1);
    scanf("%s", str2);

    printf("%s, %s, %d", str1, str2, strcmp(str1, str2));
    return 0;
}