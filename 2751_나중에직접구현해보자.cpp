#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> arr;
	int n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		arr.insert(x);
	}
	
	for(int x : arr) {
		cout << x << '\n';
	}
	
	
	return 0;
}
