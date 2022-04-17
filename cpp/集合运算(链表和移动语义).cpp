#include <iostream>

using namespace std;

class set
{
private:
	struct node
	{
		int num;
		node* next;
	}*head;
public:
	set();
	set(const set& a);
	set(set&& a) noexcept;
	~set();
	set& operator = (const set& a);
	set& operator = (set&& a) noexcept;

	bool find(int a) const;
	void add(int a);
	void del(int a);
	set operator + (const set& a) const;
	set operator && (const set& a) const;
	set operator - (const set& a) const;

	void show();
};

set::set()
{
	head = new node;
	head->num = 0;
	head->next = NULL;
}

set::set(const set& a)
{
	head = new node;
	head->num = 0;
	node* end = head;
	for (node* i = a.head->next; i != NULL; i = i->next)
	{
		node* insert = new node;
		insert->num = i->num;
		end->next = insert;
		end = insert;
	}
	end->next = NULL;
}

set::set(set&& a) noexcept
{
	head = a.head;
	a.head = NULL;
}

set::~set()
{
	while (head)
	{
		node* t = head;
		head = head->next;
		delete t;
	}
}

set& set::operator = (const set& a)
{
	set temp = a;
	*this = move(a);
	return *this;
}

set& set::operator = (set&& a) noexcept
{
	node* t = head;
	head = a.head;
	a.head = t;
	return *this;
}

bool set::find(int a) const
{
	for (node* i = head->next; i != NULL; i = i->next)
	{
		if (i->num == a)
			return true;
	}
	return false;
}

void set::add(int a)
{
	node* former = head;
	node* i = head->next;
	while (1)
	{
		if (i == NULL || i->num > a)
		{
			node* insert = new node;
			insert->num = a;
			insert->next = i;
			former->next = insert;
			return;
		}
		else if (i->num == a)
			return;
		former = former->next;
		i = i->next;
	}
}

void set::del(int a)
{
	node* former = head;
	for (node* i = head->next; i != NULL; i = i->next, former = former->next)
	{
		if (i->num == a)
		{
			former->next = i->next;
			delete i;
			return;
		}
	}
}

set set::operator + (const set& a) const
{
	set U = *this;
	for (node* i = a.head->next; i != NULL; i = i->next)
		U.add(i->num);
	return U;
}

set set::operator && (const set& a) const
{
	set I;
	for (node* i = a.head->next; i != NULL; i = i->next)
	{
		if (this->find(i->num))
			I.add(i->num);
	}
	return I;
}

set set::operator - (const set& a) const
{
	set D = *this;
	for (node* i = a.head->next; i != NULL; i = i->next)
	{
		if (D.find(i->num))
			D.del(i->num);
	}
	return D;
}

void set::show()
{
	cout << "{";
	for (node* i = head->next; i != NULL; i = i->next)
	{
		cout << i->num;
		if (i->next != NULL)
			cout << ",";
	}
	cout << "}" << endl;
}

int main()
{
	set A, B;
	int m, n, input;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		A.add(input);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		B.add(input);
	}
	A.show();
	B.show();
	set T = move(A + B);
	T.show();
	T = move(A && B);
	T.show();
	T = move(A - B);
	T.show();
}
