#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		int input = 0;
		for (int j = 0; j < M; j++)
		{
			int former = input;
			cin >> input;
			input += former;
		}
		cout << input << endl;
		if (i < N - 1)
			cout << endl;
	}
}
