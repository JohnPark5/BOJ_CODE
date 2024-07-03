#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	
	for(int i=0; i<n; i++) {
		string str;
		bool isAble = true;
		cin >> str;
		for(int j=0; j<str.length(); j++) {
			if(!(isalpha(str[j]) || isdigit(str[j]))) {
				isAble = false;
				break;
			}
		}
		if(str.length() < 6 || str.length() > 9) isAble = false;
		if(isAble) cout << "yes\n";
		else cout << "no\n";
	}
	
	
	return 0;
}
