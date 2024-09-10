#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 100

void selectionSort(int arr[], int tam, long &contador){
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
}

int main() {
    int mejorCaso[MAX];
    int peorCaso[MAX];
    int casoPromedio[MAX];

    ofstream archivo("iteracionesSS.csv");

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

            selectionSort(mejorCaso, i, iteracionesMejorCaso);
            selectionSort(peorCaso, i, iteracionesPeorCaso);
            selectionSort(casoPromedio, i, iteracionesCasoPromedio);

            archivo << i << ","
                << iteracionesMejorCaso << ","
                << iteracionesPeorCaso << ","
                << iteracionesCasoPromedio << endl;

        }
        archivo.close();
    }

    return 0;
}
