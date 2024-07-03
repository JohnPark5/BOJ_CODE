#include <stdio.h>
#include <string.h>
#define QUEUE_SIZE 10000

//not circular queue
int main()
{
	int n, front = -1, back = -1;
	int queue[QUEUE_SIZE];
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++) {
		char command[10] = "";
		scanf("%s",command);
		
		if(strcmp(command, "push") == 0) {
			int data;
			scanf("%d",&data);
			
			if(front == QUEUE_SIZE - 1) {
				printf("queue full!\n");
			}
			else {
				if(front == -1) 
					front++;
				queue[++back] = data;
			}
		}
		else if(strcmp(command, "pop") == 0) {
			if(front == -1) {
				printf("-1\n");
			}
			else {
				printf("%d\n",queue[front++]);
				if(front > back)
					front = back = -1;
			}
		}
		else if(strcmp(command, "size") == 0) {
			if(front == -1)
				printf("0\n");
			else
				printf("%d\n",back-front+1);
		}
		else if(strcmp(command, "empty") == 0) {
			(front == -1)?printf("1\n") : printf("0\n");
		}
		else if(strcmp(command, "front") == 0) {
			if(front == -1) 
				printf("-1\n");
			else
				printf("%d\n",queue[front]);
		}
		else if(strcmp(command, "back") == 0) {
			if(front == -1) 
				printf("-1\n");
			else
				printf("%d\n",queue[back]);
		}
	}
	
	
	return 0;
}
