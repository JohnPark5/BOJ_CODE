#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *b;
	
	int k, len=100;
	a = (int*)malloc(sizeof(int)*len);
	b = (int*)malloc(sizeof(int)*len);
	
	for(k=0;; k++) {
		scanf("%d %d",&a[k],&b[k]);
		
		if(a[k]==0 && b[k]==0)break;
		
		if(k%100 == 99) {
			realloc(a,sizeof(int)*(k+101));
			realloc(b,sizeof(int)*(k+101));
		}
	}
	
	for(int i=0; i<k; i++) {
		printf("%d\n",a[i]+b[i]);
	}
	
	free(a);
	free(b);
	
	return 0;
}
