#include <iostream>

using namespace std;

long long lcm(long long a, long long b)
{
    long long c = a * b;
    long long r = 0;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return c / a;
}

int main()
{
    long long A, B;
    while (cin >> A >> B)
        cout << lcm(A, B) << endl;
}
