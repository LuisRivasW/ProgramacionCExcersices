#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
int main () {
    node * np = crearNodo(5), * lp = NULL;
    insertarFinal(&lp, &np);
    np = crearNodo(6);
    insertarInicio(&lp,  &np);
    np = crearNodo(8);
    insertarFinal(&lp,  &np);
    imprimir(lp);

}