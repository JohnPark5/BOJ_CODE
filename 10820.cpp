#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main()
{
	vector<string> strArr;
	
	for(int i=0; i<100; i++) {
		string input;
		getline(cin, input);
		
		if(input.length() == 0) break;
		
		strArr.push_back(input);
	}
	
	int n = strArr.size();
	
	for(int i=0; i<n; i++) {
		int upper = 0, lower = 0, digit = 0, space = 0;
		
		int len = strArr[i].length();
		for(int k=0; k<len; k++) {
			if(isdigit(strArr[i].at(k))) {
				digit ++;
			}
			else if(isspace(strArr[i].at(k))) {
				space ++;
			}
			else if(isalpha(strArr[i].at(k))) {
				if('A' <= strArr[i].at(k) && strArr[i].at(k) <= 'Z') {
					upper ++;
				}
				else if('a' <= strArr[i].at(k) && strArr[i].at(k) <= 'z') {
					lower ++;
				}
				else {
					cout << "error : " << strArr[i].at(k) << '\n';
				}
			}
		}
		cout << lower << " " << upper << " " << digit << " " << space << '\n';
	}
	
	
	return 0;
}
