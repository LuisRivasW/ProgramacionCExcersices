#include <stdlib.h>
#include <stdio.h>

int main () {
    int a;
    printf("Ingrese el numero");
    scanf("%i", &a);

    int i;
    
    if( a > 2)
        for( i = 2; i < a; i++)
        {
            if ( a % i == 0 ) {
                printf("No es primo");
                return 0;
            }
        }

    printf("Es primo");
    

return 0;

}