#include <iostream>

using namespace std;

int main()
{
	int n;
	long long num[51] = {0};
	num[1] = 3;
	num[2] = 6;
	num[3] = 6;
	while (cin >> n)
	{
		for (int i = 4; i <= n; i++)
			num[i] = num[i - 1] + 2 * num[i - 2];
		cout << num[n] << endl;
	}
}
