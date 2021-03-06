#include "stdafx.h"
#include <iostream>

using namespace std;

struct Stack
{
	Stack* next;
	int info;
};

Stack* push(Stack*, int);
Stack* pop(Stack*, int*);
void view(Stack*);
void clear(Stack**);
Stack* task(Stack*);

int main()
{
	Stack* my_stack = NULL;
	int opt;
	while (true)
	{
		view(my_stack);
		if (my_stack != NULL)
		{
			cout << endl;
		}
		cout << "Enter 1 to fill up the stack with random numbers" << endl <<
			"Enter 2 to eject an element from the stack" << endl <<
			"Enter 3 to clear all stack" << endl <<
			"Enter 4 to delete every 2nd element from the stack" << endl <<
			"Enter 5 to exit" << endl << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
			case 1:
				{
				cout << "Enter the stack size" << endl;
				int size;
				cin >> size;
					for (int i = 0; i < size; i++)
					{
						my_stack = push(my_stack, rand());
					}
					break;
				}
			case 2:
				{
					int a;
					my_stack = pop(my_stack, &a);
					cout << a << " was ejected" << endl;
					system("pause");
					break;
				}
			case 3:
				{
					clear(&my_stack);
					break;
				}
			case 4:
			{
				system("cls");
				cout << "Old stack:" << endl;
				view(my_stack);
				my_stack = task(my_stack);
				cout << endl << "New stack:" << endl;
				view(my_stack);
				system("pause");
				break;
			}
			case 5:
				{
					clear(&my_stack);
					return 0;
				}
		}
		system("cls");
	}
}

Stack* push(Stack* p, int in)
{
	Stack* temp = new Stack;
	temp->info = in;
	temp->next = p;
	return temp;
}
Stack* pop(Stack* p, int* out)
{
	Stack* temp = p;
	*out = p->info;
	p = p->next;
	delete temp;
	return p;
}
void view(Stack* p)
{
	Stack* temp = p;
	while (temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	}
}
void clear(Stack** p) {
	Stack* temp;
	while (*p != NULL) {
		temp = *p;
		*p = (*p)->next;
		delete temp;
	}
}
Stack* task(Stack* p)
{
	Stack* temp1 = p;
	Stack* temp2 = p->next;
	
	while (temp2->next != NULL)
	{
		temp1->next = temp2->next;
		temp1 = temp2->next;
		delete temp2;
		if (temp1->next != NULL)
		{
			temp2 = temp1->next;
		}
		else return p;
		if (temp2->next == NULL)
		{
			temp1->next = temp2->next;
			delete temp2;
			return p;
		}
	}
	
}