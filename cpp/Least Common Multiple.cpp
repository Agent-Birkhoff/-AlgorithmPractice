#include <iostream>

using namespace std;

long long lcm(long long a, long long b)
{
	long long c = a * b;
	long long r = 0;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return c / a;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		long long a;
		int b;
		cin >> t;
		cin >> a;
		for (int i = 1; i < t; i++)
		{
			cin >> b;
			a = lcm(a, b);
		}
		cout << a << endl;
	}
}
