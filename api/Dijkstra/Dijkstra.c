#include <stdio.h>
#include <stdlib.h>
#include "../GraphLib.h"

int *dijkstra(Grafo *grafo, int verticeSource, int verticeSink)
{

    int tamanhoGrafo = grafo->quantidadeVertices;
    int tamanhoCaminho = 0;
    int custoCaminho = 0;
    int tabelaDistancias[tamanhoGrafo];
    int visitados[tamanhoGrafo];
    int antecessores[tamanhoGrafo];
    int caminho[tamanhoGrafo];
    int verticePai = -1;
    int verticeMenorDistancia = -1;
    int verticeAtual = verticeSource;

    for (int i = 0; i < tamanhoGrafo; i++)
    {

        tabelaDistancias[i] = -1;
        visitados[i] = 0;
        antecessores[i] = -1;
        caminho[i] = -1;
    }

    visitados[verticeAtual] = 1;
    tabelaDistancias[verticeAtual] = 0;

    while (visitados[verticeSink] != 1)
    {

        for (int linha = 0; linha < tamanhoGrafo; linha++)
        {

            if (grafo->matriz[verticeAtual][linha] != 0)
            {

                if (tabelaDistancias[linha] == -1)
                {

                    tabelaDistancias[linha] = tabelaDistancias[verticeAtual] + grafo->matriz[verticeAtual][linha];
                    antecessores[linha] = verticeAtual;
                }
                else if ((tabelaDistancias[verticeAtual] + grafo->matriz[verticeAtual][linha]) < tabelaDistancias[linha])
                {

                    tabelaDistancias[linha] = (tabelaDistancias[verticeAtual] + grafo->matriz[verticeAtual][linha]);
                    antecessores[linha] = verticeAtual;
                }
            }
        }

        // encontra o vertice de menor distancia da tabela de valores
        for (int i = 0; i < tamanhoGrafo; i++)
        {

            if (tabelaDistancias[i] != -1 && visitados[i] == 0)
            {

                if (verticeMenorDistancia == -1)
                {
                    verticeMenorDistancia = i;
                    continue;
                }
                else if (tabelaDistancias[i] < tabelaDistancias[verticeMenorDistancia])
                {

                    verticeMenorDistancia = i;
                }
            }
        }
        verticeAtual = verticeMenorDistancia;
        verticeMenorDistancia = -1;
        visitados[verticeAtual] = 1;
    }

    // encontra o caminho de volta
    verticeAtual = verticeSink;

    caminho[tamanhoCaminho++] = verticeAtual;

    while (verticePai != verticeSource)
    {

        verticePai = antecessores[verticeAtual];

        verticeAtual = verticePai;

        caminho[tamanhoCaminho++] = verticePai;
    }
    

    int *caminhoMinimo = (int *)malloc((tamanhoCaminho + 2) * sizeof(int));

    custoCaminho = tabelaDistancias[verticeSink];

    int tamanhoCaminhoInverso = tamanhoCaminho - 1;

    for (int i = 0; i < tamanhoCaminho; i++)
    {

        caminhoMinimo[i] = caminho[tamanhoCaminhoInverso--];
    }

    caminhoMinimo[tamanhoCaminho] = custoCaminho;
    caminhoMinimo[tamanhoCaminho + 1] = -1;

    return caminhoMinimo;
}