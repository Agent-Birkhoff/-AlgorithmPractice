#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int result = 1;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			if (input % 2 != 0)
				result *= input;
		}
		cout << result << endl;
	}
}
