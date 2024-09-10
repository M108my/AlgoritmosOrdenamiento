#include<iostream>
using namespace std;

void selectionSort(int arr[], int tam){
    long contador=0;
    for(int i=0; i<tam-1; i++){
        int minInd = i;
        for(int j=i+1; j<tam; j++){
            contador++;
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        swap(arr[i], arr[minInd]);
    }
    cout<<"Numero total de comparaciones: "<<contador<<endl;
}

void printArray(int arr[], int tam) {
    for (int i=0; i<tam; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {64,25,12,22,11};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout<<"Lista original: ";
    printArray(arr, tam);

    selectionSort(arr, tam);

    cout<<"Lista ordenada: ";
    printArray(arr, tam);

    return 0;
}
