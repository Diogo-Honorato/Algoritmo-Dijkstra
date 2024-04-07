#ifndef _GrafoLib_H_
#define _GrafoLib_H_

typedef struct Grafo
{

    int **matriz;
    int quantidadeVertices;
    int tamanhoGrafo;

} Grafo;


Grafo *iniciarGrafo(int totalVertices);

void liberarGrafo(Grafo *grafo);

void adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino, int peso);

void imprimirGrafo(Grafo *grafo);

Grafo *removerVertice(Grafo *grafo, int vertice);

Grafo *inverterArestas(Grafo *grafo);

Grafo *removerAdjacente(Grafo *grafo, int verticeOrigem, int verticeDestino);

int contarAdjacentes(Grafo *grafo, int vertice);

Grafo *copiarGrafo(Grafo *grafoOriginal, Grafo *grafoCopia);

#endif