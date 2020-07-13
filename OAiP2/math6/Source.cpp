#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x)
{
	return sin(x) * sin(x) - 3 * cos(x);
}

double secant(double x0, double x1, double eps) 
{
	double y0, y1, x2, de;
	double q = 0.000001;
	y0 = f(x0);
	y1 = f(x1);

	do {
		x2 = x1 - y1 * q / (y1 - f(x1 - q));
		de = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = f(x2);
	} 
	while (de > eps);

	return x2;
}

int main()
{
	double eps = 0.00000000002;
	double a = -7;
	double b = 3;
	double h = 0.1;

	for (double x = a; x <= b; x += h)
	{
		if (f(x) * f(x + h) < 0)
		{
			//cout << setprecision(10) << secant(x, x + h, eps) << "\n\n";
			cout << secant(x, x + h, eps) << "\n";
		}
	}
}