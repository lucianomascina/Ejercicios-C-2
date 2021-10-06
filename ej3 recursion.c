#include <stdio.h>
#include <stdlib.h>
#define max 5

int contar(int vec[],int valor,int i);

int main ()
{
    int i,b;
    int vec[max];

    for(i=0;i<max;i++)
    {
        printf("ingrese numero: ");
        scanf("%d",&vec[i]);
        fflush(stdin);
    }
    printf("ingrese numero a buscar: ");
    scanf("%d",&b);
    fflush(stdin);
    printf("aparece %d veces \n",contar(vec,b,max-1));
    system("pause");
}

int contar(int vec[],int valor,int i)
{
   if(i !=-1)
   {
       int x=0;
       if(vec[i]==valor)
        x=1;
       return (x + contar(vec,valor,i-1));
   }
   return 0;
}
