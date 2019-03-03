#include "stdafx.h"
#include <iostream>
#include "windows.h"
using namespace std;



int main()
{
	double* a;
	int rows, cols;
	int pos_of_max_summ = 0;
	int max_summ;

	cout << "Enter count of rows" << '\n';
	cin >> rows;
	cout << "Enter count of colomns" << '\n';
	cin >> cols;

	double **arr = new double*[rows];
	for (int r = 0; r < rows; r++)
		arr[r] = new double[cols];

	cout << "Enter the array" << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
			cin >> arr[r][c];
	}

	for (int r = 0; r < rows; r++)
	{
		cout << endl;
		for (int c = 0; c < cols; c++)
			cout << arr[r][c] << " ";
	}
	cout << endl;

	float *summ = new float[cols];
	for (int i = 0; i < cols; i++)
		summ[i] = 0;
	for (int c = 0; c < cols; c++)
		{
		for (int r = 0; r < rows; r++)
			summ[c] += arr[r][c];
		}

	while (cols != 1)
	{
		pos_of_max_summ = 0;
		max_summ = summ[0];
		for (int i = 0; i < cols; i++)
		{
			if (summ[i] > max_summ)
				pos_of_max_summ = i;
		}
		for (int c = pos_of_max_summ; c < cols; c++)
		{
			for (int r = 0; r < rows; r++)
				arr[r][c] = arr[r][c + 1];
		}

		cols = cols - 1;

		for (int r = 0; r < rows; r++)
		{
			cout << endl;
			for (int c = 0; c < cols; c++)
				cout << arr[r][c] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] summ;
	
	cout << endl;
	cout << "All arrays were deleted" << '\n';
	system("pause");
	return 0;
}



