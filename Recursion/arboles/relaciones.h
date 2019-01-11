#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

typedef struct _rel
{
    char *nombre;
    nodo *a;
    nodo *b;
    struct _rel *next;

} relaciones;

/**
 * Crea el nodo y le reserva su espacio de memoria
 * recibe el nombre del atributo y el valor
 */
relaciones *crearRelacion(char *nombre, nodo *a, nodo *b)
{

    printf("Crear Relacion\n");
    relaciones *auxp;
    auxp = (relaciones *)malloc(sizeof(relaciones));
    printf("Nodo creado\n");
    auxp->nombre = (char *)malloc(sizeof(char));
    auxp->a = a;
    auxp->b = b;
    strcpy(auxp->nombre, nombre);
    auxp->next = NULL;
    return auxp;
}
/**
 *libera el espacio de memoria que se reservara en atributo para asi limpiarla 
 * recibe un doble puntero a atributo
 */
void eliminarRelacion(relaciones **recibir)
{
    free((*recibir)->nombre);
    // free((*recibir)->a);
    // free((*recibir)->b);
    free(*recibir);
}

/**
 * inserta un elemento al final de la lista
 * recibe el elemento que se va a insertar y la lista en la que se va a insertar
 */
void insertarRelacion(relaciones **lp, relaciones **np)
{

    if (*lp == NULL)
    {
        *lp = *np;
        return;
    }
    relaciones *auxp;
    for (auxp = *lp; auxp->next != NULL; auxp = auxp->next)
        ;
    auxp->next = *np;
    return;
}
void imprimirRelacion(relaciones *lp)
{
    relaciones *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
        printf("%s: %s -> %s => ", auxp->nombre, auxp->a->nombre, auxp->b->nombre);
    printf("NULL\n");
}

