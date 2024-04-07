#ifndef _FILAPRIORIDADE_
#define _FILAPRIORIDADE_

typedef struct Node{

    int vertice;
    int distancia;

}Node;

typedef struct FilaPrioridade{

    Node *heapArray;
    int *posVerticeHeap;
    int qtdElementos;//representa a quantidade de elementos atual na heap e o proximo indice vazio do heapArray.
    int capacidadeHeap;

}FilaPrioridade;


void liberarFilaPrioridade(FilaPrioridade *FP);

int filaPrioridadeVazia(FilaPrioridade *FP);

void swap(Node *primeiroNode, Node *segundoNode);

Node criarNode(int distancia, int vertice);

FilaPrioridade* criarFilaPrioridade(int capacidadeMaxima);

void filaPrioridadeUP(FilaPrioridade *FP, int indice);

void filaPrioridadeDown(FilaPrioridade *FP, int indice);

void diminuirChave(FilaPrioridade *FP, int novaDistancia, int vertice);

void inserirFilaPrioridade(FilaPrioridade *FP, int distancia, int vertice);

Node removerMin(FilaPrioridade *FP);



#endif