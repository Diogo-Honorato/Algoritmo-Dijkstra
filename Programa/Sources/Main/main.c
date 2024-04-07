#include <stdio.h>
#include <stdlib.h>
#include "../../Programa/Headers/Arquivos.h"
#include "../../Programa/Headers/GrafoLib.h"
#include "../../Programa/Headers/FilaPrioridade.h"
#include "../../Programa/Headers/Dijkstra.h"



int main()
{
    //Nao usar vertice com a indetificaçao '0'.
    
    Grafo *G;

    char *caminhoArquivo = "Programa/Inputs/input_1_4V.txt";

    G = gerarGrafoArquivo(caminhoArquivo,4);

    int *caminho;
    int vertiOrigem = 1;
    int verticeDestino = 4;

    //retorna o caminho e o ultimo elemento do caminho eo seu custo
    caminho = dijkstra(G,vertiOrigem,verticeDestino);


    printf("\nEncontrou os caminhos:\n\n");

    for(int i = 0 ; caminho[i + 1] != -1 ;i++){

        printf("%d ",caminho[i]);

        if(caminho[i + 2] == -1){

            printf("\n\ncusto total do caminho: %d",caminho[i]);
        }
        
    }printf("\n\n");

    free(caminho);

    liberarGrafo(G);

    return 0;
}