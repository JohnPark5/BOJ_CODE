#include <stdio.h>
#include <string.h>
#define STACK_SIZE 10000

int main()
{
	int n, top = -1;
	int stack[STACK_SIZE];
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++) {
		char command[10] = "";
		scanf("%s",command);
		
		if(strcmp(command, "push") == 0) {
			int data;
			scanf("%d",&data);
			
			if(top == STACK_SIZE-1) {
				printf("stack full!\n");
			}
			else {
				stack[++top] = data;
			}
		}
		else if(strcmp(command, "pop") == 0) {
			if(top == -1) {
				printf("-1\n");
			}
			else {
				printf("%d\n",stack[top--]);
			}
		}
		else if(strcmp(command, "size") == 0) {
			printf("%d\n",top+1);
		}
		else if(strcmp(command, "empty") == 0) {
			(top==-1)?printf("1\n") : printf("0\n");
		}
		else if(strcmp(command, "top") == 0) {
			if(top == -1) 
				printf("-1\n");
			else
				printf("%d\n",stack[top]);
		}
	}
	
	
	return 0;
}
