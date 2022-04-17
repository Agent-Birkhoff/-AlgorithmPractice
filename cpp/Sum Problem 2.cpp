#include <iostream>

using namespace std;

int main()
{
	int sum;
	long long input;
	while (cin >> input)
	{
		if (input % 2 == 0)
			sum = (1 + input) * input / 2;
		else
		{
			sum = (1 + input) * (input - 1) / 2 + (input + 1) / 2;
		}
		cout << sum << endl << endl;
	}
}
