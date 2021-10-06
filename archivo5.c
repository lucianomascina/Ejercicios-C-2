#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo=fopen("d:archivo.txt","a");
    char pal[50];
    char rta;

    do
    {
        printf("ingrese : ");
        gets(pal);
        fflush(stdin);
        fprintf(archivo,"%s\n",pal);
        printf("ingrese enter para continuar o s para salir\n");
        scanf("%c",&rta);
        fflush(stdin);
    }while(rta!='s');
    fclose(archivo);
    archivo=fopen("d:archivo.txt","r");
    fscanf(archivo,"%s",pal);
    while(!feof(archivo))
    {
        printf("%s\n",pal);
        fscanf(archivo,"%s",pal);
    }
    fclose(archivo);
    system("pause");
}
