#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
	int n, m;
	unordered_set<string> x_hear;
	set<string> x_know;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		x_hear.insert(s);
	}
	for(int i=0; i<m; i++) {
		string s;
		cin >> s;
		if(x_hear.find(s)!=x_hear.end()) 
			x_know.insert(s);
	}
	
	cout << x_know.size() << '\n';
	for(string s : x_know)
		cout << s << '\n';
	
	
	return 0;
}
