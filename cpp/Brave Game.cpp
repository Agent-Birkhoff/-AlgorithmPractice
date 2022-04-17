#include <iostream>

using namespace std;

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		int n, m;
		cin >> n >> m;
		if (n % (m + 1) == 0)
			cout << "second" << endl;
		else
			cout << "first" << endl;
	}
}
