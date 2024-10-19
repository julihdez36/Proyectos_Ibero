#include <iostream>

using namespace std;

int get_suma(int arreglo[], int tamano){
    int suma = 0;
    for(int i = 0; i < tamano; i++){
        suma = arreglo[i]+suma;
    }
    return suma;
}

float get_promedio(int arreglo[], float tamano){
    return get_suma(arreglo, tamano)/tamano;
}

int numero_menor(int arreglo[], int tamano){
    int menor = arreglo[0];
    for(int i = 0; i<tamano; i++){
        if(menor>arreglo[i]){
            menor = arreglo[i];
        }
    }
    return menor;
}

int numero_mayor(int arreglo[], int tamano){
    int mayor = arreglo[0];
    for(int i = 0; i<tamano; i++){
        if(mayor < arreglo[i]){
            mayor = arreglo[i];
        }
    }
    return mayor;
}

int main() {
    int matriz[] = {1,2,3,-45,5,87,9};

    cout<<get_suma(matriz, 7)<<endl;
    cout<<get_promedio(matriz, 7)<<endl;
    cout<<numero_menor(matriz, 7)<<endl;
    cout<<numero_mayor(matriz, 7)<<endl;

    return 0;
}



