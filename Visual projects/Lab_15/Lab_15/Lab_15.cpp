#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double vegstain(double, double, double);
double f(double);

int main()
{
	const double a = -4.00;
    const double b = 3.00;
	const double e = 0.001;
	const double h = 0.001;

	for (double x = a; x <= b; x += h) 
	{
		if (f(x) * f(x + h) < 0)
		{
			cout << vegstain(x, x + h, e) << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

double vegstain(double x0, double x1, double eps)
{
	double x2, de;
	double y0 = f(x0);
	double y1 = f(x1);
	do 
	{
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
		de = fabs(x1 - x2);
		x0 = x1; 
		x1 = x2;
		y0 = y1;
		y1 = f(x2);
	}
	while (de > eps);
	return x2;
}

double f(double x)
{
	return pow(x, 3) - 50 * cos(x);
}