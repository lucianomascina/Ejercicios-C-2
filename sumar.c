#include <stdio.h>
#include <stdlib.h>

float sumar(int n);

int main()
{
    int num;

    printf("ingrese un numero: ");
    scanf("%d",&num);
    printf("%f\n",sumar(num));
    system("pause");
}

float sumar(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        if(n%2)
        {
            return sumar(n-1)+ 1/(float)n;
        }
        else
        {
            return sumar(n-1) - 1/(float)n;
        }
    }
}
