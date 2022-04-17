#include <iostream>

using namespace std;

class rationalNum
{
private:
	long nume;
	long deno;
	void simplify();
public:
	rationalNum(long n, long d);

	friend ostream& operator<<(ostream& out, rationalNum& a);
	rationalNum operator + (rationalNum a);
	rationalNum operator - (rationalNum a);
	rationalNum operator * (rationalNum a);
	rationalNum operator / (rationalNum a);
};

rationalNum::rationalNum(long n, long d)
{
	nume = n;
	deno = d;
	simplify();
}

void rationalNum::simplify()
{
	if (deno == 0)
	{
		throw "Division by zero condition!";
	}
	else if (deno < 0)
	{
		nume = -nume;
		deno = -deno;
	}

	long a = abs(nume);
	long b = abs(deno);
	while (b > 0)
	{
		long t = a % b;
		a = b;
		b = t;
	}
	nume /= a;
	deno /= a;
}

ostream& operator<<(ostream& out, rationalNum& a)
{
	if (a.deno != 1)
		out << a.nume << "/" << a.deno;
	else
		out << a.nume;
	return out;
}

rationalNum rationalNum::operator + (rationalNum a)
{
	return rationalNum(nume * a.deno + deno * a.nume, deno * a.deno);
}

rationalNum rationalNum::operator - (rationalNum a)
{
	return rationalNum(nume * a.deno - deno * a.nume, deno * a.deno);
}

rationalNum rationalNum::operator * (rationalNum a)
{
	return rationalNum(nume * a.nume, deno * a.deno);
}

rationalNum rationalNum::operator / (rationalNum a)
{
	long d = deno * a.nume;
	if (d > 0)
		return rationalNum(nume * a.deno, d);
	else if (d < 0)
		return rationalNum(-nume * a.deno, -d);
	else
		return rationalNum(0, 1);
}


int main()
{
	long a, b, c, d;
	cin >> a >> b >> c >> d;
	rationalNum E(a, b), F(c, d);
	cout << E << endl << F << endl;
	rationalNum G = E + F;
	cout << G << "\t";
	G = E - F;
	cout << G << "\t";
	G = E * F;
	cout << G << "\t";
	G = E / F;
	cout << G << "\t" << endl;
}
