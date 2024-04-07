#ifndef _ARQUIVOS_H
#define _ARQUIVOS_H
#include "GrafoLib.h"

int contadorLinha(const char *caminhoArquivo);

int **lerArquivo(const char *caminhoArquivo);

Grafo *gerarGrafoArquivo(char *caminhoArquivo, int quantidadeVerices);

int liberarMatriz(int **matriz, int totalLinhas);

#endif