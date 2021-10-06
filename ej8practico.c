#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo*siguiente;
    struct nodo*anterior;
}tiponodo;

tiponodo* crearnodo(int dato);
void agregarordenado(tiponodo**p,int dato);
void recorrer(tiponodo*p);
void agregar(tiponodo*p,int dato);

int main()
{
    int dato;
    char rta;
    tiponodo*lista;
    lista=crearnodo(0);
    do
    {
        printf("ingrese dato: ");
        scanf("%d",&dato);
        fflush(stdin);
        agregarordenado(&lista,dato);
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
void agregarordenado(tiponodo**p,int dato)
{
    tiponodo*aux=(*p);

    if((*p)->dato > dato)
    {
        agregar((*p),dato);
        (*p)=(*p)->anterior;
    }
    else
    {
        while((dato > aux->dato) && (aux->siguiente !=NULL))
        {
            aux=aux->siguiente;
            if(aux==(*p))
            {
                break;
            }
        }
        agregar(aux,dato);
    }
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
