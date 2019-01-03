//Numeros Impares
#include <stdio.h>
#include <stdlib.h>

int sumarPrimos(int num)
{
    if (num == 1)
        return 1;
    else

        return num + sumarPrimos(num - 2);
}

int main(){
        int numero;
        printf("Ingrese el numero tope");
        scanf("%i",&numero);

        printf("%i\n",sumarPrimos(numero));
}
