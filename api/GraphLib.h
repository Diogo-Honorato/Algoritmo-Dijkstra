#ifndef GraphLib_H
#define GraphLib_H

typedef struct Grafo
{

    int **matriz;
    int quantidadeVertices;

} Grafo;

//MatrizAdjacente.c
Grafo *iniciarGrafo(Grafo *grafo);

void liberarGrafo(Grafo *grafo);

Grafo *alocarNovoGrafo(Grafo *grafo, int numeroVertices);

Grafo *adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino, int peso, char *tipoConexao);

void imprimirGrafo(Grafo *grafo);

Grafo *removerVertice(Grafo *grafo, int vertice);

Grafo *removerAdjacente(Grafo *grafo, int verticeOrigem, int verticeDestino);


//LeitorArquivo.c
Grafo *lerArquivo(Grafo *grafo, char *caminhoArquivo,char *tipoConexao);

//Dijkstra.c
int *dijkstra(Grafo *grafo, int verticeSource, int verticeSink);

#endif

