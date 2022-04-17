#include <iostream>

using namespace std;

class set {
public:
	bool find(int a);
	void add(int a);
	void del(int a);
	set operator + (const set& a);
	set operator && (const set& a);
	set operator - (const set& a);
	void show();
private:
	int num[100] = { 0 };
	int n = 0;
};

bool set::find(int a)
{
	for (int i = 0; i < n; i++)
	{
		if (num[i] == a)
			return true;
	}
	return false;
}

void set::add(int a)
{
	if (!find(a))
	{
		num[n] = a;
		n++;
	}
}

void set::del(int a)
{
	for (int i = 0; i < n; i++)
	{
		if (num[i] == a)
		{
			for (int j = i; j < n - 1; j++)
				num[j] = num[j + 1];
			n--;
			return;
		}
	}
}

set set::operator + (const set& a)
{
	set U = *this;
	for (int i = 0; i < a.n; i++)
		U.add(a.num[i]);
	return U;
}

set set::operator && (const set& a)
{
	set I;
	for (int i = 0; i < a.n; i++)
	{
		if (find(a.num[i]))
			I.add(a.num[i]);
	}
	return I;
}

set set::operator - (const set& a)
{
	set D = *this;
	for (int i = 0; i < a.n; i++)
	{
		if (D.find(a.num[i]))
			D.del(a.num[i]);
	}
	return D;
}

void set::show()
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int n = 0; n < i; n++)
		{
			if (num[n] > num[n + 1])
			{
				int temp = num[n];
				num[n] = num[n + 1];
				num[n + 1] = temp;
			}
		}
	}

	cout << "{";
	for (int i = 0; i < n; i++)
	{
		cout << num[i];
		if (i != n - 1)
			cout << ",";
	}
	cout << "}" << endl;
}

int main()
{
	int m, n;
	set A, B;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		A.add(input);
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		B.add(input);
	}
	set U = A + B;
	set I = A && B;
	set D = A - B;

	A.show();
	B.show();
	U.show();
	I.show();
	D.show();
}
