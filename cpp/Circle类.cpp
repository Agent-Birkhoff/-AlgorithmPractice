#include <iostream>
#include <iomanip>

using namespace std;

const double pi = 3.14159265;

class Circle {
public:
	double area(double radius);
	double length(double radius);
};

double Circle::area(double radius)
{
	return pi * radius * radius;
}

double Circle::length(double radius)
{
	return 2 * pi * radius;
}

int main()
{
	Circle circle;
	double input;
	cin >> input;
	double cost = circle.area(input) * 20 + circle.length(input) * 35;
	cout << fixed << setprecision(2) << cost << endl;
}
