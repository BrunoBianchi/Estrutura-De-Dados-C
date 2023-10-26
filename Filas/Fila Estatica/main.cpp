#include <iostream>
using namespace std;
void push(int fila[], int dado);
void pop(int fila[]);
void print(int fila[]);
class Fila
{
public:
    int Tam = 0;
    int *Fim;
    int fila[];

    Fila(int tam, int fim)
    {

        Tam = tam;
        int ffila[Tam];
        *fila = *ffila;
        int *ffim = &fim;
        Fim = ffim;
    }

public:
    void push(int dado)
    {
        if (*Fim >= (Tam - 1))
        {
            cout << "Fila Cheia!" << endl;
            return;
        }
        else if (*Fim == 0)
        {
            fila[0] = dado;
            (*Fim)++;
        }
        else
        {
            fila[(*Fim)] = dado;
            (*Fim)++;
        }
    }

public:
    void pop()
    {
        if (*Fim <= 0)
        {
            cout << "Lista Vazia!" << endl;
            return;
        }
        int j = 0;
        for (int i = (*Fim) - 1; i >= 0; i--)
        {
            fila[j] = fila[j + 1];
            j++;
        }
        (*Fim)--;
    }

public:
    void imprimir()
    {
        if (*Fim <= 0)
        {
            cout << "Lista Vazia!" << endl;
            return;
        }
        for (int i = 0; i < *Fim; i++)
        {
            cout << fila[i] << "\t ";
        }
    }
};
int main()
{
    Fila fila(10, 0);
    fila.push(8);

    fila.push(7);
    fila.push(10);
    fila.pop();
    fila.pop();
    fila.imprimir();
}
