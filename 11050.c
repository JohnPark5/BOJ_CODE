#include <stdio.h>

int main()
{
	int n, k, n1 = 1, k1 = 1;
	
	scanf("%d %d", &n, &k);
	
	if(k > n-k) k = n-k;
	
	for(int i=n-k+1; i<=n; i++) n1 *= i;
	for(int i=k; i>=2; i--) k1 *= i;
	
	printf("%d\n",n1/k1);
	
	
	return 0;
}
