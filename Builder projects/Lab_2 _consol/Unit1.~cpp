//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <math.h>
#include <iostream.h>
#include <conio.h>
int main(int argc, char* argv[])
{
#define e 2,718281828;
double x,y,z,a,b,rez,funct;
int key;
//ввод переменных
puts("\nz a b = (vvod bez zpt cherez probel)");
scanf("%lf%lf%lf", &z, &a, &b);
printf("Vi vveli: %7.3lf%7.3lf%7.3lf",z,a,b);
//проверка z
if (z>0) x=pow(z,1./2);
else x=3*z+1;
printf("\nPri z=%7.3lf x=%7.3lf",z,x);
//выбор функции
puts("\nVvedite 1, esli hotite vibrat 2x, 2 - esli x^2, 3 - esli x/3");
scanf("%d", &key);
switch (key) {
case 1: funct=2*x; break;
case 2: funct=pow(x,2); break;
case 3: funct = x/3.0; break;
default: {printf("\n Vvedite 1-3");getch();}
}
// вычисление
rez= b*cos(funct*a)+sin(x/5.0)+a*exp(x);
printf("\nrezultat vichisleniy: %lf ", rez);

getch();

        return 0;
}
//---------------------------------------------------------------------------
