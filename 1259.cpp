#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s);

int main()
{
	vector<string> arr;
	
	while(true) {
		string a;
		cin >> a;
		if(a == "0")
			break;
		arr.push_back(a);
	}
	
	for(int i=0; i<arr.size(); i++) {
		if(isPalindrome(arr[i]))
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}	
	
	return 0;
}



bool isPalindrome(string s) {
	int n;
	int len = s.size();
	if(len%2 == 0) {
		n = len/2;
	}
	else {
		n = (len-1)/2;
	}
	
	for(int i=0; i<n; i++) {
		if(s[i] != s[len-i-1])
			return false;
	}
	return true;
}




