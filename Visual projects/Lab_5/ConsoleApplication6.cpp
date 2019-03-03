#include "stdafx.h"
#include "math.h"
#include "iostream"
#include "windows.h"
#include <cstdlib>
using namespace std;

int lim; //random limit
int variant; //enter mod
int i;
int summ;
int k;
int n;
int mass[10];

int main()
{
	cout << "Please, enter mass   ive length (less then 10)" << '\n';
	cin >> i;
	if (i > 10)
	{
		cout << "Length is more than 10!" << '\n';
		system("pause");
	}
	cout << "Please, enter 1 if you want to set the massive manually, and 2 if you want to set the massive automatically" << '\n';
	cin >> variant;
	switch (variant)
	{
	case 1:
		cout << "You've chosen manually input. Plrase, enter numbers" << '\n';
		for (k = 0; k < i; k++)
			cin >> mass[k];
		cout << '\n';
		break;
	case 2:
		cout << "You've chosen auto input" << '\n';
		cout << "Enter random numer limit" << '\n';
		cin >> lim;
		k = 0;
		for (k = 0; k < i; k++)
			mass[k] = rand() % (lim - 1);
		break;
	default: cout << "You've entered wrong number" << '\n';
		system("pause");
		break;
	}

	summ = 0;
	for (k = i; k > 0; k--)
	{
		if (mass[k] == 0)
			n = k;
	}
	for (k = 0; k < n; k++)
		mass[k] = 0;
	for (k = 0; k < i; k++)
		summ = summ + mass[k];

	if (summ == 0)
	{
		cout << "Masiive hasn't zero or numbers !=0 after zero" << '\n';
		system("pause");
	}
	else
	{
		cout << "Summ:" << summ << '\n';
		system("pause");
	}
	return 0;
}

