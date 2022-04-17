#include <iostream>

using namespace std;

int main()
{
	int N = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int m = 2;
		cin >> m;
		int input = 0;
		for (int j = 0; j < m; j++)
		{
			int former = input;
			cin >> input;
			input += former;
		}
		cout << input << endl;
	}
}
