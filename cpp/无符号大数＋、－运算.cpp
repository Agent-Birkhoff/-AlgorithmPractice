#include <iostream>

using namespace std;

class uLong
{
private:
	char num[200] = {0}; //节约内存
	int enob = 0;
	void reverse();

public:
	uLong operator+(const uLong &a) const;
	uLong operator-(const uLong &a) const;
	bool operator>(const uLong &a) const;
	bool operator<(const uLong &a) const;
	bool operator>=(const uLong &a) const;
	bool operator<=(const uLong &a) const;
	bool operator==(const uLong &a) const;
	bool operator!=(const uLong &a) const;
	friend istream &operator>>(istream &in, uLong &a);
	friend ostream &operator<<(ostream &out, const uLong &a);
};

void uLong::reverse()
{
	for (int i = 0; i < enob / 2 - 0.5; i++)
	{
		int temp = num[i];
		num[i] = num[enob - i - 1];
		num[enob - i - 1] = temp;
	}
}

uLong uLong::operator+(const uLong &a) const
{
	uLong result;
	if (enob >= a.enob)
	{
		result = *this;
		for (int i = 0; i < a.enob; i++)
		{
			result.num[i] += a.num[i];
			if (result.num[i] > 9)
			{
				result.num[i] -= 10;
				if (i + 1 > result.enob - 1)
				{
					result.enob++;
					result.num[i + 1] = 1;
				}
				else
					result.num[i + 1] += 1;
			}
		}
	}
	else
	{
		result = a;
		for (int i = 0; i < enob; i++)
		{
			result.num[i] += num[i];
			if (result.num[i] > 9)
			{
				result.num[i] -= 10;
				if (i + 1 > result.enob - 1)
				{
					result.enob++;
					result.num[i + 1] = 1;
				}
				else
					result.num[i + 1] += 1;
			}
		}
	}
	return result;
}

uLong uLong::operator-(const uLong &a) const
{
	if (*this < a)
		throw("The result is below zero!");
	uLong result = *this;
	for (int i = 0; i < a.enob; i++)
	{
		if (result.num[i] < a.num[i])
		{
			int j = i + 1;
			while (result.num[j] == 0)
			{
				result.num[j] = 9;
				j++;
			}
			result.num[j]--;
			result.num[i] += 10;
		}
		result.num[i] -= a.num[i];
	}
	while (result.num[result.enob - 1] == 0)
		result.enob--;
	if (result.enob == 0)
	{
		result.enob++;
		result.num[0] = 0;
	}
	return result;
}

bool uLong::operator>(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob > a.enob)
		return true;
	else if (enob < a.enob)
		return false;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] > a.num[i - 1])
				return true;
			else if (num[i - 1] < a.num[i - 1])
				return false;
		}
		return false;
	}
}

bool uLong::operator<(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob < a.enob)
		return true;
	else if (enob > a.enob)
		return false;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] < a.num[i - 1])
				return true;
			else if (num[i - 1] > a.num[i - 1])
				return false;
		}
		return false;
	}
}

bool uLong::operator>=(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob > a.enob)
		return true;
	else if (enob < a.enob)
		return false;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] > a.num[i - 1])
				return true;
			else if (num[i - 1] < a.num[i - 1])
				return false;
		}
		return true;
	}
}

bool uLong::operator<=(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob < a.enob)
		return true;
	else if (enob > a.enob)
		return false;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] < a.num[i - 1])
				return true;
			else if (num[i - 1] > a.num[i - 1])
				return false;
		}
		return true;
	}
}

bool uLong::operator==(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob != a.enob)
		return false;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] != a.num[i - 1])
				return false;
		}
		return true;
	}
}

bool uLong::operator!=(const uLong &a) const
{
	if (enob == 0 || a.enob == 0)
		throw("Not initialized uLong");
	if (enob != a.enob)
		return true;
	else
	{
		int i = enob;
		while (i--)
		{
			if (num[i - 1] != a.num[i - 1])
				return true;
		}
		return false;
	}
}

istream &operator>>(istream &in, uLong &a)
{
	a.enob = 0;
	while (in.get(a.num[a.enob]))
	{
		if (a.num[a.enob] >= 48 && a.num[a.enob] <= 57)
		{
			a.num[a.enob] -= 48;
			a.enob++;
			break;
		}
	}
	while (in.get(a.num[a.enob]))
	{
		if (a.num[a.enob] >= 48 && a.num[a.enob] <= 57)
		{
			a.num[a.enob] -= 48;
			a.enob++;
		}
		else
			break;
	}
	a.reverse();
	return in;
}

ostream &operator<<(ostream &out, const uLong &a)
{
	int i = a.enob;
	while (i--)
		out << static_cast<int>(a.num[i]);
	return out;
}

int main()
{
	uLong A, B;
	cin >> A >> B;
	cout << A + B << endl
		 << A - B << endl;
}
