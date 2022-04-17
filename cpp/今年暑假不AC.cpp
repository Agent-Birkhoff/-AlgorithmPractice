#include <iostream>
#include <algorithm>

using namespace std;

struct program
{
    int startTime;
    int endTime;
};

bool compare(program a, program b)
{
    return a.endTime < b.endTime;
}

int main()
{
    int n, ans, endT;
    program item[101];
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> item[i].startTime >> item[i].endTime;
        }
        sort(item, item + n, compare);
        ans = 1;
        endT = item[0].endTime;
        for (int i = 1; i < n; i++)
        {
            if (item[i].startTime >= endT)
            {
                ans++;
                endT = item[i].endTime;
            }
        }
        cout << ans << endl;
    }
}
