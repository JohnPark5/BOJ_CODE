#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *b;
	
	int len=0;
	
	scanf("%d",&len);
	
	a = (int*)malloc(sizeof(int)*len);
	b = (int*)malloc(sizeof(int)*len);
	
	for(int k=0; k<len; k++) {
		scanf("%d %d",&a[k],&b[k]);
		
		
	}
	
	for(int i=0; i<len; i++) {
		printf("%d\n",a[i]+b[i]);
	}
	
	free(a);
	free(b);
	
	return 0;
}
