#include <iostream>

using namespace std;

void busca(int[], int,int,int);

int main()
{
    int lista[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
     int inicio = 0;
     int fim = sizeof(lista)/sizeof(int)-1;
    busca(lista,12,inicio,fim);
}

void busca(int lista[], int value,int inicio,int fim)
{
    int meio = (inicio + fim)/2;
    while(lista[meio] != value) {
        cout<<lista[meio]<<endl;
        if(value>lista[meio]) {
                int inicio = meio + 1;
                busca(lista,value,inicio,fim);
                return;
        }else if(value<lista[meio]) {
                int inicio =  0 ;
                fim = meio -1;
                busca(lista,value,inicio,fim);
                return;                
        }else if(value == lista[meio]) {
            cout<<"Encontrado: "<<value<<endl;
            return;
        }
    }
}