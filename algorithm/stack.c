#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1

struct NODE
{
	int data;
	struct NODE* next;
};

struct STACK
{
	struct NODE* p;
	int size;
};

int push(struct STACK *head, int dig);
int pop(struct STACK *head);
int size();
int empty(struct STACK *head);
int top(struct STACK *head);

int push(struct STACK *head, int dig)
{
	struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
	
	node->data = dig;
	node->next = head->p;

	head->p = node;

	head->size++;

	return 0;
}

int pop(struct STACK *head)
{
	if (empty(head)) return -1;
	struct NODE *tmp = NULL;
	
	tmp = head->p;
	int _tmp = tmp->data;	
	
	head->p = head->p->next;

	if (tmp) free(tmp);

	head->size--;
	return _tmp;
}

int size(struct STACK *head)
{
	return head->size;
}

int empty(struct STACK *head)
{
	if (head->p == NULL) return 1;
	return 0;
}

int top(struct STACK *head)
{
	if (empty(head)) return -1;
	
	return head->p->data;
}

int print(struct STACK *head)
{
	struct NODE *tmp = head->p;
	while(tmp != NULL)
	{
		printf("%d \n", tmp->data);
		tmp = tmp->next;
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);
	char cmd[16] = {0,};
	struct STACK stack = {0,};

	while(N--)
	{
		memset(cmd, 0, sizeof(cmd));
		scanf("%s", cmd); //, &push_dig);
		
		if (strncmp(cmd, "push", sizeof("push")) == 0)
		{
			int push_dig = 0;
			scanf("%d", &push_dig);
			push(&stack, push_dig);
		}
		else if (strncmp(cmd, "top", sizeof("top")) == 0)
		{
			printf ("%d\n", top(&stack));	
		}		
		else if (strncmp(cmd, "pop", sizeof("pop")) == 0)
		{
			printf ("%d\n", pop(&stack));	
		}		
		else if (strncmp(cmd, "size", sizeof("size")) == 0)
		{
			printf ("%d\n", size(&stack));
		}		
		else if (strncmp(cmd, "empty", sizeof("empty")) == 0)
		{
			printf ("%d\n", empty(&stack));
		}	
		/*else if (strncmp(cmd, "print", sizeof("print")) == 0)
		{
			print(&stack);
		}*/
		else 
		{
			return -1;
		}
	}
	
	return 0;
}
