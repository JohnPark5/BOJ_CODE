#include <stdio.h>

int main()
{
	int a=0,b=0;
	
	scanf("%d %d",&a,&b);
	
	if(a<b) {
		printf("<\n");
	}
	else if(a>b){
		printf(">\n");
	}
	else {
		printf("==\n");
	}
	
	
	
	return 0;
}
