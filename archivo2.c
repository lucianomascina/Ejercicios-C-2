#include <stdio.h>
#include <string.h>

int main()
{
    FILE *archivo=fopen("d:archivo.txt","r");
    char car;

    car=fgetc(archivo);
    while(!feof(archivo))
    {
        printf("%c\n",car);
        car=fgetc(archivo);
    }
    fclose(archivo);
    system("pause");
}
