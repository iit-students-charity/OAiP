#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

unsigned int fact_rec(unsigned int);
unsigned int fact(unsigned int);

int main()
{
	unsigned int n, k;

	cout << "All data must be unsigned int type" << endl;
	cout << "Enter n: " << endl;
	cin >> n;
	cout << "Enter k: " << endl;
	cin >> k;
	system("cls");
	cout << "Now you'll be shown a recurcive function." << endl;
	cout << "n = " << n << ";  k = " << k << "." << endl;
	cout << endl;
	cout << "C = ";
	cout << fact_rec(n)/(fact_rec(k) * fact_rec(n - k)) << endl;
	system("pause");
	system("cls");

	cout << "Now you'll be shown an ordinary function." << endl;
	cout << "n = " << n << ";  k = " << k << "." << endl;
	cout << endl;
	cout << "C = ";
	cout << fact(n) / (fact(k) * fact(n - k)) << endl;
	system("pause");
    return 0;
}

unsigned int fact_rec(unsigned int n)
{
	if (n > 2)
	{
		return n * fact_rec(n - 1);
	}
	else
	{
		return 1;
	}
}

unsigned int fact(unsigned int n)
{
	unsigned int k = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		k *= i;
	}
	return k;
}
