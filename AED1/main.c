#include "aed1.h"

int main(){
    Lista* lista1 = criaLista();

    insereOrdemCrescente(lista1, 3);
    insereOrdemCrescente(lista1, 2);
    insereOrdemCrescente(lista1, 4);
    insereOrdemCrescente(lista1, 10);
    insereOrdemCrescente(lista1, 6);
    insereOrdemCrescente(lista1, 7);
    insereOrdemCrescente(lista1, 5);



    printLista(lista1);
    liberaLista(lista1);
    return 0;
}