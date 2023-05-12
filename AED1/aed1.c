#include "aed1.h"

//*********************************************************************************************************************************************************************************************
//*********************************************************************************************************************************************************************************************
//LISTAS

/**
 * @brief Instancia uma lista
 * 
 * @return Lista* 
 */
Lista* criaLista(){
    
    Lista* p = (Lista*) malloc(sizeof(Lista));
    if(p == NULL) exit(1);

    p->num_elementos=0;
    p->inicio=NULL;
    p->fim= NULL;

    return p;
}

/**
 * @brief Instancia um nó
 * 
 * @param valor 
 * @return No* 
 */
No* criaNo(double valor){
    No* n = (No*)malloc(sizeof(No));
    if(n==NULL) exit(0);

    n->anterior=NULL;
    n->prox=NULL;
    n->valor = valor;

    return n;
}

/**
 * @brief Insere um nó no começo da lista
 * 
 * @param list 
 * @param valor 
 */
void insereInicioLista(Lista* lista, double valor){
    No* n = criaNo(valor);

    if(lista->num_elementos == 0){
        lista->inicio = n;
        lista->fim = n;
        
    }else{
        lista->inicio->anterior = n;
        n->prox = lista->inicio;
        lista->inicio = n;
    }

    lista->num_elementos++;
}

/**
 * @brief Insere um nó no final da lista
 * 
 * @param list 
 * @param valor 
 */
void insereFinalLista(Lista* lista, double valor){
    No* n = criaNo(valor);

    if(lista->num_elementos == 0){
        lista->inicio = n;
        lista->fim = n;
        
    }else{
        lista->fim->prox = n;
        n->anterior = lista->fim;
        lista->fim = n;
    }

    lista->num_elementos++;
}

/**
 * @brief Remove um nó do começo da lista
 * 
 * @param list 
 * @return double 
 */
double removeInicioLista(Lista* lista){
    if(lista->num_elementos == 0)exit(1);
    
    double valor = lista->inicio->valor;
    No* aux = lista->inicio;
    
    if(lista->num_elementos == 1){        
        
        lista->inicio = NULL;
        lista->fim = NULL;
        
    }else{
        lista->inicio = lista->inicio->prox;
        lista->inicio->anterior = NULL;
    }
    
    free(aux);
    lista->num_elementos--;
    return valor; 
}

/**
 * @brief Remove um nó do final da lista
 * 
 * @param list 
 * @return double 
 */
double removeFinalLista(Lista* lista){
    if(lista->num_elementos == 0)exit(1);
    
    double valor = lista->fim->valor;
    No* aux = lista->fim;
    
    if(lista->num_elementos == 1){        
        
        lista->inicio = NULL;
        lista->fim = NULL;
        
    }else{
        lista->fim = lista->fim->anterior;
        lista->fim->prox = NULL;
    }
    
    free(aux);
    lista->num_elementos--;
    return valor; 

}

/**
 * @brief Libera a lista da memoria
 * 
 * @param list 
 */
void liberaLista(Lista* lista){
    No* aux = lista->inicio;
    
    if(lista->num_elementos == 0){
        free(lista);
        return;
    }

	while (aux->prox != NULL) {
        aux = aux->prox;
        free(aux->anterior);
	}
    free(aux);
	free(lista);

}

/**
 * @brief Imprime a lista
 * 
 * @param list 
 */
void printLista(Lista* lista){
    No* aux = lista->inicio;
    
    while(aux != NULL){
        printf("%lf ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void insereOrdemCrescente(Lista* lista ,double valor){
    No* n = criaNo(valor);
    if(lista->num_elementos == 0){
        lista->inicio = n;
        lista->fim = n;
    }else{
        if(lista->inicio->valor > valor){
            n->prox = lista->inicio;
            lista->inicio->anterior = n;
            lista->inicio = n;
        }else if(lista->fim->valor < valor){
            n->anterior = lista->fim;
            lista->fim->prox = n;
            lista->fim = n;
        }else{
            No* aux = lista->inicio->prox;
            while(aux->valor < valor){
                aux = aux->prox;
            }
            n->prox = aux;
            n->anterior = aux->anterior;
            
            n->anterior->prox = n;
            n->prox->anterior = n; 
        }


    }    

    lista->num_elementos++;
}

//*********************************************************************************************************************************************************************************************
//*********************************************************************************************************************************************************************************************
//PILHA

/**
 * @brief Cria uma pilha
 * 
 * @return Pilha* 
 */
Pilha* criaPilha(){
    Pilha* p = (Pilha *)malloc(sizeof(Pilha));
    if(p == NULL)exit(1);

    p->inicio = NULL;
    p->fim = NULL;
    p->num_elementos = 0;

    return p;
}

/**
 * @brief Insere um no na pilha
 * 
 * @param pilha 
 * @param valor 
 */
void inserePilha(Pilha* pilha, double valor){
     No* n = criaNo(valor);

    if(pilha->num_elementos == 0){
        pilha->inicio = n;
        pilha->fim = n;
        
    }else{
        pilha->inicio->anterior = n;
        n->prox = pilha->inicio;
        pilha->inicio = n;
    }

    pilha->num_elementos++;
}

/**
 * @brief Remove um no da pilha
 * 
 * @param pilha 
 * @return double 
 */
double removePilha(Pilha* pilha){
    if(pilha->num_elementos == 0)exit(1);
    
    double valor = pilha->inicio->valor;
    No* aux = pilha->inicio;
    
    if(pilha->num_elementos == 1){        
        
        pilha->inicio = NULL;
        pilha->fim = NULL;
        
    }else{
        pilha->inicio = pilha->inicio->prox;
        pilha->inicio->anterior = NULL;
    }
    
    free(aux);
    pilha->num_elementos--;
    return valor;
}

/**
 * @brief Libera a pilha da memoria
 * 
 * @param pilha 
 */
void liberaPilha(Pilha* pilha){
    No* aux = pilha->inicio;
    
    if(pilha->num_elementos == 0){
        free(pilha);
        return;
    }

	while (aux->prox != NULL) {
        aux = aux->prox;
        free(aux->anterior);
	}
    free(aux);
	free(pilha);
}

/**
 * @brief Imprime a pilha
 * 
 * @param list 
 */
void printPilha(Pilha* pilha){
    No* aux = pilha->inicio;
    
    while(aux != NULL){
        printf("%lf ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

//****************************************************************************************************************************************************************************
//****************************************************************************************************************************************************************************
//Fila

/**
 * @brief Cria uma fila
 * 
 * @return Fila* 
 */
Fila* criaFila(){
    Fila* p = (Fila *)malloc(sizeof(Fila));
    if(p == NULL)exit(1);

    p->inicio = NULL;
    p->fim = NULL;
    p->num_elementos = 0;

    return p;
}

/**
 * @brief 
 * 
 * @param fila 
 * @param valor 
 */
void insereFila(Fila* fila, double valor){
    No* n = criaNo(valor);

    if(fila->num_elementos == 0){
        fila->inicio = n;
        fila->fim = n;
        
    }else{
        fila->fim->prox = n;
        n->anterior = fila->fim;
        fila->fim = n;
    }

    fila->num_elementos++;
}

/**
 * @brief Remove elemento da fila
 * 
 * @param fila 
 * @return double 
 */
double removeFila(Fila* fila){
    if(fila->num_elementos == 0)exit(1);
    
    double valor = fila->inicio->valor;
    No* aux = fila->inicio;
    
    if(fila->num_elementos == 1){        
        
        fila->inicio = NULL;
        fila->fim = NULL;
        
    }else{
        fila->inicio = fila->inicio->prox;
        fila->inicio->anterior = NULL;
    }
    
    free(aux);
    fila->num_elementos--;
    return valor; 
}

/**
 * @brief Printa a fila
 * 
 * @param fila 
 */
void printFila(Fila* fila){
    No* aux = fila->inicio;
    
    while(aux != NULL){
        printf("%lf ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

/**
 * @brief Libera a memoria da fila
 * 
 * @param fila 
 */
void liberaFila(Fila* fila){
    No* aux = fila->inicio;
    
    if(fila->num_elementos == 0){
        free(fila);
        return;
    }

	while (aux->prox != NULL) {
        aux = aux->prox;
        free(aux->anterior);
	}
    free(aux);
	free(fila);
}




