#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n;
	multimap<int, string> member;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int age;
		string name;
		cin >> age >> name;
		
		member.insert({age, name});
	}
	
	for(pair<int, string> it : member) {
		cout << it.first << " " << it.second << '\n';
	}
	
	
	return 0;
}
