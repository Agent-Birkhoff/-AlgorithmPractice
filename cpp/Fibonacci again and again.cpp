#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int SG[1001];
	bool vis[1001];
	int step[20];
	step[1] = 1;
	step[2] = 2;
	for (int i = 3; i < 20; i++)
		step[i] = step[i - 1] + step[i - 2];

	int m, n, p;
	memset(SG, 0, sizeof(SG));
	for (int i = 1; i <= 1000; i++)
	{
		memset(vis, false, sizeof(vis));
		for (int j = 1; i - step[j] >= 0; j++)
			vis[SG[i - step[j]]] = 1;
		int k = 0;
		while (vis[k])
			k++;
		SG[i] = k;
	}

	while (cin >> n >> m >> p, m + n + p != 0)
	{
		if (SG[n] ^ SG[m] ^ SG[p])
			cout << "Fibo" << endl;
		else
			cout << "Nacci" << endl;
	}
}
