#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int start, direction;
    long long way[51] = {0};
    way[2] = 1;
    way[3] = 2;
    for (int i = 4; i <= 50; i++)
        way[i] = way[i - 1] + way[i - 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> start >> direction;
        cout << way[direction - start + 1] << endl;
    }
}
