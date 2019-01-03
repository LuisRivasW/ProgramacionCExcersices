  #include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct _dato
{
    char * nombre;
    char * valor;
    struct _dato *next;

} atributo;

/**
 * Crea el nodo y le reserva su espacio de memoria
 * recibe el nombre del atributo y el valor
 */
atributo *crearAtributo(char * nombre, char * valor)
{

    printf("Crear Atributo\n");
    atributo *auxp;
    auxp= (atributo *)malloc(sizeof(atributo));
    printf("Atributo creado\n");
    auxp->nombre = (char *)malloc(sizeof(char));
    auxp->valor = (char *)malloc(sizeof(char));
    strcpy(auxp->nombre , nombre);
    strcpy(auxp->valor , valor);
    auxp->next = NULL;
    return auxp;
}
/**
 *libera el espacio de memoria que se reservara en atributo para asi limpiarla 
 * recibe un doble puntero a atributo
 */
void eliminarAtributo(atributo **recibir)
{
    free(*recibir);
}

/**
 * inserta un elemento al final de la lista
 * recibe el elemento que se va a insertar y la lista en la que se va a insertar
 */
void insertarFinal(atributo **lp, atributo **np)
{

    if (*lp == NULL)
    {
        *lp = *np;
        return;
    }
    atributo *auxp;
    for (auxp = *lp; auxp->next != NULL; auxp = auxp->next)
        ;
    auxp->next = *np;
    return;
}
void imprimir(atributo *lp) {
    atributo * auxp;
    for(auxp=lp; auxp != NULL; auxp=auxp->next)
        printf("%s: %s -> ", auxp->nombre, auxp->valor);;
    printf("NULL\n");
}

