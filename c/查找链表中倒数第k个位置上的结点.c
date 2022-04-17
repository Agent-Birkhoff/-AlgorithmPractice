#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node* link;
};

struct node* create(int num[1000]);
void delAll(struct node* list);
void readNum(char str[1000], int num[1000]);

int main(void)
{
	int k;
	scanf("%d", &k);
	getchar();
	int num[1000];
	char input[1000];
	scanf("%[^\n]", input);
	readNum(input, num);
	struct node* list = create(num);
	if (list)
	{
		struct node* p = list->link;
		struct node* q = p;
		int i;
		for (i = 0; i < k - 1; i++)
		{
			if (q->link)
				q = q->link;
			else
			{
				printf("-1\n");
				delAll(list);
				return 0;
			}
		}
		while (q->link)
		{
			p = p->link;
			q = q->link;
		}
		printf("%d", p->data);
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
