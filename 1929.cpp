#include <iostream>
#include <set>
#define MAX_SAVE_PRIMENUM_LIMIT 10000 // at least : sqrt(max)
using namespace std;

int main()
{
	int m,n;
	set<int> primeSet;
	
	cin >> m >> n;
	
	for(int i=2; i<=n; i++) {
		bool isPrime = true;
		for(set<int>::iterator it = primeSet.begin(); it!=primeSet.end(); it++) {
			if(i%*it == 0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) {
			if( i < MAX_SAVE_PRIMENUM_LIMIT )
				primeSet.insert(i);
			if( i >= m )
				cout << i << '\n';
		}
	}
	
	
	return 0;
}
