#include <iostream>
using namespace std;

int main()
{
	char str[100][101];
	int cnt = 0;
	
	for(int i=0; i<100; i++) {
		if((scanf("%[^\n]s",str[i])) != EOF) {
			getchar();
			cnt++;
		}
		else {
			break;
		}
	}
	for(int i=0; i<cnt; i++) {
		cout << str[i] << endl;
	}
	
	return 0;
}
