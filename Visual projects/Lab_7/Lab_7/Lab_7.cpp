#include "stdafx.h"
#include <string.h>
#include <iostream>
#include "windows.h"
using namespace std;


int main()
{
	int k = 0;
	int len; //stling lenth
	int pos = 0;
	char str[999];
	int posit[999]; //array for "space" positions
	int word_len[999]; //array for words lenth

	cout << "Input the string" << '\n';
	gets_s(str);
	len = strlen(str);


	for (int i = 0; i < len; i++)
		str[i]  = str[i+1];
	len = strlen(str);
	//str[0] = ' ';
	//str[len + 1] = ' ';

	for (int i = 0; i<len; i++)
		cout << str[i];
	cout << '\n';

	/*for (int i = 0; i<len; i++)
	{
	if (str[i] == ' ')
	{
	posit[k] = i;
	k++;
	}
	}

	for (int i = 0; i < k-1; i++)
	{
	word_len[i] = posit[i+1]-posit[i];
	}

	for (int i = 0; i < k; i++)
	cout << word_len[i]<<endl;*/

	system("pause");
	return 0;
}
