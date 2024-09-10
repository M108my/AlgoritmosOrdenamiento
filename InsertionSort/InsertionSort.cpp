#include<iostream>
using namespace std;

void insertionSort(int arr[], int tam){
    long contador = 0;

    for(int i=1; i<tam; i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            contador++;
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
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

    insertionSort(arr, tam);

    cout<<"Lista ordenada: ";
    printArray(arr, tam);

    return 0;
}
