#include <iostream>
using namespace std;
int main() {

    int cantidadInputs;

    cout<<"Ingrese la cantidad de notas a registar: ";
    cin>>cantidadInputs;

    int Notas[cantidadInputs];
    cout<<"Ingrese las notas: ";
    for(int i = 0; i < cantidadInputs; i++){
        cin >> Notas[i];
    }
    for(int i = 0; i<cantidadInputs; i++){
        cout<<Notas[i]<<endl;
    }
    float suma = 0;
    for(int i = 0; i < cantidadInputs; i++){
        suma = suma+Notas[i];
    }
    float promedio;
    promedio = suma/cantidadInputs;

    cout << "Promedio: " <<promedio << endl;

    cout << "Las notas mayores al promedio son las siguientes: " << endl;
    for(int i = 0; i < cantidadInputs; i++){
        if(promedio < Notas[i]){
            cout<<Notas[i]<<endl;
        }
    }

    cout << "Las notas en orden decendente son: "<<endl;
    bool mod = true;
    int t;
    while(mod){
        mod = false;

        for(int i = 0; i<cantidadInputs-1;i++){
            if(Notas[i]<Notas[i+1]){
                t = Notas[i+1];
                Notas[i+1] = Notas[i];
                Notas[i] = t;
                mod = true;
            }
        }
    }
    for(int i = 0; i<cantidadInputs; i++){
        cout<<Notas[i]<<endl;
    }
    return 0;
}