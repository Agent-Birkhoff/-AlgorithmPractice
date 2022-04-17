#include <iostream>
#include <iomanip>

using namespace std;

struct person {
	int num;
	struct person* next;
};

int main()
{
	int M, N;
	cin >> M >> N;
	struct person* people = new(struct person);
	people->next = NULL;
	struct person* p = people;
	for (int i = 1; i <= M; i++)
	{
		struct person* one = new(struct person);
		one->num = i;
		one->next = p->next;
		p->next = one;
		p = one;
	}
	p->next = people->next;

	p = people->next;
	struct person* f = people;
	for (int i = 1; i <= M; i++)
		f = f->next;
	for (int j = 1; j <= M; j++)
	{
		for (int i = 1; i < N; i++)
		{
			f = f->next;
			p = p->next;
		}
		cout << setw(4) << p->num;
		f->next = p->next;
		delete p;
		p = f->next;
	}

	delete people;
}
