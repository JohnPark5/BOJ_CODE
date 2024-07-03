#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int len, cnt = 0;
	bool nowWord = false;
	
	getline(cin, str);
	len = str.length();
	
	for(int i=0; i<len; i++) {
		if(nowWord) {
			if(str[i] == ' ')
				nowWord = false;
		}
		else {
			if(str[i] != ' ')
				nowWord = true, cnt++;
		}
	}
	
	cout << cnt << '\n';
	
	
	return 0;
}
