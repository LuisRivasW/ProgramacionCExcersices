#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int valor;
    struct Node * sig;
} node;


node * crearNodo( int valor) {
    node * auxp = (node *)malloc(sizeof(node));
    auxp->valor = valor;
    auxp->sig = NULL;
    return auxp;
}


void insertarFinal(node **lp, node **np){
    
    if (*lp == NULL) {
        *lp = *np;
        return;
    }
    node * auxp;
    for(auxp= *lp; auxp->sig != NULL; auxp=auxp->sig);
    auxp->sig = *np;
    return;

}

void imprimir(node *lp) {
    node * auxp;
    for(auxp=lp; auxp != NULL; auxp=auxp->sig)
        printf("%i->", auxp->valor);;
    printf("NULL\n");
}