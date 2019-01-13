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
    relaciones *auxp = NULL;
    auxp = (relaciones *)malloc(sizeof(relaciones));

    auxp->nombre = (char *)malloc(sizeof(char));
    auxp->a = a;
    auxp->b = b;
    strcpy(auxp->nombre, nombre);
    auxp->next = NULL;
    printf("Relacion %s %s %s  creada\n", a->nombre, auxp->nombre, b->nombre);
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
    printf("Imprimiendo relacion\n");
    relaciones *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
        printf("[%s -> %s -> %s] => ", auxp->a->nombre, auxp->nombre, auxp->b->nombre);
    printf("NULL\n");
}

nodo *buscarNodosConRelaciones(relaciones *lp, char *relacionNombre, char *nodoNombre)
{
    printf("Buscando nodos con relacion(%s) = '%s'\n", relacionNombre, nodoNombre);
    nodo *res = NULL;
    relaciones *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        printf("%s =%s? && %s = %s ?\n", auxp->nombre, relacionNombre, auxp->b->nombre, nodoNombre);
        if (strcmp(auxp->nombre, relacionNombre) == 0 && strcmp(auxp->b->nombre, nodoNombre) == 0)
        {
            printf("wBuscando nodos con atributo(%s) = '%s'\n", relacionNombre, nodoNombre);
            nodo *duplicado;
            duplicarNodo(auxp->a, &duplicado);
            insertarNodo(&res, &duplicado);
        }
    }
    return res;
}

nodo *buscarNodosConRelacionesA(relaciones *lp, char *relacionNombre, char *nodoNombre)
{
    // printf("Buscando nodos con relacion(%s) = '%s'\n", relacionNombre, nodoNombre);
    nodo *res = NULL;
    relaciones *auxp;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        // printf("%s =%s? && %s = %s ?\n", auxp->nombre, relacionNombre, auxp->b->nombre, nodoNombre);
        if (strcmp(auxp->nombre, relacionNombre) == 0 && strcmp(auxp->a->nombre, nodoNombre) == 0)
        {
            // printf("wBuscando nodos con atributo(%s) = '%s'\n", relacionNombre, nodoNombre);
            nodo *duplicado;
            duplicarNodo(auxp->b, &duplicado);
            insertarNodo(&res, &duplicado);
        }
    }
    return res;
}

nodo *buscarNodosConRelacionesConRelacionesDeOtroNodo(relaciones *lp, char *relacionNombre, char *nodoNombre, char *relacionNombre2)
{
    printf("Buscando nodos x con relacion(%s) =>  con nodo %s=> %s => y\n", relacionNombre, nodoNombre, relacionNombre2);
    nodo *res = NULL;
    relaciones *auxp;
    nodo *auxNodos = buscarNodosConRelacionesA(lp, relacionNombre2, nodoNombre);
    imprimirNodo(auxNodos);
    nodo *index;
    for (auxp = lp; auxp != NULL; auxp = auxp->next)
    {
        if (strcmp(auxp->nombre, relacionNombre) == 0)
        {
            for (index = auxNodos; index != NULL; index = index->next)
            {
                if (strcmp(auxp->b->nombre, index->nombre) == 0)
                {
                    nodo *duplicado;
                    duplicarNodo(auxp->b, &duplicado);
                    insertarNodo(&res, &duplicado);
                }
            }
        }
    }
    return res;
}