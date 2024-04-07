#include <stdio.h>
#include <stdlib.h>
#include "../../Programa/Headers/GrafoLib.h"
#include "../../Programa/Headers/Arquivos.h"

int liberarMatriz(int **matriz, int totalLinhas){

    if (matriz == NULL) {

        printf("Matriz == NULL\n");
        return 0;

    }

    for(int i = 0; i < totalLinhas; i++){

        free(matriz[i]);

    }

    free(matriz);

    return 1;
}

Grafo *gerarGrafoArquivo(char *caminhoArquivo, int quantidadeVertices)
{

    int **matrizConexoes = NULL;
    int totalConexoes;

    matrizConexoes = lerArquivo(caminhoArquivo);

    totalConexoes = contadorLinha(caminhoArquivo);

    Grafo *grafo = iniciarGrafo(quantidadeVertices);

    grafo->quantidadeVertices = quantidadeVertices;
    grafo->tamanhoGrafo = quantidadeVertices + 1; //Adicionando +1 pois o grafo nao terá nenhum vertice com indentificador 0.

    for (int i = 0; i < totalConexoes; i++)
    {

        adicionarAresta(grafo, matrizConexoes[i][0], matrizConexoes[i][1],matrizConexoes[i][2]);
    }


    liberarMatriz(matrizConexoes, totalConexoes);

    return grafo;
}