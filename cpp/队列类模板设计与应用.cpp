#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class CQueue
{
private:
	vector<T> elems;
public:
	CQueue() {};
	CQueue(CQueue<T>& a);
	bool empty() const;
	int size() const;
	const T& front() const;
	const T& back() const;
	void push(const T& a);
	void pop();
	CQueue<T>& operator = (const CQueue<T>& a);
};

template <class T>
CQueue<T>::CQueue(CQueue<T>& a)
{
	elems = a.elems;
}
template <class T>
bool CQueue<T>::empty() const
{
	return elems.empty();
}
template <class T>
int  CQueue<T>::size() const
{
	return elems.size();
}
template <class T>
const T& CQueue<T>::front() const
{
	return elems.front();
}
template <class T>
const T& CQueue<T>::back() const
{
	return elems.back();
}
template <class T>
void  CQueue<T>::push(const T& a)
{
	elems.push_back(a);
}
template <class T>
void  CQueue<T>::pop()
{
	elems.erase(elems.begin());
}
template <class T>
CQueue<T>& CQueue<T>::operator = (const CQueue<T>& a)
{
	elems = a.elems;
	return *this;
}

int main()
{
	cout << "Start:" << endl;
	string type;
	cin >> type;

	if (type == "string")
	{
		CQueue<string> s[3];
		int n;
		cin >> n;
		while (n--)
		{
			string command;
			int queue;
			cin >> command;
			if (command == "push")
			{
				string str;
				cin >> queue;
				cin >> str;
				s[queue - 1].push(str);
			}
			else if (command == "pop")
			{
				cin >> queue;
				cout << s[queue - 1].front() << " ";
				s[queue - 1].pop();
			}
			else if (command == "assign")
			{
				int queue2;
				cin >> queue >> queue2;
				s[queue2 - 1] = s[queue - 1];
			}
			else
				throw("Unsupported Command!");
		}
		cout << endl;
		cout << "Final:" << endl;
		CQueue<string> c = s[0];
		for (int m = 0; m < 3; m++)
		{
			int k = s[m].size();
			while (k--)
			{
				cout << s[m].front() << " ";
				s[m].pop();
			}
			cout << endl;
		}
		int k = c.size();
		while (k--)
		{
			cout << c.front() << " ";
			c.pop();
		}
		cout << endl;
	}
	else if (type == "int")
	{
		CQueue<int> i[3];
		int n;
		cin >> n;
		while (n--)
		{
			string command;
			int queue;
			cin >> command;
			if (command == "push")
			{
				int num;
				cin >> queue;
				cin >> num;
				i[queue - 1].push(num);
			}
			else if (command == "pop")
			{
				cin >> queue;
				cout << i[queue - 1].front() << " ";
				i[queue - 1].pop();
			}
			else if (command == "assign")
			{
				int queue2;
				cin >> queue >> queue2;
				i[queue2 - 1] = i[queue - 1];
			}
			else
				throw("Unsupported Command!");
		}
		cout << endl;
		cout << "Final:" << endl;
		CQueue<int> c = i[0];
		for (int m = 0; m < 3; m++)
		{
			int k = i[m].size();
			while (k--)
			{
				cout << i[m].front() << " ";
				i[m].pop();
			}
			cout << endl;
		}
		int k = c.size();
		while (k--)
		{
			cout << c.front() << " ";
			c.pop();
		}
		cout << endl;
	}
	else
		throw("Unsupported Type!");
}
