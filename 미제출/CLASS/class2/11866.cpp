#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	vector<int> arr;
	
	cin >> n >> k;
	
	for(int i=1; i<=n; i++) {
		arr.push_back(i);
	}
	cout << "<";
	
	for(vector<int>::iterator it = arr.begin() + k - 1; arr.size() > 0;) {
		cout << *it;
		it = arr.erase(it);
		
		if(arr.size() != 0)		
			cout << ", ";
		
		if(it == arr.end()) {
			it = arr.begin();
		}
		for(int i=0; i<k-1; i++) {
			it ++;
			if(it == arr.end()) {
				it = arr.begin();
			}
		}
	}
	
	
	
	cout << ">";
	
	
	return 0;
}
