#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo
{
    int value;
    struct nodo *direita = NULL;
    struct nodo *esquerda = NULL;
};

void insercao(struct nodo **, int);

void imprimir(struct nodo **);

void deletar(struct nodo **, int);

int main()
{
    struct nodo *inicio = NULL;
    insercao(&inicio, 5);
    insercao(&inicio, 3);
    insercao(&inicio, 2);
    insercao(&inicio, 4);
    insercao(&inicio, 7);
    insercao(&inicio, 6);
    insercao(&inicio, 8);
    insercao(&inicio, 1);
    imprimir(&inicio);
    return 0;
}

void insercao(struct nodo **inicio, int value)
{
    struct nodo *aux = *inicio;
    struct nodo *novo_no = (nodo *)malloc(sizeof(nodo));
    novo_no->value = value;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    if (*inicio == NULL)
    {
        *inicio = novo_no;
        cout << "Arvore criada,first value: " << novo_no->value << endl;
        return;
    }
    else
    {
        // Verificar se o valor adicionado eh menor que o valor
        if (value < aux->value)
        {
            // Verificar se ha algum elemento a esquerda
            if (aux->esquerda == NULL)
            {
                aux->esquerda = novo_no;
                printf("Valor %d adicionado ah esquerda do valor %d\n", value, aux->value);
                return;
                // Recursao ate achar uma posicao disponivel ah esquerda
            }
            else
            {
                insercao(&(aux->esquerda), value);
                return;
            }
            // Verificar se o valor adicionado eh maior que o valoe
        }
        else if (value > aux->value)
        {
            // Verificar se ah valor ah direita
            if (aux->direita == NULL)
            {
                aux->direita = novo_no;
                printf("Valor %d adicionado ah direita do valor %d\n", value, aux->value);
                return;
            }
            else
            {
                // Recursao ate achar uma posicao disponivel ah esquerda
                insercao(&(aux->direita), value);
                return;
            }
        }
    }
}

void imprimir(struct nodo **inicio)
{
    struct nodo *aux = *inicio;
    // Verificar se a lista eh nula
    if (*inicio == NULL)
    {
        return;
    }
    // Recursividade para imprimir todos os valores que sao menores que o nodo
    imprimir(&(aux->esquerda));
    printf("%d\n", aux->value);
    // Recursividade para imprimir todos os valores que sao maiores que o nodo
    imprimir(&(aux->direita));
}
// TODO Fazer script para deletar valor da Arvore
void deletar(struct nodo **inicio, int value)
{
}