#include <iostream>

using namespace std;

long long poww(long long a, long long b)
{
    long long result = 1;
    while (b)
    {
        if (b & 1)
            result = (result * a) % 10;
        a = (a * a) % 10;
        b = b >> 1;
    }
    return result;
}

int main()
{
    long long T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << poww(N, N) << endl;
    }
}
