#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool isPrime(int input)
{
	int i;
	for (i = 2; i < input; i++)
	{
		if (input % i == 0)
			break;
	}
	if (input == i)
		return true;
	else
		return false;
}

int main()
{
	vector<int> V;
	queue<int> Q;
	stack<int> S1, S2;

	int input;
	while (1)
	{
		cin >> input;
		if (input == 0)
			break;
		else if (input < 0)
			V.push_back(input);
		else
		{
			if (isPrime(input))
				Q.push(input);
			if (input % 2 == 0)
				S1.push(input);
			else
				S2.push(input);
		}
	}

	for (unsigned int i = 0; i < V.size(); i++)
		cout << V[i] << '\t';
	cout << endl;

	unsigned int j = Q.size();
	for (unsigned int i = 0; i < j; i++)
	{
		cout << Q.front() << '\t';
		Q.pop();
	}
	cout << endl;

	j = S1.size();
	for (unsigned int i = 0; i < j; i++)
	{
		cout << S1.top() << '\t';
		S1.pop();
	}
	cout << endl;

	j = S2.size();
	for (unsigned int i = 0; i < j; i++)
	{
		cout << S2.top() << '\t';
		S2.pop();
	}
	cout << endl;
}
