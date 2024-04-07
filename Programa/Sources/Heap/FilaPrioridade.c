#include <stdio.h>
#include <stdlib.h>
#include "../../Programa/Headers/FilaPrioridade.h"

void liberarFilaPrioridade(FilaPrioridade *FP)
{

    free(FP->heapArray);
    free(FP->posVerticeHeap);
    free(FP);
}

int filaPrioridadeVazia(FilaPrioridade *FP)
{

    return FP->qtdElementos == 0;
}

void swap(Node *primeiroNode, Node *segundoNode)
{

    Node auxiliar = *primeiroNode;

    *primeiroNode = *segundoNode;

    *segundoNode = auxiliar;
}

Node criarNode(int distancia, int vertice)
{

    Node node;

    node.vertice = vertice;
    node.distancia = distancia;

    return node;
}

FilaPrioridade *criarFilaPrioridade(int capacidadeMaxima)
{

    FilaPrioridade *FP = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));

    FP->heapArray = (Node *)malloc(capacidadeMaxima * sizeof(Node));

    FP->posVerticeHeap = (int *)malloc((capacidadeMaxima + 1) * sizeof(int));//(capacidadeMaxima + 1) pois nao posVerticeHeapsui vertice 0. 

    FP->capacidadeHeap = capacidadeMaxima;

    FP->qtdElementos = 0;

    return FP;
}

void filaPrioridadeUP(FilaPrioridade *FP, int indice)
{

    int nodePai = (indice - 1) / 2;

    while (indice > 0 && FP->heapArray[indice].distancia < FP->heapArray[nodePai].distancia)
    {
        FP->posVerticeHeap[FP->heapArray[indice].vertice] = nodePai;

        FP->posVerticeHeap[FP->heapArray[nodePai].vertice] = indice;

        swap(&FP->heapArray[indice], &FP->heapArray[nodePai]);

        indice = nodePai;

        nodePai = (indice - 1) / 2;
    }
}

void filaPrioridadeDown(FilaPrioridade *FP, int indice)
{
    int menorFilho = indice;

    while (1)
    {
        int filhoDireita = 2 * indice + 2;
        int filhoEsquerda = 2 * indice + 1;

        if (filhoEsquerda < FP->qtdElementos && FP->heapArray[filhoEsquerda].distancia < FP->heapArray[menorFilho].distancia)
        {
            menorFilho = filhoEsquerda;
        }
        if (filhoDireita < FP->qtdElementos && FP->heapArray[filhoDireita].distancia < FP->heapArray[menorFilho].distancia)
        {
            menorFilho = filhoDireita;
        }
        if (menorFilho != indice)
        {
            FP->posVerticeHeap[FP->heapArray[menorFilho].vertice] = indice;
            FP->posVerticeHeap[FP->heapArray[indice].vertice] = menorFilho;
            swap(&FP->heapArray[menorFilho], &FP->heapArray[indice]);
            indice = menorFilho;
        }
        else
        {
            break;
        }
    }
}

void diminuirChave(FilaPrioridade *FP, int novaDistancia, int vertice)
{
    int indice = FP->posVerticeHeap[vertice];

    FP->heapArray[indice].distancia = novaDistancia;

    filaPrioridadeUP(FP, indice);
}

void inserirFilaPrioridade(FilaPrioridade *FP, int distancia, int vertice)
{

    Node novoNode = criarNode(distancia, vertice);

    FP->heapArray[FP->qtdElementos] = novoNode;

    FP->posVerticeHeap[vertice] = FP->qtdElementos;

    FP->qtdElementos++;

    filaPrioridadeUP(FP, FP->qtdElementos - 1);
}

Node removerMin(FilaPrioridade *FP)
{

    Node verticeMaiorPrioridade = FP->heapArray[0];

    FP->posVerticeHeap[FP->heapArray[0].vertice] = FP->qtdElementos - 1;

    FP->posVerticeHeap[FP->heapArray[FP->qtdElementos - 1].vertice] = 0;

    swap(&FP->heapArray[0], &FP->heapArray[FP->qtdElementos - 1]);

    FP->qtdElementos--;

    filaPrioridadeDown(FP, 0);

    return verticeMaiorPrioridade;
}