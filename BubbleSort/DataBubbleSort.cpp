#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 100

void bubbleSort(int arr[], int tam, long &contador) {
    bool intercambio;
    for (int i = 0; i < tam - 1; i++) {
        intercambio = false;

        for (int j = 0; j < tam - 1; j++) {
            contador++;  // Contamos cada vez que pasa por el bucle interno
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio){ break; }
    }
}

int main() {
    int mejorCaso[MAX];
    int peorCaso[MAX];
    int casoPromedio[MAX];

    ofstream archivo("iteracionesBS.csv");

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

            bubbleSort(mejorCaso, i, iteracionesMejorCaso);
            bubbleSort(peorCaso, i, iteracionesPeorCaso);
            bubbleSort(casoPromedio, i, iteracionesCasoPromedio);

            archivo << i << ","
                << iteracionesMejorCaso << ","
                << iteracionesPeorCaso << ","
                << iteracionesCasoPromedio << endl;

        }
        archivo.close();
    }
    return 0;
}

