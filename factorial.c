#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main()
{
    int num;

    printf("ingrese un numero: ");
    scanf("%d",&num);
    printf("%d\n",factorial(num));
    system("pause");
}

int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return(n * factorial(n-1));
    }
}
