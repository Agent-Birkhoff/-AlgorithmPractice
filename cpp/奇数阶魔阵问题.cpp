#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int len;
	cin >> len;
	vector<vector<int>> A(len, vector<int>(len));
	int  x = 1, y = (len + 1) / 2;
	A[x - 1][y - 1] = 1;

	for (int n = 2; n <= len * len; n++)
	{
		if ((n - 1) % len == 0)
		{
			x++;
			A[x - 1][y - 1] = n;
		}
		else
		{
			x -= 1;
			y += 1;
			if (x < 1)
				x = len;
			if (y > len)
				y = 1;
			A[x - 1][y - 1] = n;
		}
	}

	for (x = 1; x <= len; x++)
	{
		for (y = 1; y <= len; y++)
			cout << setw(5) << A[x - 1][y - 1];
		cout << endl;
	}
}
