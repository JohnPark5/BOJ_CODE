#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> arr;
	int n;
	
	cin >> n;
	
	if(n<1)exit(0);
	
	for(int i=0; i<n; i++) {
		int x; 
		cin >> x;
		arr.insert(x);
	}
	
	for(auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << '\n';
	}
	
	
	return 0;
}

