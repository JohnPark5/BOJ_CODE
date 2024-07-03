#include <iostream> 
#include <memory.h>
using namespace std;


int main()
{
	int arr[10000], N=-1;
	memset(arr,0,sizeof(arr));
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for(int i=0; i<N; i++) {
		short tmp;
		cin >> tmp;
		arr[tmp-1]++;
	}
	
	for(int i=0; i<10000; i++) {
		if(arr[i] > 0) {
			for(int j=0; j<arr[i]; j++)
				cout << i+1 << '\n';
		}
	}
	
	
	return 0;
}
