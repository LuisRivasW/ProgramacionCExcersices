#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "relaciones.h"
#define clear() printf("\033[H\033[J")

// char * eliminarEspacios(char *texto) {
//     char * buffer = malloc(strlen(texto));
//     char * token = malloc(strlen(texto));
//     token = strtok(buffer, " ");
//     strcpy(buffer, "");
//     while(token != NULL) {
//         printf("%s\n", token);
//         strcat(buffer, token);
//         token = strtok(NULL, token);
//     }
//     printf("%s\n", buffer);
//     free(token);
//     return buffer;
// }

int lector()
{

    int datosCargados = 0;
    char opc[200] = {'1', '\0'};
    char opc2[200] = {'1', '\0'};
    nodo *np = NULL;
    relaciones *lp = NULL;
    while (opc[0] != '3')
    {
        printf("████████████████████████████████████████████████████████████████████████╗\n");
        printf("█                                                                      █║\n");
        printf("█   Porfavor introduzca una opcion valida para procesar su desicion    █║\n");
        printf("█                                                                      █║\n");
        if (datosCargados == 1)
        {

            printf("█               (Datos ya Cargados)                                    █║\n");
        }
        else
        {
            printf("█               (Datos sin cargar)                                     █║\n");
        }
        printf("█                                                                      █║\n");
        printf("█                1.-Leer el archivo de entrada                         █║\n");
        printf("█                2.-Hacer consultas                                    █║\n");
        printf("█                3.-Salir del programa                                 █║\n");
        printf("█                                                                      █║\n");
        printf("████████████████████████████████████████████████████████████████████████║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════╝\n");

        scanf("%s", &opc);
        system("clear");

        if (opc[0] == '2')
        {
            printf("████████████████████████████████████████████████████████████████████████╗\n");
            printf("█                                                                      █║\n");
            printf("█   Porfavor introduzca un modo pregunta valida para procesar su desicion    █║\n");
            printf("█                                                                      █║\n");
            printf("█                                                                      █║\n");
            printf("█                1.- x.atributo == valor?                              █║\n");
            printf("█                2.- x->relacion == nodo?                              █║\n");
            printf("█                3.- x->relacion == nodo->relacion?                    █║\n");
            printf("█                                                                      █║\n");
            printf("████████████████████████████████████████████████████████████████████████║\n");
            printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
            scanf("%s", &opc2);
            if (opc2[0] == '1')
            {
                char *valor = NULL;
                char *nombre = NULL;
                printf("Introduzca el nombre del atributp\n");
                scanf("%s", &nombre);
                printf("Introduzca el valor del atributp\n");
                scanf("%s", &valor);
                imprimirNodo(buscarNodosConAtributo(np, &nombre, &valor));
            }
        }

        if (opc[0] == '1')
        {
            char *nombre, *buffer = NULL;
            int i = 0, size = 0;
            FILE *archivo;

            printf("Introduzca el nombre del archivo\n");
            scanf("%s", &nombre);
            char *ruta;
            ruta = (char *)malloc(sizeof(char));
            strcpy(ruta, "./");
            strcpy(ruta, &nombre);

            archivo = fopen(ruta, "r");
            printf("Archiov abierto\n");
            if (archivo != NULL)
            {
                fseek(archivo, 0, SEEK_END);
                size = ftell(archivo);

                rewind(archivo);

                buffer = malloc((size + 1) * sizeof(*buffer));

                fread(buffer, size, 1, archivo);

                buffer[size] = '\0';

                // printf("%s\n", buffer);

                if (strncmp(buffer, "Nodos\r\n", 7) == 0 || strncmp(buffer, "Nodos\n", 6) == 0)
                {

                    char *buffer2 = malloc(strlen(buffer) * sizeof(buffer2));
                    int modo = 0;
                    char *nombre = malloc(strlen(buffer) * sizeof(buffer2));
                    char *nombreAtributo = malloc(strlen(buffer) * sizeof(buffer2));
                    char *nombreRelacion = malloc(strlen(buffer) * sizeof(buffer2));
                    char *valorAtributo = malloc(strlen(buffer) * sizeof(buffer2));
                    char *a = malloc(strlen(buffer) * sizeof(buffer2));
                    char *b = malloc(strlen(buffer) * sizeof(buffer2));
                    nodo *nodoTemporal = NULL;
                    nodo *aTemporal = NULL;
                    nodo *bTemporal = NULL;
                    atributo *atributoTemporal = NULL;
                    relaciones *relacionTemporal = NULL;

                    strcpy(nombre, "");
                    strcpy(a, "");
                    strcpy(b, "");
                    strcpy(nombreAtributo, "");
                    strcpy(nombreRelacion, "");
                    strcpy(valorAtributo, "");
                    // modos
                    // 0 = buscando nombre de nodo
                    // 1 = buscando nombre de atributo
                    for (i = 4; i < strlen(buffer); i++)
                    {
                        if (!(buffer[i] == '\r' || buffer[i] == '\t' || buffer[i] == ' '))
                        {

                            printf("%c - %d\n", buffer[i], i);
                            switch (modo)
                            {
                            case 0:
                                if (buffer[i] != '\n')
                                {
                                    if (!(buffer[i] < 'A' || buffer[i] > 'Z'))
                                    {
                                        nombre[strlen(nombre)] = buffer[i];
                                    }
                                    else if (buffer[i] == '[')
                                    {
                                        printf("Nodo: %s, creado\n", nombre);
                                        nodoTemporal = crearNodo(nombre);
                                        insertarNodo(&np, &nodoTemporal);
                                        imprimirNodo(np);
                                        nombre = malloc(strlen(buffer) * sizeof(buffer2));
                                        modo = 1;
                                    }
                                }
                                break;
                            case 1:
                                if (buffer[i] != '\n')
                                {
                                    if (!(buffer[i] < 'a' || buffer[i] > 'z') || buffer[i] == '_')
                                    {
                                        nombreAtributo[strlen(nombreAtributo)] = buffer[i];
                                    }
                                    else if (buffer[i] == ':')
                                    {
                                        modo = 2;
                                    }
                                }
                                break;
                            case 2:
                                if (buffer[i] != '\n')
                                {
                                    if (!(buffer[i] < 'a' || buffer[i] > 'z') || buffer[i] == '_')
                                    {
                                        valorAtributo[strlen(valorAtributo)] = buffer[i];
                                    }
                                    else if (buffer[i] == ',')
                                    {
                                        printf("Atributo %s: %s creado\n", nombreAtributo, valorAtributo);
                                        atributoTemporal = crearAtributo(nombreAtributo, valorAtributo);
                                        insertarAtributo(&nodoTemporal->ap, &atributoTemporal);
                                        nombreAtributo = malloc(strlen(buffer) * sizeof(buffer2));
                                        valorAtributo = malloc(strlen(buffer) * sizeof(buffer2));

                                        modo = 1;
                                    }
                                    else if (buffer[i] == ']')
                                    {
                                        printf("Atributo %s: %s creado\n", nombreAtributo, valorAtributo);
                                        atributoTemporal = crearAtributo(nombreAtributo, valorAtributo);
                                        insertarAtributo(&nodoTemporal->ap, &atributoTemporal);
                                        nombreAtributo = malloc(strlen(buffer) * sizeof(buffer2));
                                        valorAtributo = malloc(strlen(buffer) * sizeof(buffer2));
                                        if (buffer[i + 3] == 'R' && buffer[i + 4] == 'e')
                                        {
                                            modo = 3;
                                            i += 12;
                                        }
                                        else
                                        {
                                            modo = 0;
                                        }
                                    }
                                }
                                break;
                            case 3:
                                if (buffer[i] != '\n')
                                {
                                    if (!(buffer[i] < 'A' || buffer[i] > 'Z'))
                                    {
                                        a[strlen(a)] = buffer[i];
                                    }
                                    else if (buffer[i] == '-' && buffer[i + 1] == '>')
                                    {
                                        i++;
                                        printf("A obtenido => %s \n", a);
                                        modo = 4;
                                    }
                                }
                                break;

                            case 4:
                                if (buffer[i] != '\n')
                                {
                                    if (!(buffer[i] < 'a' || buffer[i] > 'z') || buffer[i] == '_')
                                    {
                                        nombreRelacion[strlen(nombreRelacion)] = buffer[i];
                                    }
                                    else if (buffer[i] == '-' && buffer[i + 1] == '>')
                                    {
                                        printf("Relacion => %s \n", nombreRelacion);
                                        i++;
                                        modo = 5;
                                    }
                                }
                                break;
                            case 5:
                                if (!(buffer[i] < 'A' || buffer[i] > 'Z'))
                                {
                                    b[strlen(b)] = buffer[i];
                                }
                                else if (buffer[i] == '\n')
                                {
                                    printf("B obtenido => %s \n", b);
                                    imprimirNodo(np);
                                    aTemporal = obtenerNodo(np, a);
                                    bTemporal = obtenerNodo(np, b);
                                    // imprimirNodo(aTemporal);
                                    relacionTemporal = crearRelacion(nombreRelacion, aTemporal, bTemporal);
                                    insertarRelacion(&lp, &relacionTemporal);
                                    a = malloc(strlen(buffer) * sizeof(buffer2));
                                    b = malloc(strlen(buffer) * sizeof(buffer2));
                                    nombreRelacion = malloc(strlen(buffer) * sizeof(buffer2));

                                    modo = 3;
                                }
                                break;
                            }
                        }
                    }

                    // imprimirNodo(np);
                    // printf("relaciones:\n");
                    // imprimirRelacion(lp);
                    datosCargados = 1;
                }
                // printf("Cabecera nodos correcta\n Obteniendo Nodos ...\n");
                // char * buffer2 = malloc(strlen(buffer) * sizeof(buffer2));
                // strcpy(buffer2, buffer);
                // char *token = strtok(buffer, "\n");
                // char *nodos , *relaciones;
                //  nodos = malloc((size + 1) * sizeof(*nodos));
                //   relaciones = malloc((size + 1) * sizeof(*relaciones));
                //   strcpy(nodos, "");
                //   strcpy(relaciones, "");
                // int modo = 1;
                // while (token != NULL)
                // {

                //     if (strcmp(token, "Nodos\r") == 0)
                //     {
                //         modo = 1;
                //     } else
                //     if (strcmp(token, "Relaciones\r") == 0)
                //     {
                //         modo = 2;
                //     } else
                //     if (modo == 1)
                //     {
                //         strncat(nodos, token, strlen(token) -1);
                //         printf("%s\n", token);
                //     } else
                //     if (modo == 2)
                //     {
                //         strcat(relaciones, " ");
                //         strncat(relaciones, token, strlen(token) -1);
                //          printf("%s\n", token);
                //     }
                //     // printf("%s\n", token);
                //     printf("%d\n", modo);
                //     token = strtok(NULL, "\n");
                // }

                // printf("Nodos:\n%s\n", nodos);
                // printf("Relaciones:\n%s\n", relaciones);
                // printf("%s\n", buffer);
                // printf("%s", eliminarEspacios(buffer2));
            }
            else
            {
                printf("El archivo no se encontro\n");
                printf("Ingrese el nombre correcto del archivo\n");

                sleep(3);
                system("clear");
            }

            // strcat(cad, "\0");
            // printf(cad);
        }

        printf("1\n");
    }
}

// nodo *stringToNodos(char *texto)
// {
// }

// Nodos\n
// nombre[atr:val,atr:val,atr:val]\n
// nombre[atr:val,atr:val,atr:val]\n
// Relaciones\n
// nombre->rel->nombre\n
// nombre->rel->nombre\n