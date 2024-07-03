#include <iostream>
using namespace std;

int main()
{
	int n, m, max = -1, *arr;
	
	cin >> n >> m;
	
	if(n<1) exit(0);
	
	arr = new int[n];
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n-2; i++) {
		for(int j=i+1; j<n-1; j++) {
			for(int k=j+1; k<n; k++) {
				int x = arr[i]+arr[j]+arr[k];
				if(x <= m && x > max) max = x;
			}
		}
	}
	
	cout << max << '\n';
	
	
	delete[] arr;
	return 0;
}

