#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Train {
	int date;  // number of weekday
	string destination;  // city
	int time;  // number of hour
	int vacancies;  // free tickets
};

int numLines() {

	ifstream fi;

	fi.open("trains.txt");

	bool end = true;

	char buff[50];

	int lines = 0;

	while (!fi.eof()) {

		fi.getline(buff, 50);

		lines++;
	}

	fi.close();

	return lines - 1;
}

void QuickSort(Train* a, int begin, int end)
{
	int left, right;

	left = begin;

	right = end;

	Train x = a[(left + right) / 2];

	do {

		while (a[left].vacancies < x.vacancies) left++;

		while (x.vacancies < a[right].vacancies) right--;

		if (left <= right) {

			x = a[left];

			a[left] = a[right];

			a[right] = x;

			left++;

			right--;
		}

	} 

	while (left <= right);

	if (begin < right) QuickSort(a, begin, right);

	if (left < end) QuickSort(a, left, end);
}

void Binary(Train* a, int n, int x)
{
	int i = 0, j = n - 1, m;

	while (i < j) {

		m = (i + j) / 2;

		if (x > a[m].vacancies)
			i = m + 1;

		else
			j = m;
	}

	if (a[i].vacancies == x)
		cout << "\nYour train number in SORTED file is " << i + 1 << endl << endl;
	
	else 
		cout << "\nThere is no such element" << endl << endl;

}

int main() {

	string path = "trains.txt";

	ifstream fi;

	ofstream fo;

	ofstream srt;

	ifstream srted;

	Train train[230];

	int k = 11;

	int n = 0, j = 0, a = 0;

	int l = 0;

	int lines;

	while (k != 5) {

		cout << "Choose how to open file: \n1 - Creating \n2 - View \n3 - Append \n4 - Technical task \n5 - Close \n6 - Delete information" << endl;

		cin >> k;

		if (k == 1) {

			fo.open(path, ofstream::out); 

			if (!fo.is_open())
			{
				cout << "Open file Error : (" << endl;
			}
			else
			{

				cout << "Enter number of trains: ";

				cin >> n;

				cout << "\t\t  Enter trains info: ";

				for (int i = 0; i < n; i++)
				{
					cout << "\ntrain (" << i << ") departure date: ";
					cin >> train[i].date;
					cout << "\ntrain (" << i << ") destination: ";
					cin >> train[i].destination;
					cout << "\ntrain (" << i << ") departure time: ";
					cin >> train[i].time;
					cout << "\ntrain (" << i << ") vacancies: ";
					cin >> train[i].vacancies;
				}

				for (int i = 0; i < n; i++)
				{
					fo << train[i].date << endl;
					fo << train[i].destination << endl;
					fo << train[i].time << endl;
					fo << train[i].vacancies << endl;
		
				}

			}

			fo.close();
		}

		else if (k == 2) {

			cout << "\t\tUNSORTED FILE:\n\n";

			fi.open(path);

			if (!fi.is_open())
			{
				cout << "Reading Error" << endl;
			}
			else
			{
				cout << endl << endl;

				char ch;

				while (fi.get(ch)) {

					cout << ch;

				}
			}

			fi.close();

			cout << "\t\tSORTED FILE:\n\n";

			srted.open("sorted.txt");

			if (!srted.is_open())
			{
				cout << "Reading Error" << endl;
			}
			else
			{
				cout << endl << endl;

				char ch;

				while (srted.get(ch)) {

					cout << ch;

				}
			}

			srted.close();

			cout << endl;
		}

		else if (k == 3) {

			fo.open(path, ofstream::app);

			if (!fo.is_open())
			{
				cout << "Append error" << endl;
			}
			else
			{

				cout << "\nHow many new trains you want to add? ";

				cin >> j;

				cout << "\t\t  Enter trains info: ";

				lines = numLines();

				for (int a = lines / 4; a < lines / 4 + j; a++)
				{
					cout << "\ntrain (" << a << ") departure date: ";
					cin >> train[a].date;
					fo << train[a].date << endl;
					cout << "\ntrain (" << a << ") destination: ";
					cin >> train[a].destination;
					fo << train[a].destination << endl;
					cout << "\ntrain (" << a << ") departure time: ";
					cin >> train[a].time;
					fo << train[a].time << endl;
					cout << "\ntrain (" << a << ") vacancies: ";
					cin >> train[a].vacancies;
					fo << train[a].vacancies << endl;

				}

			}
			fo.close();
		}
		else if (k == 4) {  
				
				fi.open(path);

				lines = numLines();

				int recCount = 0;

				while (!fi.eof() && recCount < 230)
				{
					fi >> train[recCount].date >> train[recCount].destination >> train[recCount].time >> train[recCount].vacancies;

					++recCount;
				}

				fi.close();

				cout << "Choose how to sort / search file: \n1 - Linear search \n2 - Direct selection sorting \n3 - QuickSort \n4 - Binary search \n5 - Booking" << endl;

				cin >> l;

				if (l == 1) {
					
					int c;

					cout << "\nEnter the number of vacancies of train you want to find: ";

					cin >> c;

					bool checker = true;

					for (int i = 0; i < lines / 4; i++) {

						if (train[i].vacancies == c) {

							cout << "\nYour train number is " << i + 1 << " IN UNSORTED FILE ";

							checker = false;

						}

					}

					if (checker) {

						cout << "\nSorry there is no such train";

					}

					cout << endl << endl;

				}

				else if (l == 2) {   // Direct selection sorting

					int min;

					Train r = {0, "Russia", 0, 0};

					for (int i = 0; i < lines / 4; i++) {

						min = i;

						for (int y = i + 1; y < lines / 4; y++)
							if (train[y].vacancies < train[min].vacancies)
								min = y;

						r = train[min];

						train[min] = train[i];

						train[i] = r;

					}

					srt.open("sorted.txt", ofstream::trunc);

					srt.close();
					
					srt.open("sorted.txt", ofstream::app);

					for (int i = 0; i < lines / 4; i++)
					{
						srt << train[i].date << endl;
						srt << train[i].destination << endl;
						srt << train[i].time << endl;
						srt << train[i].vacancies << endl;

					}

				}

				else if (l == 3) {  // QuickSort

					QuickSort(train, 0, lines / 4 - 1);

					srt.open("sorted.txt", ofstream::trunc);

					srt.close();

					srt.open("sorted.txt", ofstream::app);

					for (int i = 0; i < lines / 4; i++)
					{
						srt << train[i].date << endl;
						srt << train[i].destination << endl;
						srt << train[i].time << endl;
						srt << train[i].vacancies << endl;

					}

				}

				else if (l == 4) {

					QuickSort(train, 0, lines / 4 - 1);

					int p;

					cout << "\nEnter the number of vacancies of train you want to find: ";

					cin >> p;

					Binary(train, lines / 4, p);

				}

				else if (l == 5) {			

				int places, day, hour;

				string city;

				cout << "Enter the number of vacancies you want to reserve: ";

				cin >> places;

				cout << "Enter the city you want to move to: ";

				cin >> city;

				cout << "Enter the number of day you want to reserve: ";

				cin >> day;

				cout << "Enter the hour you want to reserve: ";

				cin >> hour;

				bool no = true;

				for (int i = 0; i < lines / 4; i++) {

					if (train[i].vacancies >= places && train[i].date == day && train[i].time >= hour && train[i].destination == city) {

						cout << "\nHere is the number of train you have reserved: " << i + 1 << endl;

						no = false;
					}
						
				}
				
				if (no)
					cout << "There is no train you want to reserve, sorry\n";
				}

		}
		else if (k == 5) {

			cout << "Clossing..";

			break;
		}

		else if (k == 6) {

			srt.open("sorted.txt", ofstream::trunc);

			srt.close();

			fo.open(path, ofstream::trunc);

			fo.close();

		}

	}

	return 0;

}










/*else if (k == 7) {

			lines = numLines();

			int recCount = 0;

			fi.open(path);

			while (!fi.eof() && recCount < 230)
			{
				fi >> train[recCount].date >> train[recCount].destination >> train[recCount].time >> train[recCount].vacancies;

				++recCount;
			}

			fi.close();

			n = lines / 4;

			cout << "Enter how much trains you want to correct: ";

			int y;

			cin >> y;

			if (y > n) {

				cout << "\nUnvaible number...\n\nEnter the number less than number of trains? please\n";

				return -1;

			}

			int z;

			for (int i = 0; i < y; i++) {

				cout << "\nChoose the train in UNSORTED list to edit: ";

				cin >> z;

				cout << "\ntrain (" << z - 1 << ") departure date: ";
				cin >> train[z].date;
				cout << "\ntrain (" << z - 1 << ") destination: ";
				cin >> train[z].destination;
				cout << "\ntrain (" << z - 1 << ") departure time: ";
				cin >> train[z].time;
				cout << "\ntrain (" << z - 1 << ") vacancies: ";
				cin >> train[z - 1].vacancies;

			}

			srt.open("sorted.txt", ofstream::trunc);

			srt.close();

			fo.open(path, ofstream::trunc);

			fo.close();

			fo.open(path, ofstream::app);

			for (int i = 0; i < n; i++)
			{
				fo << train[i].date << endl;
				fo << train[i].destination << endl;
				fo << train[i].time << endl;
				fo << train[i].vacancies << endl;

			}

			fo.close();
		}*/