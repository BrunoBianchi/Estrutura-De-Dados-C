#include <iostream>
#include <stdlib.h>
using namespace std;
struct No
{
    int value;
    struct No *prox;
    struct No *ant;
};
typedef No no;

no *Lista;

void inserir(int);
int main()
{

    return 0;
}

void inserir(int value)
{
    no *aux = (no *)malloc(sizeof(no));
    if (Lista == NULL)
    {
        aux->value = value;
        aux->prox = aux;
        aux->ant = aux;
        Lista = aux;
    }
    else
    {
        no *aux2 = (no *)malloc(sizeof(no));
        no *aux = Lista;
        while (aux)
        {
            if (value > aux->value && aux == Lista)
            {
                aux2->value = value;
                aux->prox = aux2;
                aux2->ant = aux;
                aux2->prox = aux;
            }
            else if (value < aux->value && aux == Lista)
            {
                aux2->prox = aux;
                aux->ant = aux2;
                aux2->ant = aux;
                aux->prox = aux->prox;

            }
            aux = aux->prox;
        }
    }
}