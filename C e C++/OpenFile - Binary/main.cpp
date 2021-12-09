#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    fstream arquivo;
    arquivo.open("teste.bin", fstream::in);
    if (arquivo) printf("existe\n");
    else printf("nao existe\n");
    arquivo.close();
    
    int i = 9;
    int j = 13;
    arquivo.open("teste.bin", std::fstream::out | std::fstream::binary);
    arquivo.write(reinterpret_cast<const char *>(&i), sizeof(int));
    arquivo.write(reinterpret_cast<const char *>(&j), sizeof(int));
    arquivo.close();

    int x[2];
    arquivo.open("teste.bin", std::fstream::in | std::fstream::binary);
    arquivo.read(reinterpret_cast<char *>(&x), sizeof(x));
    printf("%d", x[0]);
    printf("%d", x[1]);
    arquivo.close();

    scanf("%d");

    return 0;
}

