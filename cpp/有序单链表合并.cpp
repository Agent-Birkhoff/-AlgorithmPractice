#include <iostream>

using namespace std;

struct node {
	int num;
	struct node* next;
};

int main()
{
	struct node* even = new(struct node);
	struct node* odd = new(struct node);
	even->next = NULL;
	even->num = 0;
	odd->next = NULL;
	odd->num = 0;
	int input;
	struct node* p;
	while (1)
	{
		cin >> input;
		if (input == 0)
			break;
		struct node* n = new(struct node);
		n->num = input;
		if (input % 2 == 0)
		{
			p = even;
			while (p)
			{
				if (p->next == NULL)
				{
					p->next = n;
					n->next = NULL;
					break;
				}
				else if (input <= p->next->num)
				{
					n->next = p->next;
					p->next = n;
					break;
				}
				p = p->next;
			}
		}
		else
		{
			p = odd;
			while (p)
			{
				if (p->next == NULL)
				{
					p->next = n;
					n->next = NULL;
					break;
				}
				else if (input <= p->next->num)
				{
					n->next = p->next;
					p->next = n;
					break;
				}
				p = p->next;
			}
		}
	}

	p = odd->next;
	while (p)
	{
		cout << p->num;
		if (p->next)
			cout << "->";
		p = p->next;
	}
	cout << endl;
	p = even->next;
	while (p)
	{
		cout << p->num;
		if (p->next)
			cout << "->";
		p = p->next;
	}
	cout << endl;

	struct node* q = even->next;
	while (q)
	{
		struct node* i = new(struct node);
		i->num = q->num;
		p = odd;
		while (p)
		{
			if (p->next == NULL)
			{
				p->next = i;
				i->next = NULL;
				break;
			}
			else if (i->num <= p->next->num)
			{
				i->next = p->next;
				p->next = i;
				break;
			}
			p = p->next;
		}
		q = q->next;
	}

	p = odd->next;
	while (p)
	{
		cout << p->num;
		if (p->next)
			cout << "->";
		p = p->next;
	}
	cout << endl;

	p = even;
	while (p)
	{
		struct node* d = p->next;
		delete p;
		p = d;
	}
	p = odd;
	while (p)
	{
		struct node* d = p->next;
		delete p;
		p = d;
	}
}
