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
    deletar(&inicio,3);
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
        // Verificar se o value adicionado eh menor que o value
        if (value < aux->value)
        {
            // Verificar se ha algum elemento a esquerda
            if (aux->esquerda == NULL)
            {
                aux->esquerda = novo_no;
                printf("value %d adicionado ah esquerda do value %d\n", value, aux->value);
                return;
                // Recursao ate achar uma posicao disponivel ah esquerda
            }
            else
            {
                insercao(&(aux->esquerda), value);
                return;
            }
            // Verificar se o value adicionado eh maior que o valoe
        }
        else if (value > aux->value)
        {
            // Verificar se ah value ah direita
            if (aux->direita == NULL)
            {
                aux->direita = novo_no;
                printf("value %d adicionado ah direita do value %d\n", value, aux->value);
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
    // Recursividade para imprimir todos os valuees que sao menores que o nodo
    imprimir(&(aux->esquerda));
    printf("%d\n", aux->value);
    // Recursividade para imprimir todos os valuees que sao maiores que o nodo
    imprimir(&(aux->direita));
}

void deletar(struct nodo **inicio, int value)
{
  	struct nodo *filho = *inicio;
	struct nodo *pai;
	do{
		pai = filho;
		if(value < filho->value)
			filho = filho->esquerda;
		else if(value > filho->value)
			filho = filho->direita;	
	}while(filho!=NULL && filho->value != value);

	if(filho != NULL){ // nodo com o value correspondente encontrado
		if(filho->esquerda == NULL && filho->direita == NULL){ // nodo folha
			printf("%d é nodo folha\n",value);
			if(pai->esquerda == filho) pai->esquerda = NULL;
			if(pai->direita == filho) pai->direita = NULL;
		}
		if(filho->esquerda != NULL && filho->direita == NULL){ // nodo com 1 filho a esquerda
			printf("%d tem um filho a esquerda\n",value);
			if(pai->esquerda == filho) pai->esquerda = filho->esquerda;
			if(pai->direita == filho) pai->direita = filho->esquerda;
		}
		if(filho->esquerda == NULL && filho->direita != NULL){ // nodo com 1 filho a direita
			printf("%d tem um filho a direita\n",value);
			if(pai->esquerda == filho) pai->esquerda = filho->direita;
			if(pai->direita == filho) pai->direita = filho->direita;
		}
		if(filho->esquerda != NULL && filho->direita != NULL) // nodo com 2 filhos
		{
			printf("%d tem dois filhos\n",value);
			if(filho->esquerda->direita==NULL){
				filho->value = filho->esquerda->value;
				filho->esquerda = NULL;
			}else{
				struct nodo *p = filho->esquerda;
				struct nodo *aux = p;
				while(p->direita != NULL){
					aux = p;
					p = p->direita;
				}
				aux->direita = NULL;
				filho->value = p->value;
			}
		}
	}
}