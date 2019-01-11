#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define clear() printf("\033[H\033[J")

int lector()
{

    char opc[200] = {'1', '\0'};
    while (opc[0] != '3')
    {
        printf("████████████████████████████████████████████████████████████████████████╗\n");
        printf("█                                                                      █║\n");
        printf("█   Porfavor introduzca una opcion valida para procesar su desicion    █║\n");
        printf("█                                                                      █║\n");
        printf("█                1.-Leer el archivo de entrada                         █║\n");
        printf("█                2.-Resetear archivos generados                        █║\n");
        printf("█                   3.-Salir del programa                              █║\n");
        printf("█                                                                      █║\n");
        printf("████████████████████████████████████████████████████████████████████████║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════╝\n");

        scanf("%s", &opc);
        system("clear");
        if (opc[0] == '2')
        {
            FILE *clasico;
            clasico = fopen("clasico.txt", "w");
            FILE *vertical;
            vertical = fopen("vertical.txt", "w");
            FILE *horizontal;
            horizontal = fopen("horizontal.txt", "w");
            fclose(clasico);
            fclose(horizontal);
            fclose(vertical);
        }

        if (opc[0] == '1')
        {
            char nombre[20], * cad, ojo;
            int i = 0, a = 0, b = 0, control = 0, error = 0, cont = 0, abierta = 0, cerrada = 0, error2, error3 = 0, comas = 0, p = 0, n = 0, j, fila, columna;
            int **matriz;
            FILE *archivo;
            int generaciones = 0, mili = 0;

            control = 0;
            printf("Introduzca el nombre del archivo\n");
            scanf("%s", nombre);
            archivo = fopen(nombre, "r");
            if (archivo != NULL)
            {
                ojo = fgetc(archivo);
                while (ojo != EOF)
                {

                    if ((ojo != ' ') && (ojo != '\t'))
                    {
                         strcat(cad, ojo + "");
                        i++;
                    }
                    ojo = fgetc(archivo);
                }

                strcat(cad, "\0");
                printf(cad);
            }
            else
            {
                printf("El archivo no se encontro\n");
                printf("Ingrese el nombre correcto del archivo\n");
                control = 1;
                sleep(3);
                system("clear");
                return 0;
            }
            printf("1\n");
        }
    }
}