#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


struct Stack { 

	int element;	

	Stack* next;	

};

void s_push(Stack** top, int a) { 

	Stack* q;

	q = new Stack(); 

	q->element = a; 

	if (top == NULL) { 

		*top = q;
	}

	else {

		q->next = *top; 

		*top = q; 
	}
}

void s_delete_element(Stack** top, int N) {

	Stack* q = *top;

	Stack* prev = NULL;

	while (q != NULL) {

		if (q->element == N) {

			if (q == *top) {

				*top = q->next;

				free(q);

				q->element = NULL;

				q->next = NULL;
			}

			else {
			
				prev->next = q->next;

				free(q);

				q->element = NULL;

				q->next = NULL;

			}
		}	

		prev = q; 

		q = q->next; 
	}
}

int Max(Stack* b)
{
	Stack* p;

	int max = b->element;

	for (p = b->next; p; p = p->next)
		if (p->element > max)
			max = p->element;

	cout << "Max element is " << max << endl;

	return max;
}

void s_print(Stack* top) {		

	Stack* q = top;

	cout << endl;

	while (q) {

		cout << q->element << "  ";

		q = q->next;

	}

	cout << endl << endl;
}

void s_del(Stack** p) {

	Stack* t;

	while (*p != NULL) {

		t = *p;

		*p = (*p)->next;

		delete t;
	}
}

void s_sort_a(Stack** p) {

	if ((*p)->next == NULL) return;

	Stack* t = NULL, * t1, * r;

	if ((*p)->next->next == NULL) return;

	do {

		for (t1 = *p; t1->next->next != t; t1 = t1->next)

			if (t1->next->element < t1->next->next->element) {

				r = t1->next->next;

				t1->next->next = r->next;

				r->next = t1->next;

				t1->next = r;
			}

		t = t1->next;

	} while ((*p)->next->next != t);

}

void s_sort_info(Stack* p) {

	Stack* t = NULL, * t1;

	if (p->next == NULL) return;

	int r;

	do {
		for (t1 = p; t1->next != t; t1 = t1->next)

			if (t1->element < t1->next->element) {

				r = t1->element;

				t1->element = t1->next->element;

				t1->next->element = r;
			}

		t = t1;

	} while (p->next != t);
}



int main() {	//  13. В созданном списке определить максимальное значение и удалить его.

	srand(time(0));

	Stack* top = NULL; 

	int size, value;

	int mode = 2048;

	while (mode !=0 ) {

		cout << "0 - exit\n1 - fill in a Stack with a random numbers\n2 - read the Stack\n3 - adress sort Stack\n4 - info sort Stack\n5 - delete element\n6 - technical task\n\n";

		cin >> mode;

		if (mode == 1) {

			cout << "\nEnter the size of Stack: ";

			cin >> size;

			cout << endl;

			for (int i = 0; i < size; i++) {

				value = rand() % 20 - 5;

				s_push(&top, value);

			}

		}

		else if (mode == 2) {

			s_print(top);

		}

		else if (mode == 3) {

			s_push(&top, 2048);

			s_sort_a(&top);

			s_delete_element(&top, top->element);

			cout << "\nStack is sorted (adress)\n\n";
		}

		else if (mode == 4) {

			s_sort_info(top);

			cout << "\nStack is sorted (info)\n\n";

		}

		else if (mode == 5) {

			int number;

			cout << "\nEnter the number you want to delete: ";

			cin >> number;

			cout << endl;

			s_delete_element(&top, number);
		}

		else if (mode == 6) {

			int max = Max(top);

			s_delete_element(&top, max);
			
		}

	}

	s_del(&top);

	return 0;

}
