#include <iostream>

using namespace std;

int main()
{
    long long num[51];
    int n;
    num[1] = 1;
    num[2] = 2;
    for (int i = 3; i <= 50; i++)
        num[i] = num[i - 1] + num[i - 2];
    while (cin >> n)
        cout << num[n] << endl;
}
