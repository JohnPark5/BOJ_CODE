#include <iostream>
#include <set>
using namespace std;


int main()
{
	int n, *arr, cnt=0;
	set<int> primeSet;
	
	for(int i=2; i<34; i++) {
		bool isPrime = true;
		for(set<int>::iterator it = primeSet.begin(); it!=primeSet.end(); it++) {
			if(i%*it == 0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) {
			primeSet.insert(i);
		}
	}
	
	cin >> n;
	
	if(n<1) {
		cout << "error: n<1" << endl;
		exit(0);
	}
	arr = new int[n];
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++) {
		bool isPrime = true;
		if(arr[i]!=1)
		for(set<int>::iterator it = primeSet.begin(); it!=primeSet.end(); it++) {
			if(*it >= arr[i])break;
			
			if(arr[i]%*it == 0) {
				isPrime = false;
				break;
			}
		}
		else isPrime = false;
		if(isPrime) cnt++;
	}
	
	cout << cnt << '\n';
	
	
	return 0;
}

