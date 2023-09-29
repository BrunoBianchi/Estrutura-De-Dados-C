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

void inserir(int x, int y);
void imprimir(Ponto *pontos);

int main()
{
    inserir(40, 50);
    inserir(40, 54);
    inserir(41, 50);
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
}
