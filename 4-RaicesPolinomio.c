#include <stdlib.h>
#include <stdio.h>
#include "math.h"

int main () {
    int a,b,c;
    printf("Ingres :a ");
    scanf("%i", &a);
    printf("Ingrese b: ");
    scanf("%i", &b);
    printf("Ingrese c: ");
    scanf("%i",&c);

    printf("%f \n", (-b + sqrt((b*b) - 4*a*c) )/2*a );
    printf("%f \n", (-b - sqrt((b*b) - 4*a*c) )/2*a );
return 0;

}