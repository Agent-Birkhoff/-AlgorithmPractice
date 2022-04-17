#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> material;
    int sum = 0;
    string input;
    while (cin >> input)
    {
        vector<string>::iterator f = find(material.begin(), material.end(), input);
        if (f == material.end())
        {
            material.push_back(input);
            sum++;
        }
    }
    cout << sum << endl;
}
