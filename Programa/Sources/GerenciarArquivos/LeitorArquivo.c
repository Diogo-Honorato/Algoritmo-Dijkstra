#include <stdio.h>
#include <stdlib.h>
#include "../../Programa/Headers/Arquivos.h"


int contadorLinha(const char *caminhoArquivo)
{
    FILE *file;
    int numeroLinhas = 0;
    char verticeOrigem, verticeAdjacente;
    int pesoAresta;


    file = fopen(caminhoArquivo, "r");

    if (file == NULL)
    {
        printf("\nERRO AO ABRIR O ARQUIVO: FUNÇAO: 'contadorLinha'\n\n");
        exit(0);
    }

    while (fscanf(file, " %c %c %d", &verticeOrigem, &verticeAdjacente, &pesoAresta) == 3)
    {
        numeroLinhas++;
    }

    fclose(file);

    return numeroLinhas;
}

int **lerArquivo(const char *caminhoArquivo)
{
    FILE *fileTxt;
    int i = 0;

    int numeroConexoes = contadorLinha(caminhoArquivo);

    int **matrizConexoes = (int **)malloc(numeroConexoes  * sizeof(int *));

    for (int j = 0; j < numeroConexoes; j++)
    {
        matrizConexoes[j] = (int *)malloc(3 * sizeof(int));
    }

    fileTxt = fopen(caminhoArquivo, "r");

    if (fileTxt == NULL)
    {
        printf("\nERRO AO ABRIR O ARQUIVO: FUNÇAO 'arquivoArestas'\n\n");
        exit(0);
    }

    while (fscanf(fileTxt," %d %d %d",&matrizConexoes[i][0],&matrizConexoes[i][1],&matrizConexoes[i][2]) == 3)
    {
        i++;
    }

    fclose(fileTxt);


    return matrizConexoes;
}
