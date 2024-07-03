#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	char ps[51];
	
	scanf("%d", &T);
	
	for(int t=0; t<T; t++) {
		scanf("%s",ps);
		
		int len = strlen(ps), total = 0, isVPS = 1;
		
		for(int i=0; i<len; i++) {
			if(ps[i] == '(') {
				total ++;
			}
			else {
				total --;
			}
			
			if(total < 0) {
				isVPS = 0;
				break;
			}
		}
		if(total != 0) isVPS = 0;
		
		if(isVPS) printf("YES\n");
		else printf("NO\n");
	}
	
	
	return 0;
}
