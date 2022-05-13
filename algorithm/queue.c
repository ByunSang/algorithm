#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 10001

#define PUSH "push"
#define POP "pop"
#define BACK "back"
#define EMPTY "empty"
#define FRONT "front"
#define SIZE "size"

typedef struct data
{
	int queue[MAX_QUEUE_SIZE];
	int front,  back;
	int queue_size;
}data;

bool is_empty(data* data)
{
	if (data->front == data->back) 
		return true;
	else return false;
}

bool is_full(data* data)
{
	if ((data->back +1) % MAX_QUEUE_SIZE == data->front) return true;
	
	else return false;
}

int push(data* data, int push_size)
{
	if (is_full(data)) return -1;

	data->back = (data->back+1)	% MAX_QUEUE_SIZE;
	data->queue[data->back] = push_size;
	data->queue_size++;
	return push_size;
}

int pop(data* data)
{
	if (is_empty(data)) return -1;
		
	else 
	{
		data->front = (data->front + 1) % MAX_QUEUE_SIZE;
		data->queue_size--;
		return data->queue[data->front];
	}
}

int front(data* data)
{
	if (is_empty(data))
		return -1;
	return data->queue[data->front + 1];
}

int back(data* data)
{
	if (is_empty(data))
		return -1;
	return data->queue[data->back];
}

int size(data* data)
{
	return data->queue_size;
	//if (data->front < data->back)
	//	return data->back - data->front;
	//return MAX_QUEUE_SIZE - data->front + data->back;
}
int main()
{
	int N;
	data data;
	char cmd[16];

	scanf("%d", &N);

	data.front = 0;
	data.back = 0;
	data.queue_size = 0;
	while(N--)
	{
		scanf(" %s", cmd);
		
		if (strcmp(cmd, PUSH) == 0)
		{
			int push_data;
			scanf(" %d", &push_data);
			push(&data, push_data);
		}
		else if (strncmp(cmd, POP, strlen(POP)) == 0)
		{
			printf("%d\n", pop(&data));
		}
		else if (strncmp(cmd, FRONT, strlen(FRONT)) == 0)
		{
			printf("%d\n", front(&data));
		}
		else if (strncmp(cmd, SIZE, strlen(SIZE)) == 0)
		{
			printf("%d\n", size(&data));
		}
		else if (strncmp(cmd, EMPTY, strlen(EMPTY)) == 0)
		{
			printf("%d\n", is_empty(&data));
		}
		else if (strncmp(cmd, BACK, strlen(BACK)) == 0)
		{
			printf("%d\n", back(&data));
		}
		else {
			printf("not found cmd\n");
			return -1;
		}
	}

	return 0;
}
