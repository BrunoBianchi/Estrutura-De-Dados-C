#include <iostream>
#include <string.h>
using namespace std;
struct circular
{
    int value;
    struct circular *prox;
};
typedef struct circular Circular;

Circular *Inicio;
Circular *Fim;
void inserir(int);
void imprimir();
void remover(int value);
int main()
{
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(10);
    inserir(9);
    inserir(0);
    inserir(200);
    remover(200);
    remover(0);
    remover(3);
    imprimir();
    return 0;
}

void inserir(int value)
{
    if (Inicio == NULL)
    {
        Circular *aux = (Circular *)malloc(sizeof(Circular));
        aux->value = value;
        aux->prox = aux;
        Fim = aux;
        Inicio = aux;
    }
    else
    {
        Circular *aux = Inicio;
        Circular *aux2 = (Circular *)malloc(sizeof(Circular));
        while (aux)
        {
            if (value > aux->value && aux->prox == Inicio)
            {
                aux2->prox = Inicio;
                aux2->value = value;
                aux->prox = aux2;
                Fim = aux2;
                break;
            }
            else if (value < aux->value && aux == Inicio)
            {
                aux2->prox = aux;
                aux2->value = value;
                Inicio = aux2;
                Fim->prox = aux2;
                break;
            }
            else if (value > aux->value && value < aux->prox->value)
            {
                aux2->value = value;
                aux2->prox = aux->prox;
                aux->prox = aux2;
                break;
            }
            aux = aux->prox;
        }
    }
}

void imprimir()
{
    Circular *aux = Inicio;
    while (aux)
    {
        cout << aux->value << "\t";
        aux = aux->prox;
        if (aux == Inicio)
            puts("\n");
    }
}

void remover(int value)
{
    Circular *aux = Inicio;
    while (aux->prox->value != value)
    {
        aux = aux->prox;
    }
    if (aux->prox == Inicio)
    {
        circular *aux2;
        aux2 = Inicio;
        aux->prox = aux->prox->prox;
        free(aux2);
        Inicio = aux->prox;
    }
    else if (aux->prox == Fim)
    {
        circular *aux2;
        aux2 = Fim;
        free(aux2);
        Fim = aux;
        aux->prox = Inicio;
    }
    else
    {
        circular *aux2;
        aux2 = aux->prox;

        aux->prox = aux->prox->prox;
        free(aux2);
    }
}