#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
	int len;
	cin >> len;
	vector<vector<int>> num(len, vector<int>(len));

	int n = 1;
	int x = 1, y = 1;
	int U = 1, D = len, L = 2, R = len;
	char dir = 'D';
	while (n <= len * len)
	{
		switch (dir)
		{
		case 'U':
			if (x == U)
			{
				num[x - 1][y - 1] = n;
				dir = 'L';
				y--;
				U++;
			}
			else
			{
				num[x - 1][y - 1] = n;
				x--;
			}
			break;
		case 'D':
			if (x == D)
			{
				num[x - 1][y - 1] = n;
				dir = 'R';
				y++;
				D--;
			}
			else
			{
				num[x - 1][y - 1] = n;
				x++;
			}
			break;
		case 'L':
			if (y == L)
			{
				num[x - 1][y - 1] = n;
				dir = 'D';
				x++;
				L++;
			}
			else
			{
				num[x - 1][y - 1] = n;
				y--;
			}
			break;
		case 'R':
			if (y == R)
			{
				num[x - 1][y - 1] = n;
				dir = 'U';
				x--;
				R--;
			}
			else
			{
				num[x - 1][y - 1] = n;
				y++;
			}
			break;
		}
		n++;
	}

	for (x = 1; x <= len; x++)
	{
		for (y = 1; y <= len; y++)
			cout << setw(4) << num[x - 1][y - 1];
		cout << endl;
	}
}
