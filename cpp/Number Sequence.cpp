#include <iostream>

using namespace std;

int main()
{
	int f[200];
	int A, B, n;
	cin >> A >> B >> n;
	while (A)
	{
		if (n >= 3)
		{
			f[1] = 1;
			f[2] = 1;
			int i;
			for (i = 3; i < 200; i++)
			{
				f[i] = (A * f[i - 1] + B * f[i - 2]) % 7;
				if (f[i - 1] == 1 && f[i] == 1)
					break;
			}
			i -= 2;
			n %= i;
			if (n == 0)
				cout << f[i] << endl;
			else
				cout << f[n] << endl;
		}
		else
			cout << "1" << endl;
		cin >> A >> B >> n;
	}
}
