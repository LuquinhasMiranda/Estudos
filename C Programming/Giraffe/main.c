#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file_read = fopen("arquivo.txt", "r");
    char line[500];

    fgets(line, 500, file_read);
    printf("%s",line);

    fclose(file_read);
    return 0;
}

void exemplo_fprintf() {
    FILE * file_write = fopen("arquivo.txt", "a");
    fprintf(file_write, "lucas miranda giannella\n");
    fclose(file_write);
}
