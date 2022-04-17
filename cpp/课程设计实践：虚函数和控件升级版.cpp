#include <iostream>
#include <string>

using namespace std;

struct CPoint
{
	int x;
	int y;
};

class CShape
{
public:
	virtual ~CShape() {};
	virtual bool HitIn(const CPoint& a) const = 0;
protected:
	CPoint location = { 0,0 };
};

class CRectangle :public CShape
{
public:
	CRectangle(int& x, int& y, int& l, int& w)
	{
		location.x = x;
		location.y = y;
		length = l;
		width = w;
	}
	~CRectangle() {};
	bool HitIn(const CPoint& a) const
	{
		if (a.x >= location.x && a.x <= location.x + length && a.y >= location.y && a.y <= location.y + width)
			return true;
		else
			return false;
	}
private:
	int length;
	int width;
};

class CCircle :public CShape
{
public:
	CCircle(int& x, int& y, double& r)
	{
		location.x = x;
		location.y = y;
		radius = r;
	}
	~CCircle() {};
	bool HitIn(const CPoint& a) const
	{
		double dx = double(a.x), dy = double(a.y), dx2 = double(location.x), dy2 = double(location.y);
		double distance2 = (dx - dx2) * (dx - dx2) + (dy - dy2) * (dy - dy2);
		if (distance2 <= radius * radius)
			return true;
		else
			return false;
	}
private:
	double radius;
};

class CUIControl
{
public:
	virtual ~CUIControl() {};
	bool HitTest(const CPoint& a) const
	{
		if (_pShape->HitIn(a))
			return true;
		else
			return false;
	}
	virtual void Clicked() = 0;
protected:
	string name;
	CShape* _pShape = NULL;
};

class CMenu :public CUIControl
{
public:
	CMenu(string& n, int& x, int& y, int& l, int& w)
	{
		name = n;
		_pShape = new CRectangle(x, y, l, w);
	}
	CMenu(string& n, int& x, int& y, double& r)
	{
		name = n;
		_pShape = new CCircle(x, y, r);
	}
	~CMenu()
	{
		delete _pShape;
	};
	void Clicked()
	{
		cout << "menu-" << name << " Clicked" << endl;
	}
};

class CButton :public CUIControl
{
public:
	CButton(string& n, int& x, int& y, int& l, int& w)
	{
		name = n;
		_pShape = new CRectangle(x, y, l, w);
	}
	CButton(string& n, int& x, int& y, double& r)
	{
		name = n;
		_pShape = new CCircle(x, y, r);
	}
	~CButton()
	{
		delete _pShape;
	};
	void Clicked()
	{
		cout << "button-" << name << " Clicked" << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	string input, shape;
	CPoint point;
	CUIControl** CUIC = new CUIControl * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == "menu")
		{
			cin >> input;
			cin >> shape;
			if (shape == "rectangle")
			{
				int l, w;
				cin >> point.x >> point.y >> l >> w;
				CUIC[i] = new CMenu(input, point.x, point.y, l, w);
			}
			else if (shape == "circle")
			{
				double r;
				cin >> point.x >> point.y >> r;
				CUIC[i] = new CMenu(input, point.x, point.y, r);
			}
			else
				CUIC[i] = NULL;
		}
		else if (input == "button")
		{
			cin >> input;
			cin >> shape;
			if (shape == "rectangle")
			{
				int l, w;
				cin >> point.x >> point.y >> l >> w;
				CUIC[i] = new CButton(input, point.x, point.y, l, w);
			}
			else if (shape == "circle")
			{
				double r;
				cin >> point.x >> point.y >> r;
				CUIC[i] = new CButton(input, point.x, point.y, r);
			}
			else
				CUIC[i] = NULL;
		}
		else
			CUIC[i] = NULL;
	}
	while (cin >> input)
	{
		cin >> point.x >> point.y;
		for (int i = n - 1; i >= 0; i--)
		{
			if (CUIC[i] && CUIC[i]->HitTest(point))
			{
				CUIC[i]->Clicked();
				break;
			}
			if (i == 0)
				cout << "none hit" << endl;
		}
	}
	for (int i = 0; i < n; i++)
		delete CUIC[i];
	delete[] CUIC;
}
