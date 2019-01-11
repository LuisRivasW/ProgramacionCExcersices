#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "relaciones.h"


int main()
{
    nodo *lnp = crearNodo("Oscar");
    atributo *ap = crearAtributo("edad", "21" );
    atributo *lp = NULL;
    insertarAtributo(&lnp->ap, &ap);
    ap = crearAtributo("sexo", "M" );
    insertarAtributo(&lnp->ap, &ap);
    nodo * np = crearNodo("Winche");
    insertarNodo( &lnp, &np);
    ap = crearAtributo("edad", "21" );
    lp = NULL;
    insertarAtributoEnNodo(&lnp, "Winche", &ap);
    ap = crearAtributo("sexo", "M" );
    insertarAtributoEnNodo(&lnp, "Winche", &ap);
    imprimirNodo(lnp);
    printf("%s,%s\n",obtenerNodo(lnp,"Oscar")->nombre, obtenerNodo(lnp ,"Winche")->nombre);

   relaciones *lrp = crearRelacion("amigo", obtenerNodo(lnp,"Oscar"), obtenerNodo(lnp ,"Winche"));

   imprimirRelacion(lrp);


    

    // printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
    // imprimir(np);
    // insertarFinal(&lp, &np);
    // np = crearAtributo("Maria", "21");
    // insertarFinal(&lp, &np);
    // imprimir(lp);
    // imprimir(np);
    // // eliminarAtributo(&lp);
    
}
// Nodo [ atributos, atributos, ], [ Relaciones]
// Atributos [ nombre: valor ]
// Relaciones [ Nodo1 -> Nodo 2]
// X [ y: z, y: z, y: z] & [ Y, W, P, Q]
// Y [ w: z, w: z]
// Winch [ nombre: valor, edad: valor, sexo: valor ]
