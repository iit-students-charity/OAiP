#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;
ifstream fin;
ofstream fout;

int cnt = 0;
string option;
string text;
regex rx1("1");
regex rx2("2");
regex rx3("3 [1-9][0-9]{4}[1-9]");
regex rx4("4");
regex middle("");

void view();
void create();
void correction();
void indiv();

int main()
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		view();
		cout << endl;
		cout << "Чтобы создать запись, введите 1" << endl << "Чтобы редактировать запись, введите 2" << endl
			<< "Чтобы распечатать данные студентов-отличников интересующей вас группы, введите 3 и номер группы" << endl
			<< "Чтобы выйти, введите 4" << endl;
		cout << endl;
		getline(cin, option, '\n');

		if (regex_match(option, rx1))
		{
			create();
		}
		else if (regex_match(option, rx2))
		{
			correction();
		}
		else if (regex_match(option, rx3))
		{
			indiv();
		}
		else if (regex_match(option, rx4))
		{
			return 0;
		}
		else
		{
			cout << "Введите верные данные!" << '\a' << endl;
			Sleep(1500);
		}

	}
}



void view()
{
	system("cls");
	cnt = 0;
	fin.open("D:/stud.txt");
	cout << endl;
	cout << "_____________________________СПИСОК______________________________" << endl;
	cout << "порядок оценок: физика, математика, информатика, химия, <средняя>" << endl;
	cout << "_________________________________________________________________" << endl;
	while (!fin.eof())
	{
		cout << "[" << cnt + 1 << "] ";
		cnt++;
		getline(fin, text, '\n');
		cout << text << endl;
	}
	cout << "______________________________________________" << endl;
	cout << endl;
	text = "";
	fin.close();
}

void create()
{
	fout.open("D:/stud.txt", ios_base::app); //открыть для записи в конец
	if (!fout.is_open()) //проверка на существование файла
	{
		cout << "Не удается открыть файл" << '\a' << endl;
		fout.close();
		system("pause");
	}
	else
	{
		cout << "Введите данные" << endl;
		SetConsoleCP(1251); //изменение кодировки для ввода в консоль...
							//cin.ignore(); //если перед cin.getline() был любой cin, то перед ним нужно поставить cin.ignore()
		getline(cin, text);

		fout << text << endl;
		SetConsoleCP(866); //...и обратно
		text = "";
	}
	fout.close();
}

void correction()
{
	string data[9999];
	int line = 0;
	int str = 0;

	fin.open("D:/stud.txt");
	while (!fin.eof())
	{
		getline(fin, data[line], '\n'); //считывать из файла 
		line++;
	}
	fin.close();

	cout << "Введите номер строки, которую хотите изменить" << endl;
	cin >> str;
	cout << "Введите новые данные" << endl;
	SetConsoleCP(1251);
	cin.ignore();
	getline(cin, text);
	SetConsoleCP(866);
	data[str - 1] = text;
	text = "";

	fout.open("D:/stud.txt", ios_base::trunc);
	for (int i = 0; i < line; i++)
	{
		if (!empty(data[i])) //фикс бага с лишней пустой строкой
		{
			fout << data[i] << "\n";
		}
	}
	fout.close();
	text = "";
}

void indiv()
{
	option.erase(0, 2); //получение из option номера группы путем удаления 3_
	regex achiever(".* " + option + " (9|10) (9|10) (9|10) (9|10)");
	bool exist = 0;

	string data[9999];
	int line = 0;
	int str = 0;

	fin.open("D:/stud.txt");
	while (!fin.eof())
	{
		getline(fin, data[line], '\n'); //считывать из файла 
		line++;
	}
	fin.close();

	for (int i = 0; i < line; i++)
	{
		if (regex_match(data[i], achiever))
		{
			exist = 1;
			cout << data[i] << endl;
		}
	}

	if (exist == 0)
	{
		cout << "Отличники не найдены" << '\a' << endl;
	}
	Sleep(2000);
}