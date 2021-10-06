#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *izq;
    struct nodo *der;
}arbol;

arbol *crear(int dato);
void agregar(arbol *a,int dato);
void recorrerpreorden(arbol *a);
void recorrerinorden(arbol *a);
void recorrerpostorden(arbol *a);
void contarnodos(arbol *a,int *cont);

int main()
{
    arbol *raiz=crear(10);
    agregar(raiz,5);
    agregar(raiz,15);
    recorrerpreorden(raiz);

    system("pause");
}

arbol *crear(int dato)
{
    arbol *nuevo=(arbol*)malloc(sizeof(arbol));
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
}
void agregar(arbol *a,int dato)
{
    if(dato > a->dato)
    {
        if(a->der)
        {
            agregar(a->der,dato);
        }
        else
        {
            arbol *nuevo=crear(dato);
            a->der=nuevo;
        }
    }
    if(dato < a->dato)
    {
        if(a->izq)
        {
            agregar(a->izq,dato);
        }
        else
        {
            arbol *nuevo=crear(dato);
            a->izq=nuevo;
        }
    }
}
void recorrerpreorden(arbol *a)
{
    if(a)
    {
        printf("%d \n",a->dato);
        recorrerpreorden(a->izq);
        recorrerpreorden(a->der);
    }
}
void recorrerinorden(arbol *a)
{
    if(a)
    {
        recorrerinorden(a->izq);
        printf("%d \n",a->dato);
        recorrerinorden(a->der);
    }
}
void recorrerpostorden(arbol *a)
{
    if(a)
    {
        recorrerpostorden(a->izq);
        recorrerpostorden(a->der);
        printf("%d \n",a->dato);
    }
}
void contarnodos(arbol *a,int *cont)
{
    if(a)
    {
        (*cont)++;
        contarnodos(a->izq,cont);
        contarnodos(a->der,cont);
    }
}
