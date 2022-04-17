#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x[201] = {0}, N, i, j, a, b, ans;
		ans = 0;
		cin >> N;
		for (i = 1; i <= N; i++)
		{
			cin >> a >> b;
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			for (j = min(a, b); j <= max(a, b); j++)
				x[j]++;
		}
		for (i = 1; i <= 200; i++)
		{
			if (x[i] > ans)
				ans = x[i];
		}
		cout << ans * 10 << endl;
	}
}
