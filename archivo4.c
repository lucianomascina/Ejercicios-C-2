#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo=fopen("d:archivo.txt","a");
    int c;
    char rta;
    do
    {
        printf("ingrese numero: ");
        scanf("%d",&c);
        fflush(stdin);
        fprintf(archivo,"%d\n",c);
        printf("ingrese enter para continuar o s para salir\n");
        scanf("%c",&rta);
        fflush(stdin);
    }while(rta!='s');
    fclose(archivo);
    archivo=fopen("d:archivo.txt","r");
    fscanf(archivo,"%d",&c);
    while(!feof(archivo))
    {
        printf("%d\n",c);
        fscanf(archivo,"%d",&c);
    }
    fclose(archivo);
    system("pause");
}

