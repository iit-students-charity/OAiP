#include <iostream>

using namespace std;


double Recursion(int x, int n)
 {
    if (n == 0)
        return 1;

    else if (n == 1)
        return x;

    else if (n % 2 == 0 )
        return Recursion(x * x, n / 2);

    else
        return x * Recursion(x, n - 1);
 }

void main() {

	setlocale(LC_ALL, "RU");

	int x;

	cout << "number x: ";

	cin >> x;

	int n;

	cout << "exp n: ";

	cin >> n;
	
	cout << endl << "Recursion Solving: " << Recursion(x, n) << endl;

	double y;

	y = pow(x, n);

	cout << endl << "NOT recursion Solving: " << y << endl;

	if (y == Recursion(x, n)) {

		cout << endl << "You have done it correct! " << endl;
	}
	else {

		cout << "You fail ^...^" << endl;
	}
}
/*	 Calculate y = x^n  for the rule:
	 y = (x ^ (n / 2)) ^ 2   if n is even
	 and
	 y = x * y^(n–1)     if n is odd.	
 */