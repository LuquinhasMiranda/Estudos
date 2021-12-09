#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    fstream arquivo;
    arquivo.open("teste.txt", fstream::in);
    if (arquivo) printf("existe\n");
    else printf("nao existe\n");
    
    fstream chunk_file;
    chunk_file.open("teste.txt", std::fstream::out);
    chunk_file << "assda";
    chunk_file.close();

    return 0;
}

