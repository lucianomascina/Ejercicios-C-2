#include <stdio.h>
#include <stdlib.h>

void recursividad(int n);

int main()
{
    int num;

    printf("ingrese un numero: ");
    scanf("%d",&num);
    recursividad(num);
    system("pause");
}

void recursividad(int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        printf("contando %d\n",n);
        recursividad(n-1);
    }
}
