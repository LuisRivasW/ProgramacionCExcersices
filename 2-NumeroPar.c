#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Ingrese el numero: ");
    scanf("%i",&num);

    if (num%2==0)
        printf("Este numero es par \n");
    else
        if (num%2!=0)
            printf("Este numeros es impar \n");

    return 0;
} 
