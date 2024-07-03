#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int len, diff = 'a'-'A';
	
	cin >> str;
	len = str.length();
	
	
	for(int i=0; i<len; i++) {
		if(str[i]<'a') {
			str[i] += diff;
		}
		else {
			str[i] -= diff;
		}
	}
	
	cout << str;
	
	
	return 0;
}
