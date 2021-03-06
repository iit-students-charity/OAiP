#include "stdafx.h"
#include <iostream>

using namespace std;

struct queue
{
	int info;
	queue* next;
	queue* prev;
};

void init(queue**, queue**, int);
queue* add_beg(queue*&, int);
queue* add_end(queue*&, int);
void view_beg(queue*);
void view_end(queue*);
queue* task(queue*, queue*&);

int main()
{
	queue* begin_ = NULL;
	queue* end_ = NULL;
	int opt;
	int opt_view = 1;
	while (true)
	{
		if (opt_view == 1)
		{
			view_beg(begin_);
		}
		else if (opt_view == 0)
		{
			view_end(end_);
		}
		cout << endl << "Enter 1 to fill up the queue with random numbers" << endl <<
			"Enter 2 to delete every 2nd element from the queue" << endl <<
			"Enter 3 to change view mode. Now is ";
		if (opt_view == 1)
		{
			cout << "from the begining" << endl;
		}
		else
		{
			cout << "from the end" << endl;
		}
		cout << "Enter 4 to exit" << endl << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
			case 1:
			{
				int size;
				cout << "Enter the queue size" << endl;
				cin >> size;
				init(&begin_, &end_, rand());
				for (int i = 0; i < size - 1; i++)
				{
					begin_ = add_beg(begin_, rand());
				}
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Old queue" << endl;
				if (opt_view == 1)
				{
					view_beg(begin_);
				}
				else if (opt_view == 0)
				{
					view_end(end_);
				}
				cout << endl << "New queue" << endl;
				begin_ = task(begin_, end_);
				if (opt_view == 1)
				{
					view_beg(begin_);
				}
				else if (opt_view == 0)
				{
					view_end(end_);
				}
				system("pause");
				break;
			}
			case 3:
			{
				if (opt_view == 1)
				{
					opt_view = 0;
				}
				else
				{
					opt_view = 1;
				}
				break;
			}
			case 4:
			{
				return 0;
			}
		}
		system("cls");
	}
	system("pause");
    return 0;
}

void init(queue** b, queue** e, int in) 
{
	queue *t = new queue;
	t->info = in;		
	t->next = NULL;		
	if (*b == NULL)
	{
		*b = *e = t;
	}
	else 
	{
		(*e)->next = t;
		*e = t;
	}
}

queue* add_beg(queue* &v, int in)
{
	queue *t = new queue;
	t->info = in;
	t->next = v;
	t->prev = NULL;
	v->prev = t;
	return t;
}
queue* add_end(queue* &v, int in)
{
	queue *t = new queue;
	t->info = in;
	t->next = NULL;
	t->prev = v;
	v->next = t;
	return t;
}
void view_beg(queue* p)
{
	queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}
void view_end(queue* p)
{
	queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}
queue* task(queue* b, queue* &e)
{
	queue* t1 = b;
	queue* t2 = b->next;

	while (t2->next != NULL)
	{
		t1->next = t2->next;
		t2->next->prev = t1;
		t1 = t2->next;
		delete t2;
		if (t1->next != NULL)
		{
			t2 = t1->next;
		}
		else
		{
			e = t1;
			return b;
		}
		if (t2->next == NULL)
		{
			t1->next = t2->next;
			delete t2;
			e = t1;
			return b;
		}
	}
	return t2;
}