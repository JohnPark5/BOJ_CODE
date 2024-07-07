#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> arr;
	int n, m;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		
		unordered_map<int, int>::iterator it = arr.find(x);
		if(it != arr.end()) {
			it->second ++;
		}
		else {
			arr.insert({x,1});
		}
	}
	
	cin >> m;
	
	for(int i=0; i<m; i++) {
		int x;
		cin >> x;
		
		unordered_map<int, int>::iterator it = arr.find(x);
		if(it != arr.end()) {
			cout << it->second << " ";
		}
		else {
			cout << "0 ";
		}
	}
	
	
	return 0;
}
