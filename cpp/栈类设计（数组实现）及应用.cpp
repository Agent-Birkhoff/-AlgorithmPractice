#include <iostream>

using namespace std;

class stack
{
public:
	stack() : n(0) {}

	bool empty()
	{
		if (n == 0)
			return true;
		else
			return false;
	}

	inline int size()
	{
		return n;
	}

	inline int top()
	{
		return s[n - 1];
	}

	inline void push(int input)
	{
		s[n] = input;
		n++;
	}

	inline void pop()
	{
		n--;
	}

private:
	int n;
	int s[100];
};

int main()
{
	stack s1, s2;
	int v, x;
	while (cin >> v >> x)
	{
		if (v == 1)
			s1.push(x);
		else
			s2.push(x);
	}

	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
}
