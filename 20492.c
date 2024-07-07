#include <stdio.h>

int main()
{
	int n;
	double k;
	
	scanf("%d",&n);
	
	k = n / 1000.0;
	
	printf("%d %d\n", (int)(k*780), (int)(k*956));
	
	
	return 0;
}
