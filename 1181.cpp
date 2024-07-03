#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1, string s2) {
	if(s1.length() == s2.length()) {
		return s1.compare(s2) < 0;
	}
	return s1.length() < s2.length();
}

int main()
{
	int n, cnt=0;
	vector<string> str;	
	
	cin >> n;
	if(n<1 || n>20000) {
		cout << "error : n out of bounds" << endl;
		exit(0);
	}
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		
		if(find(str.begin(),str.end(),s) == str.end()) 
			str.push_back(s);
	}
	
	//sort
	sort(str.begin(),str.end(),compare);
	
	for(int i=0; i<str.size(); i++) {
		cout << str[i] << '\n';
	}
	
	return 0;
}

