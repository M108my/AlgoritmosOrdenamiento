#include<iostream>
using namespace std;

void bubbleSort(int arr[], int tam){
    long contador = 0;
    bool intercambio;

    for(int i=0; i<tam-1; i++){
        intercambio = false;

        for(int j=0; j<tam-1; j++){
            contador++;
            if(arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){
            break;
        }
    }
    cout<<"Numero total de iteraciones: "<<contador<<endl;
}

void printArray(int arr[], int tam){
    for(int i=0; i<tam; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout<<"Lista original: ";
    printArray(arr, tam);

    bubbleSort(arr, tam);

    cout<<"Lista ordenada: ";
    printArray(arr, tam);

    return 0;
}
