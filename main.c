#include <stdio.h>
#include <stdlib.h>
#include "api/GraphLib.h"

int main()
{

    Grafo *G = NULL;

    G = iniciarGrafo(G);

    char *tipoConexao = "D";
    char *caminhoArquivo = "testes/input.txt";
    int *caminhoMinimo = NULL;


    G = lerArquivo(G, caminhoArquivo, tipoConexao);

    caminhoMinimo =  dijkstra(G, 1, 6);

    for(int i = 0; caminhoMinimo[i] != -1; i++){

        printf("%d ",caminhoMinimo[i]);
        
    }printf("\n");

    printf("quantidade de vertices: %d\n", G->quantidadeVertices);
    

    liberarGrafo(G);
}