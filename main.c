#include <stdio.h>
#include <stdlib.h>
#include "api/GraphLib.h"

int main()
{

    Grafo *G = NULL;

    G = iniciarGrafo(G);

    char *tipoConexao = "ND";
    char *caminhoArquivo = "testes/input.txt";
    int *caminhoMinimo = NULL;


    G = lerArquivo(G, caminhoArquivo, tipoConexao);

    caminhoMinimo =  dijkstra(G, 0, 6);

    for(int i = 0; caminhoMinimo[i] != -1; i++){

        printf("%d ",caminhoMinimo[i]);
        
    }printf("\n");

    liberarGrafo(G);
}