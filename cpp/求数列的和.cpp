#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double n, m;
    while (cin >> n >> m)
    {
        double sum = n;
        for (int i = 2; i <= m; i++)
        {
            n = sqrt(n);
            sum += n;
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
}
