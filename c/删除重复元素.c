#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node* link;
};

struct node* create(int num[1000]);
void del(struct node* list, int order);
void delAll(struct node* list);
int view(struct node* list, int order);
int len(struct node* list);
void readNum(char str[1000], int num[1000]);

int main(void)
{
	char input[1000];
	int num[1000];
	scanf("%[^\n]", input);
	readNum(input, num);
	struct node* list = create(num);
	if (list)
	{
		int i = 1;
		while (1)
		{
			if (i > len(list))
				break;
			int j = 1 + i;
			while (1)
			{
				if (j > len(list))
					break;
				if (view(list, i) == view(list, j))
				{
					del(list, j);
					j--;
				}
				j++;
			}
			i++;
		}
		struct node* temp = list->link;
		while (temp)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
	}
	delAll(list);
	return 0;
}

struct node* create(int num[1000])
{
	struct node* start, * node, * end;
	start = (struct node*)malloc(sizeof(struct node));
	end = start;
	if (end)
	{
		int k = 0;
		while (num[k] != -1)
			k++;
		int i;
		for (i = 0; i < k; i++)
		{
			node = (struct node*)malloc(sizeof(struct node));
			if (node)
			{
				end->link = node;
				end = node;
				end->data = num[i];
			}
		}
		end->link = NULL;
	}
	return start;
}

void del(struct node* list, int order)
{
	struct node* former = list, * target = former->link;
	int i;
	for (i = 0; i < order - 1; i++)
	{
		if (former->link)
			former = former->link;
	}
	target = former->link;
	if (target)
	{
		former->link = target->link;
		free(target);
	}
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

void readNum(char str[1000], int num[1000])
{
	int value = 0;
	int i, k = 0;
	int isSaved = 0;
	for (i = 0; i < 1000; i++)
	{
		while ((*str >= '0') && (*str <= '9'))
		{
			value = value * 10 + (*str - '0');
			isSaved = 0;
			str++;
		}
		if (*str == '\n' || *str == '\0')
		{
			if (isSaved != 1)
			{
				num[k] = value;
				k++;
				value = 0;
				isSaved = 1;
				break;
			}
			else
				break;
		}
		else if (isSaved != 1)
		{
			num[k] = value;
			k++;
			value = 0;
			isSaved = 1;
		}
		str++;
	}
	num[k] = -1;
}
