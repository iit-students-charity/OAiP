#include <iostream>
#include <ctime>

using namespace std;

struct Queue
{
	int info;
	Queue* next;
	Queue* prev;
};

void init(Queue** b, Queue** e, int in)
{
	Queue* t = new Queue;
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
Queue* add_beg(Queue*& v, int in)
{
	Queue* t = new Queue;
	t->info = in;
	t->next = v;
	t->prev = NULL;
	v->prev = t;
	return t;
}
Queue* add_end(Queue*& v, int in)
{
	Queue* t = new Queue;
	t->info = in;
	t->next = NULL;
	t->prev = v;
	v->next = t;
	return t;
}
void view_beg(Queue* p)
{	
	Queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}
void view_end(Queue* p)
{
	
	Queue* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}
void delete_element(Queue*& begin, Queue*& end, int N)
{
	
	Queue* key = NULL;
	Queue* q = end;
	Queue* t = begin;

	if (q == t)
	{
		cout << "There is only 1 element" << endl;
		return;
	}

	while (t)
	{
		if (t->info == N)
			key = t;
		t = t->next;
	}

	if (key == NULL)
	{
		return;
	}

	else
	{
		if (key == begin)
		{
			begin = begin->next;
			begin->prev = NULL;
			delete key;
		}
		else if (key == end)
		{
			end = end->prev;
			end->next = NULL;
			delete key;
		}
		else
		{
			key->prev->next = key->next;
			key->next->prev = key->prev;
			delete key;
		}
	}
}
int task(Queue* b)
{
	Queue* p = b;
	int max = b->info;

	for (p = b->next; p; p = p->next)
		if (p->info > max)
			max = p->info;

	return max;
}
void clean(Queue*& myQueue)
{
	Queue* temp = NULL;

	while (myQueue->next != NULL)
	{
		temp = myQueue->prev;
		myQueue->prev = myQueue->prev->next;
		delete temp;
	}

	myQueue->next = NULL;
}
int main()
{
	srand(time(NULL));
	Queue* begin = NULL;
	Queue* end = NULL;
	int opt;
	int opt_view = 1;

	while (true)
	{
		if (opt_view == 1)
		{
			view_beg(begin);
		}

		else if (opt_view == 0)
		{
			view_end(end);
		}

		cout << endl << "Enter 1 to fill up the queue with random numbers" << endl << "Enter 2 to delete the maximum element from the queue" << endl << "Enter 3 to add elemnt (begin or end)" << endl << "Enter 4 to change view/add mode. Now is ";

		if (opt_view == 1)
		{
			cout << "from the begining" << endl;
		}

		else
		{
			cout << "from the end" << endl;
		}

		cout << "Enter 5 to exit" << endl << endl;
		cin >> opt;
		cout << endl;

		switch (opt)
		{
		case 1:
		{
			int size;
			cout << "Enter the queue size" << endl;
			cin >> size;
			cout << endl;
			init(&begin, &end, rand() %30 - 10);

			for (int i = 0; i < size - 1; i++)
			{
				begin = add_beg(begin, rand() %30 - 10);
			}

			break;
		}
		case 2:
		{
			if (begin == NULL)
			{
				cout << "There is no elements! Nothing to delete" << endl;
				break;
			}

			int max = task(begin);
			delete_element(begin, end, max); 

			break;
		}
		case 3:
		{
			if (begin == NULL)
			{
				cout << "First press 1 to init queue" << endl;
				break;
			}

			int number;
			cout << "Enter the number you want to add: ";
			cin >> number;
			cout << endl;

			if (opt_view == 1)
			{
				begin = add_beg(begin, number);
			}

			else
			{
				end = add_end(end, number);
			}
			break;
		}
		case 4:
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
		case 5:
		{
			return 0;
		}
		}
	}
	clean(begin);
	return 0;
}