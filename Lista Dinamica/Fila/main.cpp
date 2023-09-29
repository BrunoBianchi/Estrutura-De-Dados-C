#include <iostream>
#include <stdlib.h>
using namespace std;

struct Fila
{
    string nome;
    Fila *next;
};

typedef Fila fila;

fila *supermercado;
void inserir(string nome);
void imprimir();
void proximoDaFila();
int main()
{
    inserir("Bruno");
    inserir("Pedro");
    inserir("Ana");
    imprimir();
    proximoDaFila();
    return 0;
}

void inserir(string nome)
{
    fila *pessoa = (fila*) malloc(sizeof(fila));
    fila *aux = supermercado;
    pessoa->nome = nome;
    if(supermercado == NULL) {
        pessoa->next = NULL;
        supermercado = pessoa; 
    }else {
        while(aux->next != NULL) {
            aux =aux->next;
        }
        aux->next = pessoa;
    }
}
void imprimir() {
    fila *aux = supermercado;
    while(aux != NULL) {
        cout<<aux->nome<<"\t";
        aux = aux->next;
    }
}
void proximoDaFila() {
    fila*aux = supermercado;
    cout<<"\n"<<aux->nome<<" eh o proximo da fila"<<endl;
    supermercado = aux->next;
    cout<<"Nova fila: "<<endl;
    imprimir();
}