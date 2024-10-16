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



int main() {

    int personas;
    cout<<"Ingrese la cantida de personas: ";
    cin >> personas;

    int matriz[3][personas];

    cout<<"Ingrese las edades: ";
    for(int j = 0; j<personas; j++){
        cin>>matriz[0][j];
    }
    cout<<"Ingrese los sueldos: ";
    for(int j = 0; j<personas; j++){
        cin>>matriz[1][j];
    }
    cout<<"Ingrese las antiguedades: ";
    for(int j = 0; j<personas; j++){
        cin>>matriz[2][j];
    }


    for(int i = 0; i<3; i++){
        for(int j = 0; j<personas; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    float sueldo_promedio = get_promedio(matriz[1], personas);
    int mas_joven = matriz[0][0];
    int idx = 0;
    for(int i = 0; i<personas;i++){
        if(matriz[1][i]>sueldo_promedio){
            mas_joven = matriz[0][i];
            idx = i;
            break;
        }
    }

    for(int i = 0; i<personas; i++){
        if(matriz[1][i] > sueldo_promedio & mas_joven > matriz[0][i]){
            mas_joven = matriz[0][i];
            idx = i;
        }
    }
    int mas_antiguo = matriz[2][idx];


    cout<<"Sueldo promedio: "<<sueldo_promedio<<endl;
    cout<<"Edad mas joven: "<<mas_joven<<endl;
    cout<<"Antiguedad del mas joven: "<<mas_antiguo<<endl;


    return 0;
}



