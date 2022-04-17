#include <iostream>
#include <string>

using namespace std;

class CUIControl
{
public:
	virtual ~CUIControl() {};
	virtual void Clicked() = 0;
protected:
	string name;
};

class CMenu :public CUIControl
{
public:
	CMenu(string n) { name = n; }
	~CMenu() {};
	void Clicked()
	{
		cout << "menu-" << name << " Clicked" << endl;
	}
};

class CButton :public CUIControl
{
public:
	CButton(string n) { name = n; }
	~CButton() {};
	void Clicked()
	{
		cout << "button-" << name << " Clicked" << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	string input;
	CUIControl** CUIC = new CUIControl * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == "menu")
		{
			cin >> input;
			CUIC[i] = new CMenu(input);
		}
		else if (input == "button")
		{
			cin >> input;
			CUIC[i] = new CButton(input);
		}
		else
			CUIC[i] = NULL;
	}
	int order;
	while (cin >> input)
	{
		cin >> order;
		CUIC[order - 1]->Clicked();
	}
	for (int i = 0; i < n; i++)
		delete CUIC[i];
	delete[] CUIC;
}
