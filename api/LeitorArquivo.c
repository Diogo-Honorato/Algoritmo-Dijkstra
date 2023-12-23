#include <stdio.h>
#include <stdlib.h>
#include "GraphLib.h"

Grafo *lerArquivo(Grafo *grafo,char *caminhoArquivo,char *tipoConexao)
{

    FILE *file;

    int verticeOrigem;
    int verticeDestino;
    int peso;

    file = fopen(caminhoArquivo, "r");

    if(file == NULL)
    {
        printf("\nErro ao abrir o arquivo: %s\n\n",caminhoArquivo);
        exit(0);
    }

    while (fscanf(file, " %d %d %d",&verticeOrigem, &verticeDestino, &peso) == 3)
    {
        grafo = adicionarAresta(grafo,verticeOrigem,verticeDestino,peso,tipoConexao);
    }

    fclose(file);


    return grafo;
}