#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Marks {
	int physics;
	int math;
	int informatics;
	int chemistry;
};

struct Student {
	string surname;
	int birthYear;
	int groupNumber;
	Marks marks;
	double rate;
};

ifstream fi;

int numLines() {

	ifstream fi;

	fi.open("Students.txt");

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

Student Reading(int start) {

	Student stud;

	fi.open("Students.txt");

	char buff[50];

	int len = 0;

	double ch = 0;

	int mn = 1;

	bool elem = true;

	string name;

	for (int i = 0; i < start; i++) {

		fi.getline(buff, 50);
	}

	for (int j = 0; j < 8; j++) {

		fi.getline(buff, 50);

		switch (j) {

		case 0: {

			while (elem) {		// длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}

			name = "";

			for (int i = 0; i <= len - 2; i++) {

				name += buff[i];
			}

			stud.surname = name;

			break;
		}
		case 1: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) {		//длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) {	//получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.birthYear = ch;

			break;
		}
		case 2: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) { //длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}
				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.groupNumber = ch;

			break;
		}

		case 3: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) { //длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.marks.physics = ch;

			break;
		}

		case 4: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) { //длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.marks.math = ch;

			break;
		}

		case 5: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) { //длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.marks.informatics = ch;

			break;
		}

		case 6: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) {

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}
			stud.marks.chemistry = ch;

			break;
		}

		case 7: {

			len = 0;

			ch = 0;

			mn = 1;

			elem = true;

			while (elem) { //длина строки

				if (buff[len] - '0' == -48) {

					elem = false;
				}

				len++;
			}
			for (int i = len - 2; i >= 0; i--) { //получение числа

				ch += (buff[i] - '0') * mn;

				mn *= 10;
			}

			stud.rate = ch;

			break;
		}

		}
	}
	fi.close();

	return stud;
}



int main()
{
	setlocale(LC_ALL, "Ru");

	string path = "Students.txt";

	int k = 1729;

	ofstream fo;

	//ifstream fi; 

	Student stud[120];

	int n = 0;

	int j = 0;

	while (k != 5) {

		cout << "Choose how to open file: \n1 - Creating \n2 - View \n3 - Append \n4 - Technical task \n5 - Close \n6 - Delete information" << endl;

		cin >> k;

		if (k == 1) {
			fo.open(path, ofstream::out);
			if (!fo.is_open())
			{
				cout << "Creating Error " << endl;
			}
			else
			{

				cout << "Enter number of students: ";

				cin >> n;

				cout << "\t\t  Enter students info: ";

				for (int i = 0; i < n; i++)
				{
					cout << "\nstudent surname: ";
					cin >> stud[i].surname;
					cout << "\nstudent birth year: ";
					cin >> stud[i].birthYear;
					cout << "\nstudent group number: ";
					cin >> stud[i].groupNumber;
					cout << "\nstudent physics mark: ";
					cin >> stud[i].marks.physics;
					cout << "\nstudent math mark: ";
					cin >> stud[i].marks.math;
					cout << "\nstudent informatics mark: ";
					cin >> stud[i].marks.informatics;
					cout << "\nstudent chemistry mark: ";
					cin >> stud[i].marks.chemistry;
					stud[i].rate = (stud[i].marks.chemistry + stud[i].marks.informatics + stud[i].marks.math + stud[i].marks.physics) / 4.;
					cout << "\nstudent rate is: " << stud[i].rate << endl;
				}

				for (int i = 0; i < n; i++)
				{
					fo << stud[i].surname << endl;
					fo << stud[i].birthYear << endl;
					fo << stud[i].groupNumber << endl;
					fo << stud[i].marks.physics << endl;
					fo << stud[i].marks.math << endl;
					fo << stud[i].marks.informatics << endl;
					fo << stud[i].marks.chemistry << endl;
					fo << stud[i].rate << endl;
				}

			}
			fo.close();
		}

		else if (k == 2) {

			fi.open(path);

			if (!fi.is_open())
			{
				cout << "Reading file Error" << endl;
			}
			else
			{
				char ch;

				while (fi.get(ch)) {

					cout << ch;
				}
			}

			fi.close();

			cout << endl;
		}

		else if (k == 3) {

			fo.open(path, ofstream::app);
			if (!fo.is_open())
			{
				cout << "Open file Error (append)" << endl;
			}
			else
			{

				cout << "\nHow many new students you want to add? ";

				cin >> j;

				cout << "\t\t  Enter students info: ";

				for (int a = n + 1; a < n + j + 1; a++)
				{
					cout << "\nstudent surname: ";
					cin >> stud[a].surname;
					cout << "\nstudent birth year: ";
					cin >> stud[a].birthYear;
					cout << "\nstudent group number: ";
					cin >> stud[a].groupNumber;
					cout << "\nstudent physics mark: ";
					cin >> stud[a].marks.physics;
					cout << "\nstudent math mark: ";
					cin >> stud[a].marks.math;
					cout << "\nstudent informatics mark: ";
					cin >> stud[a].marks.informatics;
					cout << "\nstudent chemistry mark: ";
					cin >> stud[a].marks.chemistry;
					stud[a].rate = (stud[a].marks.chemistry + stud[a].marks.informatics + stud[a].marks.math + stud[a].marks.physics) / 4.;
					cout << "\nstudent rate is: " << stud[a].rate << endl;

					fo << stud[a].surname << endl;
					fo << stud[a].birthYear << endl;
					fo << stud[a].groupNumber << endl;
					fo << stud[a].marks.physics << endl;
					fo << stud[a].marks.math << endl;
					fo << stud[a].marks.informatics << endl;
					fo << stud[a].marks.chemistry << endl;
					fo << stud[a].rate << endl;
				}

			}
			fo.close();
		}
		else if (k == 4) {

			fi.open(path);

			if (!fi.is_open()) {

				cout << "Task 13 solving error" << endl;
			}
			else
			{

				int lines = numLines();

				int start = 0;

				stud[0] = Reading(0);

				for (int i = 0; i < lines / 8; i++) {

					stud[i] = Reading(start);

					start += 8;
				}

				for (int i = 0; i < lines / 8; i++) {

					stud[i].rate = (stud[i].marks.chemistry + stud[i].marks.informatics + stud[i].marks.math + stud[i].marks.physics) / 4.;

				}

				cout << "\nEnter number of the group you want to analyze: ";

				int number;

				cin >> number;

				double AveRate = 0;

				double amount = 0;

				for (int i = 0; i < (lines / 8); i++)
				{
					if (stud[i].groupNumber == number) {

						AveRate += stud[i].rate;

						amount++;
					}
				}

				AveRate /= amount;

				cout << "\nAverage Rate is: " << AveRate << endl;

				//cout << "Open file to check the data\n";

				cout << "\n TASK SOLVING: \n\n";

				for (int i = 0; i < (lines / 8); i++)
				{
					if (stud[i].groupNumber == number) {

						if (stud[i].rate >= AveRate) {

							cout << "\nstudent(" << i << ") surname: " << stud[i].surname;

							cout << "\nstudent(" << i << ") birth year: " << stud[i].birthYear;

							cout << "\nstudent(" << i << ") group number: " << stud[i].groupNumber;

							cout << "\nstudent(" << i << ") physics mark: " << stud[i].marks.physics;

							cout << "\nstudent(" << i << ") math mark: " << stud[i].marks.math;

							cout << "\nstudent(" << i << ") informatics mark: " << stud[i].marks.informatics;

							cout << "\nstudent(" << i << ") chemistry mark: " << stud[i].marks.chemistry;

							cout << "\nstudent(" << i << ") rate is: " << stud[i].rate << endl << endl;

						}
					}
				}

			}
			fi.close();
		}

		else if (k == 5) {

			cout << "Closing..";

			break;
		}

		else if (k == 6) {

			fo.open(path, ofstream::trunc);

			fo.close();

		}
	}

	return 0;
}