#include <iostream>
#include <vector>

using namespace std;

long Dx[4] = { 0, 0, 1, -1 };
int Dy[4] = { 1, -1, 0, 0 };

int Xm, Ym, sum = 0;
vector<int> M;
vector<bool> vis;

void DFS(int x, int y, int v)
{
	vis[int(x) * Ym + y] = true;
	for (int i = 0; i < 4; i++)
	{
		int x2 = x + Dx[i];
		int y2 = y + Dy[i];
		if (x2 < Xm && y2 < Ym && x2 >= 0 && y2 >= 0 && vis[int(x2) * Ym + y2] == false && M[int(x2) * Ym + y2] == v)
			DFS(x2, y2, v);
	}
}

int main()
{
	cin >> Xm >> Ym;
	for (int i = 0; i < Xm * Ym; i++)
	{
		int num;
		cin >> num;
		M.push_back(num);
		vis.push_back(false);
	}

	for (int x = 0; x < Xm; x++)
	{
		for (int y = 0; y < Ym; y++)
		{
			if (x < Xm && y < Ym && x >= 0 && y >= 0 && vis[int(x) * Ym + y] == false)
			{
				DFS(x, y, M[int(x) * Ym + y]);
				sum++;
			}
		}
	}
	cout << sum << endl;
}
