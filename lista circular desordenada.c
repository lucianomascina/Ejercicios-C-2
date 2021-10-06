#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo*siguiente;
    struct nodo*anterior;
}tiponodo;

tiponodo* crearnodo(int dato);
void agregar(tiponodo*p,int dato);
void recorrer(tiponodo*p);

int main()
{
    int dat;
    char rta;
    tiponodo*lista;
    lista=crearnodo(0);
    do
    {
        printf("ingrese dato: ");
        scanf("%d",&dat);
        agregar(lista,dat);
        fflush(stdin);
        printf("ingrese <s> para salir o cualquier tecla para continuar: ");
        scanf("%c",&rta);
        fflush(stdin);
    }while(rta!='s');
    recorrer(lista);
    system("pause");
}

tiponodo* crearnodo(int dato)
{
    tiponodo*nuevo=(tiponodo*)malloc (sizeof(tiponodo));
    nuevo->dato=dato;
    nuevo->anterior=NULL;
    nuevo->siguiente=NULL;
}
void agregar(tiponodo*p,int dato)
{

    tiponodo*nuevo=crearnodo(dato);

    if(p->anterior==NULL)
    {
        p->siguiente=nuevo;
        nuevo->anterior=p;
        nuevo->siguiente=p;
        p->anterior=nuevo;
    }
    else
    {
        nuevo->anterior=p->anterior;
        tiponodo*anterior=p->anterior;
        anterior->siguiente=nuevo;
        nuevo->siguiente=p;
        p->anterior=nuevo;
    }
}
void recorrer(tiponodo*p)
{
    tiponodo*aux =p;
    do
    {
        printf("%d\n",p->dato);
        p=p->siguiente;
    }while(p!=aux);
}
