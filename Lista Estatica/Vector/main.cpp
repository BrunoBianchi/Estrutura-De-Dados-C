#include <iostream>
#include <stdlib.h>
using namespace std;

void updateVetor(int*vec,int tam,int newVal);

void organizar(int*vec,int tam,int newVal);

void remover(int*vec,int tam,int rVal);

void buscar(int*vec,int val,int tam);

int main() {
    int numero  = 0,tam =  1;
    cin>>numero;
    int *vec = nullptr;
    vec = (int*) malloc(sizeof(int) * 1);
    vec[0] = numero;
    while(numero) {
        cin>>numero;
        if(numero == 0)break;
        tam++;
        updateVetor(vec,tam,numero);
        organizar(vec,tam,numero);
        
    }
         for(int i = 0;i<tam;i++) {
            cout<<vec[i]<<"\t";
        }   
    return 0 ;
}

void updateVetor(int*vec,int tam,int newVal){
    int *aux =  nullptr;
    aux = (int*) malloc(sizeof(int)*tam);
    aux[tam-1] = newVal;
    for(int i = 0;i<tam;i++) {
        if(i>0) {
            aux[i] = vec[i-1];
        }else {
            aux[0] = vec[0];
        }
    }
     vec[tam-1] = newVal;
    vec = (int*)malloc(sizeof(int)*tam);
    for(int i = 0;i<tam;i++) {
        vec[i] = aux[i];
    }
}

void organizar(int*vec,int tam,int newVal) {
    int indexFinal = tam-1;
    for(int i = 0;i<tam;i++) {
        for(int j = 0;j<tam;j++) {
            if(vec[i]<vec[j]) {
                int aux = 0;
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }
}

void buscar(int*vec,int val,int tam) {
    int meio =  (tam-1)/2;
    int inicio = 0;
    int fim = tam-1;
    while(vec[meio] != val) {
        if(vec[meio] > val) {
            inicio = meio+1;
            fim = meio;
            meio = (inicio + fim /2);
            cout<<meio<<endl;
        }else if(vec[meio]<val) {
            inicio =0;
            fim = meio-1;
            meio = (inicio + fim /2);
            cout<<meio<<endl;
        }else  {
            cout<<"valor nao existe!";
        }
    }
    
}

void remover(int*vec,int tam,int rVal) {
    int* aux =  (int*)malloc(sizeof(int) * tam-1);
    for(int i = 0;i<tam;i++) {
        if(vec[i] != rVal) {
            aux[i-1] = vec[i];
        }
    }
    for(int i = 0;i<tam-1;i++) {
        cout<<aux[i]<<"\t";
    }
    vec = (int*)malloc(sizeof(int)*tam-1);
    for(int i = 0;i<tam-1;i++) {
        if(i>0) {
            vec[i-1] = aux[i];
        }        
    }

}