#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo=fopen("d:archivo.txt","w");
    char car,rta;

    do
    {
        printf("ingrese caracter: ");
        scanf("%c",&car);
        fflush(stdin);
        fputc(car,archivo);
        printf("ingrese enter para continuar o s para salir\n");
        scanf("%c",&rta);
        fflush(stdin);
    }while(rta!='s');
    fclose(archivo);
    system("pause");
}
