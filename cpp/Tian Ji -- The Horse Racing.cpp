#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{

    int T[1001];
    int vis[1001];
    int K[1001];
    int n;
    while (cin >> n && n != 0)
    {
        memset(T, 0, sizeof(T));
        memset(K, 0, sizeof(K));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            cin >> T[i];
        for (int i = 0; i < n; i++)
            cin >> K[i];

        sort(T, T + n, greater<int>());
        sort(K, K + n, greater<int>());

        int sum = 0;
        int Tfirst = 0, Tend = n - 1;
        int Kfirst = 0, Kend = n - 1;
        while (n--)
        {

            if (T[Tfirst] > K[Kfirst])
            {
                sum++;
                Tfirst++;
                Kfirst++;
            }
            else if (T[Tend] > K[Kend])
            {
                sum++;
                Tend--;
                Kend--;
            }
            else if (T[Tend] < K[Kfirst])
            {
                sum--;
                Tend--;
                Kfirst++;
            }
        }
        cout << sum * 200 << endl;
    }
}
