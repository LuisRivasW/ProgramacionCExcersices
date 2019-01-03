#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atributos.h"
int main()
{

    atributo *np = crearAtributo("nombre", "5");
    atributo *lp = NULL;
    insertarFinal(&lp, &np);
    np = crearAtributo("nombre", "6");
    // printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
    // imprimir(np);
    insertarFinal(&lp, &np);
    np = crearAtributo("nombre", "21");
    insertarFinal(&lp, &np);
    imprimir(lp);
    // imprimir(np);
    // // eliminarAtributo(&lp);
}
// Nodo [ atributos, atributos, ], [ Relaciones]
// Atributos [ nombre: valor ]
// Relaciones [ Nodo1 -> Nodo 2]
// X [ y: z, y: z, y: z] & [ Y, W, P, Q]
// Y [ w: z, w: z]
// Winch [ nombre: valor, edad: valor, sexo: valor ]
