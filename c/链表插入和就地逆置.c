#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node* link;
};

struct node* create(int N);
int len(struct node* list);
void delAll(struct node* list);
void bubbleSort1(struct node* list, int length);
void bubbleSort2(struct node* list, int length);
int view(struct node* list, int order);
void output(struct node* list);
void swap(struct node* list, int n);

int main(void)
{
	int N;
	scanf("%d", &N);
	struct node* list = create(N);
	bubbleSort1(list, len(list));
	output(list);
	bubbleSort2(list, len(list));
	output(list);
	delAll(list);
	return 0;
}

struct node* create(int N)
{
	struct node* start, * node, * end;
	start = (struct node*)malloc(sizeof(struct node));
	end = start;
	if (end)
	{
		int i;
		for (i = 0; i < N; i++)
		{
			int input;
			scanf("%d", &input);
			node = (struct node*)malloc(sizeof(struct node));
			if (node)
			{
				end->link = node;
				end = node;
				end->data = input;
			}
		}
		end->link = NULL;
	}
	return start;
}

int len(struct node* list)
{
	int n = 0;
	struct node* p = list;
	if (p)
	{
		while (p->link != NULL)
		{
			n++;
			p = p->link;
		}
	}
	return n;
}

void delAll(struct node* list)
{
	struct node* num = list;
	while (num)
	{
		struct node* temp = num->link;
		free(num);
		num = temp;
	}
}

int view(struct node* list, int order)
{
	struct node* target = list;
	if (target)
	{
		int i;
		for (i = 0; i < order; i++)
			target = target->link;
		return target->data;
	}
	else
		return -1;
}

void bubbleSort1(struct node* list, int length)
{
	int i, n;
	for (i = length - 1; i > 0; i--)
	{
		for (n = 1; n <= i; n++)
		{
			if (view(list, n) > view(list, n + 1))
				swap(list, n);
		}
	}
}

void bubbleSort2(struct node* list, int length)
{
	int i, n;
	for (i = length - 1; i > 0; i--)
	{
		for (n = 1; n <= i; n++)
		{
			if (view(list, n) < view(list, n + 1))
				swap(list, n);
		}
	}
}

void output(struct node* list)
{
	struct node* temp = list->link;
	while (temp)
	{
		printf("%d", temp->data);
		temp = temp->link;
		if (temp != NULL)
			printf("->");
	}
	printf("\n");
}

void swap(struct node* list, int n)
{
	int i;
	struct  node* temp = list;
	if (temp)
	{
		for (i = 0; i < n - 1; i++)
			temp = temp->link;
		struct  node* m = temp->link;//第n个
		temp->link = m->link;//n-1链接到n+1
		m->link = (temp->link)->link;//n链接到n+2
		(temp->link)->link = m;//n+1链接到n
	}
}
