/*Calcular la suma de los primeros 10 números de Fibonacci (averiguar en Internet las formulas)
o sea desde F(0) hasta F(10) pero excepto F(4). 
Utilizar operador  "continue" para que en su suma no aparezca F(4).*/
#include <iostream>
#include <math.h>

using namespace std;
int main()
{ int x,y,z;
  x=0;
  y=0;
  z=1;
  cout<<z<<endl;
  for(int i=0; i<10;i++) //Para que vaya de 1,1,2... partimos de z=1 y recalculamos valores.
  { x=y;
  y=z;
  z=x+y;
	if(i==3) //Nos saltamos la iteración 3.
	{
	continue;}
	cout<<z<<endl;
  }
return 0;
}
