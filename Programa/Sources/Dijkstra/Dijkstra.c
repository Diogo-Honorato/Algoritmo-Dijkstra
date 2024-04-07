#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../Programa/Headers/GrafoLib.h"
#include "../../Programa/Headers/FilaPrioridade.h"
#include "../../Programa/Headers/Dijkstra.h"

#define INF INT_MAX

int *inverterCaminho(int *predecessores, int verticeOrigem, int verticeDestino, int custoCaminho)
{

    int verticeAtual = verticeDestino;

    int *caminhoMinimo;

    int verticePredecessor = 0;

    int numeroElementos = 0;

    while (verticeAtual != verticeOrigem)
    {
        verticeAtual = predecessores[verticeAtual];
        numeroElementos++;
    }

    int *caminhoPredecessores = (int *)malloc(numeroElementos * sizeof(int));

    verticeAtual = verticeDestino;

    for (int i = 0; verticeAtual != verticeOrigem; i++)
    {
        verticePredecessor = predecessores[verticeAtual];

        verticeAtual = verticePredecessor;

        caminhoPredecessores[i] = verticePredecessor;
    }

    int numeroTotalElementos = numeroElementos + 3; // +2 adicionando o verticeDestino no final, custo do caminho e o -1 para indicar o fim do array.

    caminhoMinimo = (int *)malloc(numeroTotalElementos * sizeof(int));

    int indiceUltimoElemento = numeroElementos - 1;

    for (int i = 0; i < numeroTotalElementos; i++)
    {

        caminhoMinimo[i] = caminhoPredecessores[indiceUltimoElemento--];
    }

    caminhoMinimo[numeroElementos] = verticeDestino;
    caminhoMinimo[numeroElementos + 1] = custoCaminho;
    caminhoMinimo[numeroElementos + 2] = -1;


    free(caminhoPredecessores);

    return caminhoMinimo;
}

int *dijkstra(Grafo *grafo, int verticeOrigem, int verticeDestino)
{

    int *tabelaDistancias = (int *)malloc(grafo->tamanhoGrafo * sizeof(int)); // indice começa no 1

    int *visitados = (int *)malloc(grafo->tamanhoGrafo * sizeof(int));//array que impede ciclos.

    int *predecessores = (int *)malloc(grafo->tamanhoGrafo * sizeof(int));//array que armazena os predecessores dos vertices do caminho minimo

    int *caminhoMin;

    FilaPrioridade *FP = criarFilaPrioridade(grafo->quantidadeVertices);

    for (int i = 1; i < grafo->tamanhoGrafo; i++)// i == 1 pois nao existe vertices '0' na matriz adjacente
    {

        tabelaDistancias[i] = INF;

        visitados[i] = 0;

        predecessores[i] = 0;

        //inserindo todos os vertices do grafo na heap.
        inserirFilaPrioridade(FP, tabelaDistancias[i], i);
    }

    tabelaDistancias[verticeOrigem] = 0;

    diminuirChave(FP, 0, verticeOrigem); // alterando a distancia do vertice de origem na fila de prioridade.

    while (1)
    {
        if (filaPrioridadeVazia(FP))//condiçao de parada caso nao encontre o caminho.
        {
            //Caminho nao encontrado
            caminhoMin = NULL;
            printf("Caminho nao encontrado.\n\n");
            return caminhoMin;
        }

        Node verticeAtual = removerMin(FP);//retirando da heap o proximo vertice com o menor custo.

        if (verticeAtual.vertice == verticeDestino)//Condiçao de parada caso encontre o vertice de destino
        {
            visitados[verticeAtual.vertice] = 1;
            break;
        }

        visitados[verticeAtual.vertice] = 1;//marcando com visitado

        for (int i = 1; i < grafo->tamanhoGrafo; i++)
        {
            //verificando seus adjacentes se tem conexao e nao foi visitado antes
            if (grafo->matriz[verticeAtual.vertice][i] > 0 && visitados[i] == 0)
            {

                int pesoAresta = grafo->matriz[verticeAtual.vertice][i];

                if (tabelaDistancias[i] > tabelaDistancias[verticeAtual.vertice] + pesoAresta)
                {

                    tabelaDistancias[i] = tabelaDistancias[verticeAtual.vertice] + pesoAresta;

                    predecessores[i] = verticeAtual.vertice;

                    diminuirChave(FP, tabelaDistancias[i], i);
                }
            }
        }
    }

    //função que faz o caminho de volta para encontrar os antecessores e retorna o caminho minimo com seu custo.
    caminhoMin = inverterCaminho(predecessores, verticeOrigem, verticeDestino, tabelaDistancias[verticeDestino]);

    liberarFilaPrioridade(FP);
    free(predecessores);
    free(tabelaDistancias);
    free(visitados);

    return caminhoMin;
}