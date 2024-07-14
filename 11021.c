#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t,*a,*b;
	
	scanf("%d",&t);
	
	a = (int*)malloc(sizeof(int)*t);
	b = (int*)malloc(sizeof(int)*t);
	
	for(int i=0; i<t; i++) {
		scanf("%d %d",&a[i],&b[i]);		
	}
	for(int i=0; i<t; i++) {
		printf("Case #%d: %d\n",i+1,a[i] + b[i]);
	}
	
	free(a);
	free(b);
	
	return 0;
}
