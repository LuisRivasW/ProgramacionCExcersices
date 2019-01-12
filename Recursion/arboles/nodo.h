#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atributos.h"

typedef struct _nodo
{
    char *nombre;
    atributo *ap;
    struct _nodo *next;

} nodo;

/**
 * Crea el nodo y le reserva su espacio de memoria
 * recibe el nombre del atributo y el valor
 */
nodo *crearNodo(char *nombre)
{

    printf("Crear Nodo\n");
    nodo *auxp;
    auxp = (nodo *)malloc(sizeof(nodo));
    printf("Nodo creado\n");
    auxp->nombre = (char *)malloc(sizeof(char));
    auxp->ap = (atributo *)malloc(sizeof(atributo));
    strcpy(auxp->nombre, nombre);
    auxp->ap = NULL;
    auxp->next = NULL;
    return auxp;
}
/**
 *libera el espacio de memoria que se reservara en atributo para asi limpiarla 
 * recibe un doble puntero a atributo
 */
void eliminarNodo(nodo **recibir)
{
    atributo *auxp;
    atributo *lp = (*recibir)->ap;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        auxp = lp->next;
        eliminarAtributo(&lp);
        lp = auxp;
    }
    free((*recibir)->nombre);
    free(*recibir);
}

/**
 * inserta un elemento al final de la lista
 * recibe el elemento que se va a insertar y la lista en la que se va a insertar
 */
void insertarNodo(nodo **lp, nodo **np)
{

    if (*lp == NULL)
    {
        *lp = *np;
        return;
    }
    nodo *auxp;
    for (auxp = *lp; auxp->next != NULL; auxp = auxp->next)
        ;
    auxp->next = *np;
    return;
}
void imprimirNodo(nodo *lp)
{
    nodo *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        printf("%s = {", auxp->nombre);
        imprimirAtributo(auxp->ap);
        printf("} -> ");
    }
    printf("NULL\n");
}

void insertarAtributoEnNodo(nodo **lp, char *nombre, atributo **ap)
{
    nodo *auxp;
    for (auxp = *lp; auxp != NULL; auxp = auxp->next)
    {
        printf("%s == %s ? = %d\n", auxp->nombre, nombre, strcmp(auxp->nombre, nombre) );
        if (strcmp(auxp->nombre, nombre) == 0)
        {
            printf("Creando atributo para nodo %s\n", auxp->nombre);

            insertarAtributo(&auxp->ap, ap);
            return;

        }

    }
    return;
}

nodo * obtenerNodo(nodo *lp, char *nombre)
{
    nodo *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        printf("%s == %s - %d\n", auxp->nombre, nombre, strcmp(auxp->nombre, nombre) );
        if (strcmp(auxp->nombre, nombre) == 0)
        {
            return auxp;
        }

    }
    return NULL;
}
