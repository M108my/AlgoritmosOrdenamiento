#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 100

void insertionSort(int arr[], int tam, long &contador){
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
}

int main() {
    int mejorCaso[MAX];
    int peorCaso[MAX];
    int casoPromedio[MAX];

    ofstream archivo("iteracionesIS.csv");

    if (archivo.is_open()) {
        archivo << "Tamanio,Mejor Caso,Peor Caso,Caso Promedio\n";

        for(int i=1; i<=MAX; i++){

            long iteracionesMejorCaso = 0;
            long iteracionesPeorCaso = 0;
            long iteracionesCasoPromedio = 0;

            for(int j=0; j<i; j++){
                mejorCaso[j] = j + 1;   //ordenado
                peorCaso[j] = i - j;    //Inverso
                casoPromedio[j] = rand() % 100; //aleatorio
            }

            insertionSort(mejorCaso, i, iteracionesMejorCaso);
            insertionSort(peorCaso, i, iteracionesPeorCaso);
            insertionSort(casoPromedio, i, iteracionesCasoPromedio);

            archivo << i << ","
                << iteracionesMejorCaso << ","
                << iteracionesPeorCaso << ","
                << iteracionesCasoPromedio << endl;

        }
        archivo.close();
    }

    return 0;
}

