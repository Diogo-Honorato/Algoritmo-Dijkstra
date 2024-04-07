#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Programa/Headers/GrafoLib.h"

Grafo *iniciarGrafo(int totalVertices)
{
    Grafo *grafo = NULL;

    grafo = (Grafo *)malloc(sizeof(Grafo));

    grafo->tamanhoGrafo = totalVertices + 1;

    grafo->quantidadeVertices = totalVertices;

    grafo->matriz = (int **)malloc(grafo->tamanhoGrafo * sizeof(int *));

    for (int i = 0; i < grafo->tamanhoGrafo; i++)
    {

        grafo->matriz[i] = (int *)malloc(grafo->tamanhoGrafo * sizeof(int));
    }

    for (int i = 0; i < grafo->tamanhoGrafo; i++)
    {

        for (int j = 0; j < grafo->tamanhoGrafo; j++)
        {

            grafo->matriz[i][j] = 0;
        }
    }

    return grafo;
}

void liberarGrafo(Grafo *grafo)
{

    for (int i = 0; i < grafo->tamanhoGrafo; i++)
    {

        free(grafo->matriz[i]);
    }
    free(grafo->matriz);

    free(grafo);
}

void adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino, int peso)
{

    grafo->matriz[verticeOrigem][verticeDestino] = peso;
}

void imprimirGrafo(Grafo *grafo)
{
    for (int i = 1; i < grafo->tamanhoGrafo; i++)
    {

        printf("\033[4m    %2d\033[0m", i);
    }
    printf("\n");

    for (int i = 1; i < grafo->tamanhoGrafo; i++)
    {

        printf("%2d| ", i);

        for (int j = 1; j < grafo->tamanhoGrafo; j++)
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

    for (int i = 0; i < grafo->tamanhoGrafo; i++)
    {

        grafo->matriz[vertice][i] = 0;
        grafo->matriz[i][vertice] = 0;
    }

    return grafo;
}

Grafo *inverterArestas(Grafo *grafo)
{

    Grafo *novoGrafo = iniciarGrafo(grafo->quantidadeVertices);

    for (int i = 1; i < grafo->tamanhoGrafo; i++)
    {

        for (int j = 1; j < grafo->tamanhoGrafo; j++)
        {

            if (grafo->matriz[i][j] > 0)
            {

                adicionarAresta(novoGrafo, j, i, grafo->matriz[i][j]);
            }
        }
    }

    return novoGrafo;
}

Grafo *removerAdjacente(Grafo *grafo, int verticeOrigem, int verticeDestino)
{

    grafo->matriz[verticeOrigem][verticeDestino] = 0;

    return grafo;
}

int contarAdjacentes(Grafo *grafo, int vertice)
{
    int arestas = 0;

    for (int i = 1; i < grafo->tamanhoGrafo; i++)
    {
        if (grafo->matriz[vertice][i] != 0)
        {
            arestas++;
        }
    }

    return arestas;
}

Grafo *copiarGrafo(Grafo *grafoOriginal, Grafo *grafoCopia){

    for(int i = 1; i < grafoOriginal->tamanhoGrafo; i++)
    {
        for(int j = 1; j < grafoOriginal->tamanhoGrafo; j++){

            if(grafoOriginal->matriz[i][j] > 0){

                grafoCopia->matriz[i][j] = grafoOriginal->matriz[i][j];

            }
        }
    }

    grafoCopia->quantidadeVertices = grafoOriginal->quantidadeVertices;
    grafoCopia->tamanhoGrafo = grafoOriginal->tamanhoGrafo;

    return grafoCopia;
}