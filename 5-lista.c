#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
int main () {
    node *aux=NULL;
    node *auxlist=NULL;
    node * np = crearNodo(5), * lp = NULL;
    insertarFinal(&lp, &np);
    np = crearNodo(6);
    //imprimir(aux);
    insertarInicio(&lp,  &np);
    np->valor=3;
    np = crearNodo(8);
    insertarFinal(&lp,  &np);
    //imprimir(lp);
    //imprimir(aux);
    //imprimir(head(lp));
    duplicarLista(lp, &auxlist);
    duplicarLista(lp, &auxlist);
    lp->valor = 5;
    imprimir(lp);
    imprimir(auxlist);

}