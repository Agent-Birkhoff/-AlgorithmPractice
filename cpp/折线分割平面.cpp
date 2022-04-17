#include <iostream>

using namespace std;

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int n;
        long long sum;
        cin >> n;
        sum = n * n * 2 - n + 1;
        cout << sum << endl;
    }
}
