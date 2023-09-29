#include <iostream>
#include <stdlib.h>
using namespace std;
struct Data
{
    int value;
    struct Data *prox;
    struct Data *ant;
};
typedef Data data2;

data2 *lista;
data2 *final;
void inserir(int value);
void imprimirOrdemCrescente();
void imprimirOrdemDecrescente();
int main()
{
     inserir(5);
     inserir(10);
    inserir(15);
    inserir(4);
     inserir(20);
    inserir(4130);
    inserir(25);
    inserir(3);
    inserir(200);
    inserir(19000);
    imprimirOrdemCrescente();
    imprimirOrdemDecrescente();
    return 0;
}

void inserir(int value)
{
    data2 *aux = (data2 *)malloc(sizeof(data2));
    if (lista == NULL)
    {
        aux->value = value;
        aux->prox = NULL;
        aux->ant = NULL;
        lista = aux;
        final = aux;
    }
    else
    {
        aux = lista;
        data2 *aux2 = (data2 *)malloc(sizeof(data2));

        while (aux!= NULL)
        {

            if (value < aux->value && aux->ant == NULL)
            {
                aux2->prox = aux;
                aux2->value = value;
                aux2->ant = NULL;
                aux->ant = aux2;
                lista = aux2;
            
                break;
            }
            else if(value>aux->value && aux->prox == NULL && final == aux) {
                aux2->ant = aux;
                aux2->prox = NULL;
                aux2->value = value;
                
                aux->prox = aux2;
                final = aux2;
            }else if(value>aux->value && aux->prox != NULL && aux->ant != NULL && value<aux->prox->value) {
                aux2->value = value;
                aux2->prox = aux->prox;
                aux2->ant = aux;
                aux->prox = aux2;
            }
            aux = aux->prox;
        }
    }
}

void imprimirOrdemCrescente()
{
    data2 *aux = lista;
    while (aux != NULL)
    {
        cout << aux->value << "\t";
        aux = aux->prox;
    }
    puts("\n");
}

void imprimirOrdemDecrescente()
{
    data2 *aux = lista;
    while (final != NULL)
    {
        cout << final->value << "\t";
        final = final->ant;
    }
    puts("\n");
}