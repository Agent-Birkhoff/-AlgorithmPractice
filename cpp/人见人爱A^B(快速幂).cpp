#include <iostream>

using namespace std;

long long poww(int a, int b)
{
	long long result = 1;
	while (b)
	{
		if (b & 1)
			result = (result * a) % 1000;
		a = (a * a) % 1000;
		b = b >> 1;
	}
	return result;
}

int main()
{
	int A, B;
	while (cin >> A >> B, A + B != 0)
		cout << poww(A, B) << endl;
}
