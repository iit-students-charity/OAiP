#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct person {
	string name;
	double math;
	double phys;
	double inf;
	double chem;
	double mid;
};

ifstream fin;
ofstream fout;

void print(vector <person>&);
double middl(vector <person>&);
void bbl_sort(vector <person>&);
void qck_sort(vector <person>&, int, int);
void srch(vector <person>&, double);
void bin_srch(vector <person>&, double);


int main()
{
	setlocale(LC_ALL, "Russian");
	vector <person> student;
	char option;

	while (true)
	{
		cout << "======================================================================================================" << endl;
		cout << "Фамилия и инициалы, год рождения, группа, отметка по информатике, химии, математике, физике, [средняя]" << endl;
		cout << "======================================================================================================" << endl;
		print(student);
		cout << "======================================================================================================" << endl;
		cout << endl;
		cout << "Введите 1, чтобы создать запись" << endl << "Введите 2, чтобы вывести студентов, чей балл выше среднего" 
			<< endl << "Введите 3, чтобы вычислить студента по IP" << endl << "Введите q, чтобы выйти" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
		{
			person buff;
			cout << "Введите фамилию и инициалы: ";
			SetConsoleCP(1251);
			cin.ignore();
			getline(cin, buff.name);
			SetConsoleCP(866);
			cout << "Введите отметку по информатике: ";
			cin >> buff.inf;
			cout << "Введите отметку по химии: ";
			cin >> buff.chem;
			cout << "Введите отметку по математике: ";
			cin >> buff.math;
			cout << "Введите отметку по физике: ";
			cin >> buff.phys;
			buff.mid = (buff.inf + buff.chem + 
				buff.math + buff.phys) / 4;
			student.push_back(buff);
			break;
		}
		case '2':
		{
			vector <person> sort;
			///////////////ПРЯМОЙ ВЫБОР////////
			sort = student;
			cout << "Общий средний - " << middl(sort) << endl;
			cout << "Результат сортировки прямым выбором:" << endl;
			bbl_sort(sort);
			print(sort);
			////////////QUICKSORT///////////////
			sort = student;
			middl(sort);
			qck_sort(sort, 0, sort.size() - 1);
			cout << "Результат QuckSort:" << endl;
			print(sort);
			system("pause");
			break;
		}
		case '3':
		{
			vector <person> search;
			double key = 0;
			cout << "Введите средний балл для поиска: ";
			cin >> key;
			cout << endl;
			////////////ПРЯМОЙ ПОИСК////////////////////
			search = student;
			srch(search, key);
			cout << "Результат прямого поиска:" << endl;
			print(search);
			///////////БИНАРНЫЙ ПОИСК///////////////////
			search = student;
			bbl_sort(search);
			bin_srch(search, key);
			cout << "Результат двоичного поиска:" << endl;
			print(search);
			system("pause");
			break;
		}
		case 'q':
		{
			return 0;
		}
		}

		fout.open("D:/stud.txt", ios_base::trunc);	
		for (size_t i = 0; i < student.size(); i++)
		{
			fout << student[i].name << " " << student[i].math << " " << student[i].phys << " " << student[i].inf << " " <<
				student[i].chem << " " << "[" << student[i].mid << "]" << endl;
		}
		fout.close();
		system("cls");
	}
	return 0;
}

void print(vector <person>& out)
{
	for (size_t i = 0; i < out.size(); i++)
	{
		cout << out[i].name << " " << out[i].math << " " << out[i].phys << " " << out[i].inf << " " <<
			out[i].chem << " " << "[" << out[i].mid << "]" << endl;
	}
}

double middl(vector <person>& md)
{
	double summ = 0;
	double com_mid;

	for (size_t i = 0; i < md.size(); i++)
	{
		summ += md[i].mid;
		i--;
	}
	com_mid = summ / md.size();

	for (size_t i = 0; i < md.size(); i++)
	{
		if (md[i].mid < com_mid)
		{
			md.erase(md.begin() + i);
		}
	}
	return com_mid;
}

void bbl_sort(vector <person>& srt)
{
	person buff;
	for (size_t i = 1; i < srt.size(); i++)
		for (int j = i; j > 0 && srt[j - 1].mid < srt[j].mid; j--)
		{
			swap(srt[j - 1], srt[j]);
		}
}

void qck_sort(vector <person>& srt, int first, int last)
{
	int f = first;
	int l = last;
	person bear = srt[(f + l) / 2];

	do
	{
		while (srt[f].mid > bear.mid) f++;
		while (srt[l].mid < bear.mid) l--;
		if (f <= l)
		{
			swap(srt[f], srt[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) qck_sort(srt, first, l);
	if (last > f) qck_sort(srt, f, last);
}

void srch(vector <person>& src, double key)
{
	for (size_t i = 0; i < src.size(); i++)
	{
		if (src[i].mid != key)
		{
			src.erase(src.begin() + i);
			i--;
		}
	}
}

void bin_srch(vector <person>& src, double key)
{
	vector <person> buff;
	int bear;
	int first = 0;
	int last = src.size();
	int n;

	while (first < last)
	{
		bear = (first + last) / 2;		
			if (src[bear].mid == key)
			{
				buff.push_back(src[bear]);
				for (int n = first; n < bear; n++)
				{
					if (src[n].mid == key)
					{
						buff.push_back(src[n]);
					}
				}
				for (int n = bear + 1; n < last; n++)
				{
					if (src[n].mid == key)
					{
						buff.push_back(src[n]);
					}
				}
				
			}

		if (src[bear].mid < key)
		{
			last = bear;
		}
		else
		{
			first = bear + 1;
		}
	}

	src.clear();
	src = buff;
}