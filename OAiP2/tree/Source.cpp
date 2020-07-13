#include <string>
#include <iostream>
#include <math.h>

using namespace std;

struct Tree
{
	int info;
	string str;
	Tree* left;
	Tree* right;
};

Tree* init(int inf, string str)
{
	Tree* t = new Tree;
	t->info = inf;
	t->str = str;
	t->left = t->right = NULL;
	return t;
}
void add(Tree* root, int key, string str)
{
	Tree* prev = NULL;
	Tree* t = NULL;
	bool find = true;
	t = root;
	while (t && find)
	{
		prev = t;
		if (key == t->info)
		{
			find = false;
			cout << "Invalid Key!" << endl;
		}
		else if (key < t->info)
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}
	if (find)
	{
		t = init(key, str);
		if (key < prev->info)
		{
			prev->left = t;
		}
		else
		{
			prev->right = t;
		}
	}
}
void view(Tree* p, int level)
{
	string str;
	if (p)
	{
		view(p->right, level + 1);
		for (int i = 0; i < level; i++)
		{
			str = str + "     ";
		}
		cout << str << p->info << "  " << p->str << "\n";
		view(p->left, level + 1);
	}
}
Tree* del_info(Tree* root, int key)
{
	Tree* dlt = root;
	Tree* Prev_Del = NULL;
	Tree* R = NULL;
	Tree* Prev_R = NULL;
	while (dlt != NULL && dlt->info != key)
	{
		Prev_Del = dlt;
		if (dlt->info > key)
		{
			dlt = dlt->left;
		}
		else
		{
			dlt = dlt->right;
		}
	}
	if (dlt == NULL)
	{
		cout << "Invalid key!" << endl;
		return root;
	}

	if (dlt == root)
	{
		cout << "Invalid key!" << endl;
		return root;
	}

	if (dlt->right == NULL)
	{
		R = dlt->left;
	}
	else if (dlt->left == NULL)
	{
		R = dlt->right;
	}
	else
	{
		Prev_R = dlt;
		R = dlt->left;
		while (R->right != NULL)
		{
			Prev_R = R;
			R = R->right;
		}
		if (Prev_R == dlt)
		{
			R->right = dlt->right;
		}
		else
		{
			R->right = dlt->right;
			Prev_R->right = R->left;
			R->left = Prev_R;
		}
	}
	if (dlt == root)
	{
		root = R;
	}
	else if (dlt->info < Prev_Del->info)
	{
		Prev_Del->left = R;
	}
	else
	{
		Prev_Del->right = R;
	}
	delete dlt;
	return root;
}
void del(Tree* t)
{
	if (t != NULL)
	{
		del(t->left);
		del(t->right);
		delete t;
	}
}
void run(Tree* p, int* arr, int* cnt, string* str) {
	if (p)
	{
		run(p->right, arr, cnt, str);
		arr[*cnt] = p->info;
		str[*cnt] = p->str;
		(*cnt)++;
		run(p->left, arr, cnt, str);
	}
}
void ballance(Tree** p, int n, int k, int* a, string* str)
{
	if (n == k)
	{
		*p = NULL;
		return;
	}
	else
	{
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = a[m];
		(*p)->str = str[m];
		ballance(&(*p)->left, n, m, a, str);
		ballance(&(*p)->right, m + 1, k, a, str);
	}
}
void Find(Tree* p, int key)
{
	while (p)
	{
		if (key == p->info)
		{
			cout << "Key information: " << p->info << "  " << p->str;
			break;
		}

		if (key > p->info)
			p = p->right;

		if (key < p->info)
			p = p->left;
	}
	cout << endl;
}
void task(Tree* p, int* a, double m, int count)
{
	double remainder[256];

	for (int i = 0; i < count; i++)
		remainder[i] = fabs(a[i] - m);

	double key = remainder[0];
	int index;

	for (int i = 1; i < count; i++)
	{
		if (remainder[i] < key)
		{
			key = remainder[i];
			index = i;
		}
	}

	key = a[index];
	Find(p, key);
}

int main()
{
	int val;
	string str;
	cout << "Enter an initial node info: ";
	cin >> val;
	cout << "Enter an initial node str: ";
	cin >> str;
	Tree* root = init(val, str);
	int key = -1;
	int count;

	while (key != 0)
	{
		cout << "0 - exit\n1 - Read tree\n2 - Balance tree\n3 - Add element\n4 - Find\n5 - Delete element\n6 - Task\n";
		cin >> key;

		if (key == 1)
		{
			cout << endl << "Your tree: " << endl;
			view(root, 0);
		}

		if (key == 2)
		{
			count = 0;
			int arr[256];
			string txt[256];
			run(root, arr, &count, txt);
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (arr[i] > arr[j])
					{
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;

						string stemp = txt[i];
						txt[i] = txt[j];
						txt[j] = stemp;
					}
				}
			}

			ballance(&root, 0, count, arr, txt);
		}

		if (key == 3)
		{
			cout << endl << "Enter a count of elements: ";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				cout << "Enter info of " << i << " node: ";
				cin >> val;
				cout << "Enter str of " << i << " node: ";
				cin >> str;
				add(root, val, str);
			}
		}

		if (key == 4)
		{
			int find;
			cout << "Enter the key of element you want to find:";
			cin >> find;
			Find(root, find);
		}

		if (key == 5)
		{
			cout << "Enter a value to delete: ";
			cin >> val;
			del_info(root, val);
		}

		if (key == 6)
		{
			count = 0;
			string txt[256];
			int arr[256];
			run(root, arr, &count, txt);
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = i + 1; j < count; j++)
				{
					if (arr[i] > arr[j])
					{
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}

			bool tsk = true;
			double m = 0;

			for (int i = 0; i < count; i++)
			{
				m = m + arr[i];
			}

			m = m / count;

			for (int i = 0; i < count; i++)
			{
				if (arr[i] == m)
				{
					Find(root, m);
					tsk = false;
					break;
				}
			}

			if (tsk)
			{
				task(root, arr, m, count);
			}
			
		}
		
	}

	del(root);
}

/* 13. Между максимальным и минимальным значениями ключей найти
запись с ключом со значением, ближайшим к среднему значению. */
