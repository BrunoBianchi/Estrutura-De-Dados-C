#include <iostream>
#include <stdlib.h>
using namespace std;
struct ponto
{
    int x = 0;
    int y = 0;
    struct ponto *next;
};

typedef struct ponto Ponto;

Ponto *pontos;


void inserirIndex(int x,int y,int index);
void inserir(int x, int y);
void inserirFinal(int x, int y);

void imprimir(Ponto *pontos);
int length = 0;

int main()
{
    inserir(40, 50);
    inserir(40, 54);
    inserir(41, 50);
    inserirFinal(90, 10);
    inserir(90, 10);
    inserirIndex(99,99,0);
    imprimir(pontos);
    return 0;
}

void imprimir(Ponto *pontos)
{
    if (pontos != NULL)
    {
        cout << "(" << pontos->x << "," << pontos->y << ")"
             << "\t";
        imprimir(pontos->next);
    }
}

void inserir(int x, int y)
{
    Ponto *aux = (Ponto *)malloc(sizeof(Ponto));
    aux->x = x;
    aux->y = y;
    aux->next = pontos;
    pontos = aux;
    length++;
}

void inserirFinal(int x, int y)
{
    length++;
    Ponto *aux = (Ponto *)malloc(sizeof(Ponto));
    aux->x = x;
    aux->y = y;
    aux->next = NULL;
    if(pontos == NULL) {
        pontos = aux;
    }else {
        Ponto *auxiliar = (Ponto *)malloc(sizeof(Ponto));
        auxiliar = pontos;
        while(auxiliar->next!=NULL) {
            auxiliar = auxiliar->next;
        }
        auxiliar->next = aux;
    }
}

void inserirIndex(int x, int y, int index)  {
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    if(index > length) {
        cout<<"posicao invalida!"<<endl;
    }else {
        if(index == 0) {
            p->next = pontos;
            pontos = p;
        }else {
            Ponto *aux = pontos;
            for(int i = 0;i<index-1;i++) {
                aux = aux->next;
            }
            p->next = aux->next;
            aux->next = p;
        }
        length++;
    }
}

