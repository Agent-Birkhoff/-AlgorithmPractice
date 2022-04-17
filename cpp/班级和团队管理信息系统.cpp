#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Student
{
private:
	string name;
	int num;
public:
	Student(string& a, int& b) : name(a), num(b) {	}
	string& get_name()
	{
		return name;
	}
	int& get_number()
	{
		return num;
	}
};

class Cls
{
private:
	string name;
	vector<shared_ptr<Student>> students;
public:
	Cls(string& a) : name(a) {};
	string& get_name()
	{
		return name;
	}
	void add(shared_ptr<Student> a)
	{
		students.push_back(a);
	}
	void printStudents()
	{
		cout << "class " << name << ":" << endl;
		for (unsigned int i = 0; i < students.size(); i++)
			cout << students[i]->get_number() << " " << students[i]->get_name() << endl;
		cout << endl;
	}
};

class Org
{
private:
	string name;
	vector<shared_ptr<Student>> students;
public:
	Org(string& a) : name(a) {};
	string& get_name()
	{
		return name;
	}
	void add(shared_ptr<Student> a)
	{
		students.push_back(a);
	}
	void printStudents()
	{
		cout << name << " team" << ":" << endl;
		for (unsigned int i = 0; i < students.size(); i++)
			cout << students[i]->get_number() << " " << students[i]->get_name() << endl;
		cout << endl;
	}
};

int main()
{
	int num = 10000;
	vector<shared_ptr<Student>> students;
	vector<shared_ptr<Cls>> classes;
	vector<shared_ptr<Org>> organisations;
	string input;
	while (cin >> input)
	{
		if (input == "append")
		{
			string name;
			cin >> name;
			shared_ptr<Student> a(new Student(name, num));
			students.push_back(a);
			num++;
		}
		else if (input == "create")
		{
			string type, name;
			cin >> type >> name;
			if (type == "class")
			{
				shared_ptr<Cls> a(new Cls(name));
				classes.push_back(a);
			}
			else if (type == "team")
			{
				shared_ptr<Org> a(new Org(name));
				organisations.push_back(a);
			}
		}
		else if (input == "join")
		{
			string type, name;
			int num;
			cin >> type >> name >> num;
			shared_ptr<Student> a;
			for (unsigned int i = 0; i < students.size(); i++)
			{
				if (students[i]->get_number() == num)
				{
					a = students[i];
					break;
				}
			}
			if (type == "class")
			{
				for (unsigned int i = 0; i < classes.size(); i++)
				{
					if (classes[i]->get_name() == name)
					{
						classes[i]->add(a);
						break;
					}
				}
			}
			else if (type == "team")
			{
				for (unsigned int i = 0; i < organisations.size(); i++)
				{
					if (organisations[i]->get_name() == name)
					{
						organisations[i]->add(a);
						break;
					}
				}
			}
		}
	}

	cout << "student list:" << endl;
	for (unsigned int i = 0; i < students.size(); i++)
		cout << students[i]->get_number() << " " << students[i]->get_name() << endl;
	cout << endl;
	for (unsigned int i = 0; i < classes.size(); i++)
		classes[i]->printStudents();
	for (unsigned int i = 0; i < organisations.size(); i++)
		organisations[i]->printStudents();
}
