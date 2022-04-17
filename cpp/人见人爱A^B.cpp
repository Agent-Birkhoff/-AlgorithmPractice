#include <iostream>

using namespace std;

int main()
{
    int A, B;
    while (cin >> A >> B)
    {
        long long result = 1;
        if (A + B == 0)
            break;
        for (int i = 1; i <= B; i++)
            result = result * A % 1000;
        cout << result << endl;
    }
}
