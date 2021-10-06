#include <stdio.h>
#include <string.h>

int main(int argc,char *args[])
{
    if(argc!=3)
    {
        printf("error de argumentos\n");
    }
    else
    {
        FILE *origen=fopen(args[1],"rb");
        FILE *destino=fopen(args[2],"wb");
        char c;
        c=fgetc(origen);
        while(!feof(origen))
        {
            fputc(c,destino);
            c=fgetc(origen);
        }
        fclose(origen);
        fclose(destino);
    }
    system("pause");
}
