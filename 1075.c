#include <stdio.h>

int main()
{
	int N,F,res=0;
	
	scanf("%d %d",&N,&F);
	
	N-=N%100;
	
	for(int i=0; i<100; i++) {
		if((N+i)%F == 0) {
			res = i;
			break;
		}
	}
	printf("%02d\n",res);

	return 0;
}
