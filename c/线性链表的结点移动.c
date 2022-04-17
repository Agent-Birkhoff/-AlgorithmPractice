#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
	int data;
	struct node* link;
};

struct node* create();
void delAll(struct node* list);

int main(void)
{
	struct node* list = create();
	struct node* num = list;
	struct node* max = num->link;
	struct node* former = num;
	if (former != NULL && max != NULL)
	{
		while (num->link)
		{
			struct node* temp = num->link;
			if (temp->data > max->data)
			{
				former = num;
				max = num->link;
			}
			num = num->link;
		}
		former->link = max->link;
		num->link = max;
		max->link = NULL;
		num = list->link;
		while (num)
		{
			printf("%d ", num->data);
			num = num->link;
		}
	}
	delAll(list);
	return 0;
}

struct node* create()
{
	struct node* start, * node, * end;
	start = (struct node*)malloc(sizeof(struct node));
	end = start;
	if (end)
	{
		while (1)
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
			if (getchar() == '\n')
				break;
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
