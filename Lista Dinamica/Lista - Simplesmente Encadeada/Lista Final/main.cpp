#include <iostream>
#include <stdlib.h>
using namespace std;

struct data
{
    int value;
    struct data *next;
};
typedef struct data Data;
void inserir(int value);
void imprimir(Data *valores);
void remover(int value);
Data *valores;
int main()
{

    inserir(10);
    inserir(40);
    inserir(50);
    inserir(30);
    inserir(5);
    inserir(4);
    inserir(100);
    inserir(1);
    inserir(65);
    remover(50);
    inserir(70);
    inserir(15);
    imprimir(valores);
    return 0;
}

void inserir(int value)
{
    if (valores == NULL)
    {
        Data *aux = (Data *)malloc(sizeof(Data));
        aux->value = value;
        aux->next = NULL;
        valores = aux;
    }
    else
    {
        // Insercao no meio!
        Data *aux = valores;
        Data *adicionar = (Data *)malloc(sizeof(Data));
        adicionar->value = value;
        adicionar->next = NULL;
        while (aux != NULL)
        {
            if (adicionar->value > aux->value && aux->next == NULL)
            {
                aux->next = adicionar;
            }
            else if (adicionar->value > aux->value && adicionar->value < aux->next->value && aux->next != NULL)
            {
                adicionar->next = aux->next;
                aux->next = adicionar;
            }
            else if (adicionar->value < aux->value && aux->next != NULL && aux == valores)
            {
                adicionar->next = valores;
                valores = adicionar;
            }
            aux = aux->next;
        }
    }
}
void imprimir(Data *valores)
{
    Data *aux = valores;
    while (aux != NULL)
    {
        cout << aux->value << "\t";
        aux = aux->next;
    }
}

void remover(int value)
{
    Data *aux = valores;
    while (aux != NULL)
    {
        if (aux->next->value == value && aux->next != NULL)
        {
            aux->next = aux->next->next;
            break;
        }
        else if (aux->next->value == value && aux->next->next == NULL)
        {
            aux->next = NULL;
        }
        else if (aux->value == value)
        {
            if (aux->next == NULL)
            {
                valores = NULL;
                break;
            }
            else
            {
                valores = aux->next;
                break;
            }
            break;
        }
        else if (aux->next->value != value && aux->next == NULL)
        {
            cout << "valor (" << value << ") nao encontrado!" << endl;
            break;
        }
        aux = aux->next;
    }
}