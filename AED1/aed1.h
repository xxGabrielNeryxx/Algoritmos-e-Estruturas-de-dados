#include <stdio.h>
#include <stdlib.h>


//TADS

typedef struct no{
    double valor;
    struct no *prox;
    struct no *anterior;
}No;

typedef struct lista{
    int num_elementos;
    No* inicio;
    No* fim;
}Lista;

typedef struct pilha{
    int num_elementos;
    No* inicio;
    No* fim;
}Pilha;

typedef struct fila{
    int num_elementos;
    No* inicio;
    No* fim;
}Fila;


//LISTA:

Lista* criaLista();
No* criaNo(double valor);
void insereInicioLista(Lista* lista, double valor);
void insereFinalLista(Lista* lista, double valor);
double removeInicioLista(Lista* lista);
double removeFinalLista(Lista* lista);
void liberaLista(Lista* lista);
void printLista(Lista* lista);
void insereOrdemCrescente(Lista* lista ,double valor);

//PILHA:

Pilha* criaPilha();
void inserePilha(Pilha* pilha, double valor);
double removePilha(Pilha* pilha);
void printPilha(Pilha* pilha);
void liberaPilha(Pilha* pilha);

//FILA

Fila* criaFila();
void insereFila(Fila* fila, double valor);
double removeFila(Fila* fila);
void printFila(Fila* fila);
void liberaFila(Fila* fila);

//Lista circular:
