#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char str[1000]="";
	int radix=-1,len = 0, tmp=0;
	double res;
	
	scanf("%s %d",str,&radix);
	
	if(radix<2 || radix>36) {
		printf("error\n");
		exit(0);
	}
	len = strlen(str);
	
	for(int i=len-1; i>=0; i--)
	{
		if('0'<=str[i] && str[i]<='9') {
			tmp = str[i]-'0';
			res += tmp*pow((double)radix,(double)(len-i-1));
			//printf("%d ^ %d = (%f) 를 더함\n",tmp,len-i-1,pow((double)radix,(double)(len-i-1)));
		}
		else if('A'<=str[i] && str[i]<='Z') {
			tmp = str[i]-'A' + 10;
			res += tmp*pow((double)radix,(double)(len-i-1));
			//printf("%d ^ %d = (%f) 를 더함\n",tmp,len-i-1,pow((double)radix,(double)(len-i-1)));
			}
		else if('a'<str[i] && str[i]<'z') {
			printf("error");
			exit(0);
		}
		else {
			printf("error");
			exit(0);
		}
		
		
		
	}
	printf("%.0f\n",res);
	
	
	return 0;
}
