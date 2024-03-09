#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphLib.h"

Grafo *iniciarGrafo(Grafo *grafo)
{

    grafo = (Grafo *)malloc(sizeof(Grafo));

    grafo->matriz = (int **)malloc(2 * sizeof(int *));

    for (int i = 0; i < 2; i++)
    {

        grafo->matriz[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)
        {

            grafo->matriz[i][j] = 0;
        }
    }

    grafo->quantidadeVertices = 1;

    return grafo;
}

void liberarGrafo(Grafo *grafo)
{

    for (int i = 0; i < grafo->quantidadeVertices; i++)
    {

        free(grafo->matriz[i]);
    }
    free(grafo->matriz);

    free(grafo);
}

Grafo *alocarNovoGrafo(Grafo *grafo, int numeroVertices)
{
    Grafo *novoGrafo = (Grafo *)malloc(sizeof(Grafo));

    novoGrafo->matriz = (int **)malloc(numeroVertices * sizeof(int *));

    for (int i = 0; i < numeroVertices; i++)
    {
        novoGrafo->matriz[i] = (int *)malloc(numeroVertices * sizeof(int));
    }

    for (int i = 0; i < numeroVertices; i++)
    {
        for (int j = 0; j < numeroVertices; j++)
        {
            novoGrafo->matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < grafo->quantidadeVertices; i++)
    {
        for (int j = 0; j < grafo->quantidadeVertices; j++)
        {
            if (grafo->matriz[i][j] != 0)
            {
                novoGrafo->matriz[i][j] = grafo->matriz[i][j];
            }
        }
    }


    novoGrafo->quantidadeVertices = numeroVertices;

    liberarGrafo(grafo);

    return novoGrafo;
}

Grafo *adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino,int peso, char *tipoConexao)
{

    if (verticeOrigem >= grafo->quantidadeVertices || verticeDestino >= grafo->quantidadeVertices)
    {

        int maior;

        if (verticeOrigem > verticeDestino)
        {

            maior = verticeOrigem;
        }
        else
        {

            maior = verticeDestino;
        }

        grafo = alocarNovoGrafo(grafo, maior + 1);
    }

    if (strcmp(tipoConexao,"D") == 0)
    {

        grafo->matriz[verticeOrigem][verticeDestino] = peso;
    }
    else if (strcmp(tipoConexao,"ND") == 0)
    {

        grafo->matriz[verticeOrigem][verticeDestino] = peso;
        grafo->matriz[verticeDestino][verticeOrigem] = peso;
    }
    else
    {

        perror("\nInsira um tipo de conexao valida\n");
    }

    return grafo;
}

void imprimirGrafo(Grafo *grafo)
{

    int tamanhoMatriz = grafo->quantidadeVertices;

    for (int i = 1; i < tamanhoMatriz; i++)
    {

        printf("\033[4m    %2d\033[0m", i);
    }
    printf("\n");

    for (int i = 1; i < tamanhoMatriz; i++)
    {

        printf("%2d| ", i);

        for (int j = 1; j < tamanhoMatriz; j++)
        {

            if (grafo->matriz[i][j] != 0)
            {

                printf("\033[31m%2d    \033[0m", grafo->matriz[i][j]);
            }
            else
            {

                printf("%2d    ", grafo->matriz[i][j]);
            }
        }

        printf("\n");
    }
}

Grafo *removerVertice(Grafo *grafo, int vertice)
{

    for (int i = 0; i < grafo->quantidadeVertices; i++)
    {

        grafo->matriz[vertice][i] = 0;
        grafo->matriz[i][vertice] = 0;
    }

    return grafo;
}

Grafo *removerAdjacente(Grafo *grafo, int verticeOrigem, int verticeDestino)
{

    grafo->matriz[verticeOrigem][verticeDestino] = 0;

    return grafo;
}