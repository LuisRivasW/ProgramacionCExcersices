#include <stdlib.h>
#include <stdio.h>

int main () {
    int a,b,c;
    printf("Ingrese el primer numero");
    scanf("%i", &a);
    printf("Ingrese el segundo numero");
    scanf("%i", &b);
    printf("Ingrese el tercer numero");
    scanf("%i",&c);

    if (a>b && a>c)
        printf("El mayor numero es :%i\n ",a);
    else
        if (b>a && b>c)
            printf("El mayor numero es :%i\n",b);
        else    
            printf("El mayor numero es :%i\n",c);

return 0;

}