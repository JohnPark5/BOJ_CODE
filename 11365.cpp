#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(true) {
		string decode;
		getline(cin, input);
		if(input.compare("END")==0) break;
		
		for(string::reverse_iterator it = input.rbegin(); it != input.rend(); it++) {
			cout << *it;
		}
		cout << '\n';
		
	}
	
	
	return 0;
}
