/*Escribir un programa que dado un entero positivo n, calcule la lista primos menores o iguales a n 
(para cada numero deben averiguar si el es divisible por los enteros entre 2 y la raíz cuadrada de n) 
y al final imprime la cantidad de ellos.*/

#include <iostream>
#include <math.h>

using namespace std;
int main ()
{ int x,y,ctr;
  y=2;
  cout<<"ingrese un entero positivo"<<endl;
  cin>>x;
  while (y<=x)
  {
  	ctr=0;
  	for(int i=2;i<=sqrt(y);i++){
  		if(y%i==0)
  		{
  			ctr++;
  			
		  }
	  }
	  if(ctr==0)
	  {cout<<y<<" es un numero primo"<<endl;
	  }
	y++;
  }
  return 0;
}

