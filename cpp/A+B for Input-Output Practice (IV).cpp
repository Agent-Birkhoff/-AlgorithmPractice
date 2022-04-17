#include <iostream>

using namespace std;

int main()
{
	int N = 2;
	while (cin >> N)
	{
		if (N != 0)
		{
			int input = 0;
			for (int i = 0; i < N; i++)
			{
				int former = input;
				cin >> input;
				input += former;
			}
			cout << input << endl;
		}
		else
			break;
	}
}
