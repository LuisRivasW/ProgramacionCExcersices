//Digitos
#include <stdio.h>

int digitos(int n)
{
    if (n == 0)
        return (0);
    else
        return ((n % 10) + digitos(n / 10));
}
int main()
{
    int n;
    printf("Introduzca el numero a evaluar");
    scanf("%i", &n);

    printf("%i\n", digitos);

    return 0;
}

// Hola winch