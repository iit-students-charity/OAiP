#include "stdafx.h"
#include <string>
#include <iostream>
#include "windows.h"
using namespace std;


int main()
{
	string str;
	int lenth;
	int k = 0;
	int symb_pos = 0;
	int posit[100];
	int word_len[100];
	int posit_of_longest = 0;

	cout << "Inp the string" << endl;
	getline(cin, str);

	str = ' ' + str + ' ';	
	lenth = str.size();

	for (int i = 0; i < lenth; i++)
	{
		if (str[i] == ' ')
		{
			posit[k] = i;
			k++;
		}
	}

	for (int i = 0; i < k - 1; i++)
	{
		word_len[i] = posit[i + 1] - posit[i] - 1;
	}

	int len_of_longest = word_len[0];
	for (int i = 0; i < k - 1; i++)
	{
		if (word_len[i] > len_of_longest)
		{
			posit_of_longest = i;
			len_of_longest = word_len[i];
		}
	}

	cout << "Number of the longest word is " << posit_of_longest + 1;
	cout << endl;

	symb_pos = posit[posit_of_longest];

	cout << "Number of symbol is " << symb_pos + 1 << endl;

	system("pause");
    return 0;
}

