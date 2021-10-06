#include <stdio.h>
#include <string.h>

typedef struct agenda
{
    int codigo;
    char nombre[50];
    char direccion[50];
    int telefono[];
}tagenda;

void grabar(tagenda *ag);
tagenda* leer();
int strpos(char *c);
void strdato(char *c,char *dato,int pos);
void strresto(char*c,char*dato,int pos);

int main()
{



    system("pause");
}

void grabar(tagenda *ag)
{
    FILE *arc=fopen("agenda.txt","a");
    fprintf(arc,"%d;%s;%s;%d;\n",ag->codigo,ag->nombre,ag->direccion,ag->telefono);
    fclose(arc);
}
tagenda* leer()
{
    FILE *arc=fopen("agenda.txt","r");
    int x=0;
    char *cadena=(char*)malloc(sizeof(char*));
    tagenda *libro=(tagenda*)malloc(sizeof(tagenda));
    fscanf(arc,"%s",cadena);
    while(!feof(arc))
    {
        int pos=strpos(cadena);
        tagenda *contacto=(tagenda*)malloc(sizeof(tagenda));
        char dato[50];
        char resto[250];
        strdato(cadena,dato,pos);
        contacto->codigo=atoi(dato);
        srtrresto(cadena,resto,pos);

        pos=strpos(resto);
        strdato(resto,dato,pos);
        strcpy(contacto->nombre,dato);
        strresto(resto,resto,pos);

        pos=strpos(resto);
        strdato(resto,dato,pos);
        strcpy(contacto->direccion,dato);
        strresto(resto,resto,pos);

        pos=strpos(resto);
        strdato(resto,dato,pos);
        strcpy(contacto->telefono,dato);
        strresto(resto,resto,pos);

        libro[x]=contacto;
        x++;
    }
    return libro;
}
int strpos(char *c)
{
    int x=0;

    while(c[x]!='\0');
    {
        if(c[x]==';')
            return x;
        x++;
    }
    return -1;
}
void strdato(char *c,char *dato,int pos)
{
    int i=0;
    while(i<pos)
    {
        dato[i]=c[i];
        i++;
    }
    dato[i]='\0';
}
void strresto(char*c,char*dato,int pos)
{
    int x=pos++;
    int j=0;
    while(c[x]!='\0')
    {
        dato[j]=c[x];
        j++;
        x++;
    }
    dato[j]='\0';
}
