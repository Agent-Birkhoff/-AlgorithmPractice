#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        long long *Mi = new long long[N];
        for (int i = 0; i < N; i++)
            cin >> Mi[i];
        sort(Mi, Mi + N);
        long long sum = 0;
        for (int i = 0; i < N; i++)
            sum += Mi[i];
        if (Mi[N - 1] - 1 <= sum - Mi[N - 1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        delete[] Mi;
    }
}
