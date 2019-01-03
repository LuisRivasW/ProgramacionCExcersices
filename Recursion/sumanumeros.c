//Sumar numeros naturales
#include <stdio.h>

int sumador(int in, int fi, int res)
{
    if (in <= fi)
        sumador(in + 1, fi, res + in);
    else
        return res;
}

int main()
{
    int inicio, final, resultado, op;

    printf("Ingrese el primer numero\n");
    scanf("%i", &inicio);

    printf("Ingrese el numero final\n");
    scanf("%i", &final);

    printf("%i\n", sumador(inicio, final, resultado));

    return 0;
}