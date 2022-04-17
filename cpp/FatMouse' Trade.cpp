#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using namespace std;

struct trade
{
    double J;
    double F;
} room[1000];

int compare(trade a, trade b)
{
    return a.J / a.F > b.J / b.F;
}

int main()
{
    int M, N;
    double sum;
    while (cin >> M >> N, (M != -1 && N != -1))
    {
        sum = 0;
        for (int i = 0; i < N; i++)
            cin >> room[i].J >> room[i].F;

        sort(room, room + N, compare);
        for (int i = 0; i < N; i++)
        {
            if (M - room[i].F > 0.001)
            {
                sum += room[i].J;
                M -= room[i].F;
            }
            else
            {
                sum += M * room[i].J / room[i].F;
                break;
            }
        }
        printf("%.3lf\n", sum);
        //cout << fixed << setprecision(3) << sum << endl;
    }
}
