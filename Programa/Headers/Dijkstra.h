#ifndef _DIJKSTRA_
#define _DIJKSTRA_
#include "GrafoLib.h"


int *inverterCaminho(int *antecessores, int verticeOrigem, int verticeDestino, int custoCaminho);

int *dijkstra(Grafo *grafo, int verticeOrigem, int verticeDestino);

#endif