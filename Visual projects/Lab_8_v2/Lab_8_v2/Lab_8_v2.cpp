/*Создать D:\\stud.txt!!! */
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <regex>

using namespace std;

struct person {
	string name;
	int year;
	int group;
	double math;
	double phys;
	double inf;
	double chem;
	double mid;
};

ifstream fin;
ofstream fout;

string text;  //
string text_; //буфер
int option = 0;
int line;
int st;


int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		person student;
		fin.open("D:\\stud.txt");
		int cnt = 0;
		while (!fin.eof())
		{
			getline(fin, text_, '\n');
			text = text + text_ + '\n';
			cnt++;
		}
		fin.close();

		cout << "====================================================================================================" << endl;
		cout << "Фамилия и инициалы, год рождения, группа, отметка по информатике, химии, математике, физике, средняя" << endl;
		cout << "====================================================================================================" << endl;
		cout << text << endl;

		cout << "Введите 1, чтобы создать запись" << endl << "Введите 2, чтобы редактировать запись" << endl <<
			"Введите 3, чтобы вывести всех отличников определенно группы" << endl << "Введите 4, чтобы выйти" << endl;
		cin >> option;
		text = "";
		switch (option)
		{
		case 1:
		{
			cout << "Введите фамилию и инициалы: ";
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, student.name);
			SetConsoleCP(866);
			cout << "Введите год рождения: ";
			cin >> student.year;
			char year[50];
			sprintf_s(year, " %d", student.year);
			cout << "Введите группу: ";
			cin >> student.group;
			char group[50];
			sprintf_s(group, " %d", student.group);
			cout << "Введите отметку по информатике: ";
			cin >> student.inf;
			char inf[50];
			sprintf_s(inf, " %.0lf", student.inf);
			cout << "Введите отметку по химии: ";
			cin >> student.chem;
			char chem[50];
			sprintf_s(chem, " %.0lf", student.chem);
			cout << "Введите отметку по математике: ";
			cin >> student.math;
			char math[50];
			sprintf_s(math, " %.0lf", student.math);
			cout << "Введите отметку по физике: ";
			cin >> student.phys;
			char phys[50];
			sprintf_s(phys, " %.0lf", student.phys);
			cin.get(); //фикс побочной записи \n
			student.mid = (student.inf + student.chem + student.math + student.phys) / 4;
			char mid[50];
			sprintf_s(mid, " %.3lf", student.mid);

			text = student.name + " " + year + " " + group + " " + inf + " " + chem + " " + math + " " +
				phys + "   " + "<" + mid + " >";

			break;
		}
		case 2:
		{
			string data[9999];
			fin.open("D:/stud.txt");
			while (!fin.eof())
			{
				getline(fin, data[line]); //считывать из файла 
				line++;
			}
			fin.close();

			cout << "Введите номер строки,которую хотите изменить" << endl;
			cin >> st;
			cout << "Введите фамилию и инициалы: ";
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, student.name);
			SetConsoleCP(866);
			cout << "Введите год рождения: ";
			cin >> student.year;
			char year[50];
			sprintf_s(year, " %d", student.year);
			cout << "Введите группу: ";
			cin >> student.group;
			char group[50];
			sprintf_s(group, " %d", student.group);
			cout << "Введите отметку по информатике: ";
			cin >> student.inf;
			char inf[50];
			sprintf_s(inf, " %.0lf", student.inf);
			cout << "Введите отметку по химии: ";
			cin >> student.chem;
			char chem[50];
			sprintf_s(chem, " %.0lf", student.chem);
			cout << "Введите отметку по математике: ";
			cin >> student.math;
			char math[50];
			sprintf_s(math, " %.0lf", student.math);
			cout << "Введите отметку по физике: ";
			cin >> student.phys;
			char phys[50];
			sprintf_s(phys, " %.0lf", student.phys);
			cin.get(); //фикс побочной записи \n
			student.mid = (student.inf + student.chem + student.math + student.phys) / 4;
			char mid[50];
			sprintf_s(mid, " %.3lf", student.mid);

			text = student.name + " " + year + " " + group + " " + inf + " " + chem + " " + math + " " +
				phys + "   " + "<" + mid + " >";
			data[st - 1] = text;
			text = "";
			for (int i = 0; i < line; i++)
			{
				if (data[i] == "\n")
				{
					data[i] = "";
				}
				text = text + data[i] + '\n';
			}
			break;
		}
		case 3:
		{
			string group;
			string data[9999];
			string ach[9999];

			fin.open("D:/stud.txt");
			while (!fin.eof())
			{
				getline(fin, data[line]); //считывать из файла 
				line++;
			}
			fin.close();

			cout << "Введите группу: ";
			cin >> group;
			regex achiever(".* " + group + ".*(9|10).*(9|10).*(9|10).*(9|10).*");

			for (int i = 0; i < line; i++)
			{
				if (regex_match(data[i], achiever))
				{
					cout << data[i] << endl;
				}
			}

			system("pause");
			return 0;
			break;
		}
		case 4:
		{
			return 0;
			break;
		}
		}

		fout.open("D:/stud.txt", ios_base::trunc); //открыть для записи в конец		
		fout << text << '\n';
		fout.close();
		text = "";
		system("cls");
	}
	return 0;
}