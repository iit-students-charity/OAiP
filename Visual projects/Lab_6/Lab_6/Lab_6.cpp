#include "stdafx.h"
#include <iostream>
#include "windows.h"
using namespace std;



int main()
{
	int i, j, cols, rows, max_i=0, min_i=0;
	double max, min;
	double* p;
	cout << "Enter count of rows" << '\n';
	cin >> rows;
	cout << "Enter count of colomns" << '\n';
	cin >> cols;

	double **arr = new double*[rows];
	for (i = 0; i < rows; i++)
		arr[i] = new double[cols];

	cout << "Enter the array" << '\n';
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			cin >> arr[i][j];
	}
	max = arr[0][0];
	min = arr[0][0];


	cout << "_______________________________________"<<'\n';
	for (i = 0; i < rows; i++)
	{
		cout << '\n';
		for (j = 0; j < cols; j++)
			cout << arr[i][j] << " ";
	}
	cout << '\n' << "_______________________________________" << '\n' << '\n';


	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				max_i = i;
			}
		}
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
				min_i = i;
			}
		}
	}

	cout << min_i << max_i << '\n';

	p = arr[min_i];
	arr[min_i] = arr[max_i];
	arr[max_i] = p;

	cout << "_______________________________________" << '\n';
	for (i = 0; i < rows; i++)
	{
		cout << '\n';
		for (j = 0; j < cols; j++)
			cout << arr[i][j] << " ";
	}
	cout << '\n' << "_______________________________________" << '\n' << '\n';


	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
	cout << "The array was deleted" << '\n';
	system("pause");
	return 0;
}


