#include <iostream>

using namespace std;

int main()
{
    int N = 0, M = 0, i = 0, sum = 0, a[41] = {0};
    cin >> N;
    a[1] = 1;
    a[2] = 1;
    for (i = 3; i <= 40; i++)
        a[i] = a[i - 1] + a[i - 2];
    while (N--)
    {
        cin >> M;
        cout << a[M] << endl;
    }
}
