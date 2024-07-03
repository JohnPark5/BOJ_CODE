#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, shirt[6], t, p, shirtBundleCnt = 0, penBundleCnt = 0, penCnt = 0;
	
	scanf("%d", &n);
	
	for(int i=0; i<6; i++) {
		scanf("%d", &shirt[i]);
	}
	
	scanf("%d %d", &t, &p);
	
	for(int i=0; i<6; i++) {
		shirtBundleCnt += shirt[i]/t;
		if(shirt[i] % t != 0) shirtBundleCnt ++;
	}
	
	penBundleCnt = n / p;
	penCnt = n % p;
	
	printf("%d\n%d %d\n", shirtBundleCnt, penBundleCnt, penCnt);
	
	
	return 0;
}
