#include <stdio.h>
#include <stdlib.h>
#define tope 100

typedef struct Agenda
{
    int codigo;
    char nombre[50];
    char telefono[50];

}TAgenda;

void inicializa(TAgenda*);
void agregar(TAgenda*A,int pos);
void recorrer(TAgenda*A,int max);
void modificar(TAgenda*A,int n);
TAgenda* buscarxcod(TAgenda*A,int cod,int max);
TAgenda* buscarxnom(TAgenda*A,char *nom,int max);

int main()
{
    int pos=0,op=0,cod=0;
    TAgenda AG[tope];
    char rta='s';
    char nom[50];

    inicializa(AG);



while (rta=='s')
{
    system("cls");
    printf("1-Agregar \n2-Recorrer \n3-Modificar \n4-Buscar por codigo\n5-Buscar por nombre\n");
    scanf("%d",&op);
    fflush(stdin);

    switch (op)
    {
    case 1:
    agregar(AG,pos);
    pos++;
    break;
    case 2:
    recorrer(AG,tope);
    break;
    case 3:
        printf("Modificando elija una posicion: ");
        scanf("%d",&pos);
        fflush(stdin);
        modificar(AG,pos);
        break;
    case 4:
        printf("Ingrese codigo: ");
        scanf("%d",&cod);
        fflush(stdin);

        TAgenda *G=buscarxcod(AG,cod,tope);

        if (G!=NULL)
        {
        printf("Codigo: %d\n",G->codigo);
        printf("Nombre: %s\n",G->nombre);
        printf("Telefono: %s\n",G->telefono);
        }
        else
        {
        printf("No se encontraron datos");
        }
        break;
    case 5:
        printf("Ingrese nombre: ");
        gets(nom);
        TAgenda *N=buscarxnom(AG,&nom,tope);

        if (N!=NULL)
        {
        printf("Codigo: %d\n",N->codigo);
        printf("Nombre: %s\n",N->nombre);
        printf("Telefono: %s\n",N->telefono);
        }
        else
        {
        printf("No se encontraron datos");
        }
        break;
    }
printf("\nDesea elegir otra opcion?? s/n: ");
scanf("%c",&rta);
rta=tolower(rta);
fflush(stdin);

}

}

void inicializa(TAgenda*A)
{
    int i;
    for (i=0;i<tope;i++)
    {
        (A+i)->codigo=0;
        strcpy((A+i)->nombre,"");
        strcpy((A+i)->telefono,"");
    }
}

void agregar(TAgenda*A,int pos)
{
    int c;
    char s[50];
    printf("Codigo: ");
    scanf("%d",&c);
    fflush(stdin);
    (A+pos)->codigo=c;

    printf("Nombre: ");
    gets(s);
    strcpy((A+pos)->nombre,s);

    printf("Telefono: ");
    gets((A+pos)->telefono);

}

void recorrer (TAgenda*A,int max)
{
    int i=0;

    for (i=0;i<max;i++)
    {
        if (A[i].codigo!=0)
        {
        printf("Posicion: -%d-\n",i+1);
        printf("Codigo: %d\n",A[i].codigo);
        printf("Nombre: %s\n",A[i].nombre);
        printf("Telefono %s\n\n",A[i].telefono);
        }
    }
}

void modificar(TAgenda*A,int n)
{
    int c=0;
    char d[50];

    printf ("Ingrese Codigo: ");
    scanf("%d",&c);
    fflush(stdin);
    A[n-1].codigo=c;

    printf("Ingrese Nombre: ");
    gets(d);
    strcpy(A[n-1].nombre,d);

    printf("Ingrese Telefono: ");
    gets(A[n-1].telefono);

}

TAgenda* buscarxcod(TAgenda*A,int cod,int max)
{
    int i=0;
    TAgenda *R=NULL;

    for(i=0;i<max;i++)
    {
        if(cod==(A+i)->codigo)
        {
            R=(A+i);
            return R;

        }
    }
    return R;
}

TAgenda* buscarxnom(TAgenda*A,char *nom,int max)
{
    int i=0;

    TAgenda *P=NULL;

    for(i=0;i<max;i++)
    {
        if(strcmp((A+i)->nombre,nom)==0)
        {

            P=(A+i);
            return P;

        }
    }
    return P;
}
