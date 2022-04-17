#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int a)
{
	int sum = 0;
	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
			sum = sum + i;
	}
	if (sum == a)
		return true;
	else
		return false;
}

int main()
{
	vector<int> num;
	int a;
	while (cin >> a)
		num.push_back(a);
	int n = count_if(num.begin(), num.end(), f);
	if (n == 0)
		cout << 0 << endl << "none" << endl;
	else
	{
		vector<int>::iterator first = find_if(num.begin(), num.end(), f);
		cout << n << endl << distance(num.begin(), first) + 1 << "	" << *first << endl;
	}
}
