/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <locale>
#include <math.h>

using namespace std;

int main()
{   
    int size;
    cout<<"Ingrese la cantidad de filas de la matriz: ";
    cin >> size;
    
    
    int matrix[size][size];
    
    bool diagonalFilas = true;
    bool diagonalColumnas = true;
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            cout << "Elemento en posición " <<i+1<<" "<<j+1<<": ";
            cin >> matrix[i][j];
        }
        
    }
    
    
    for(int i = 0; i<size;i++){
        float Norm = 0;
        for(int j = 0; j<size; j++){
            if(j!=i)
                Norm += abs(matrix[i][j]);
        }
        diagonalFilas = abs(matrix[i][i])>Norm;
        
        if(!diagonalFilas){
            break;
        }
    }
    for(int i = 0; i<size; i++){
        
        
        
        float Norm = 0;
        for(int j = 0; j<size; j++){
            if(j!=i)
                Norm += abs(matrix[j][i]);
        }
        diagonalColumnas = abs(matrix[i][i])>Norm;
        if(!diagonalColumnas){
            break;
        }
    }
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            
            cout <<setw(size*2)<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    if(diagonalFilas){
        cout<<"La matriz es estrictamente Diagonal por filas"<<endl;
    }
    else{
        cout<<"La matriz NO es estrictamente Diagonal por filas"<<endl;
    }
    if(diagonalColumnas){
        cout<<"La matriz es estrictamente Diagonal por columnas"<<endl;
    }
    else{
        cout<<"La matriz NO es estrictamente Diagonal por columnas"<<endl;
    }

    

    return 0;
}
