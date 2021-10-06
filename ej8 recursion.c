#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 6

int palindromo(char *pal,int max,int i);

int main()
{
    char pal[m];

    printf("ingrese palabra: ");
    gets(pal);
    if(palindromo(pal,strlen(pal),0))
        printf("es palindromo");
    else
        printf("no es palindromo");
    system("pause");
}

int palindromo(char *pal,int max,int i)
{
    if (max/2==i)
    {
        return 1;
    }
    else
    {
        if(pal[i]!=pal[(max-1)-i])
            return 0;
        palindromo(pal,max,i+1);
    }
}
