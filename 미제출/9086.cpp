#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[10001]="";
	int T, len=0;
	
	cin >> T;
	if(T<1) {
		cout << "error : T<1" << endl;
		exit(0);
	}
	
	while(scanf("%[^\n]s",str)!=EOF)len++;
	str[len-1] = '\0';
	
	puts(str);
	
	
	return 0;
}
