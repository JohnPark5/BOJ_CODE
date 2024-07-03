#include <iostream>
#define N 5
using namespace std;

int main()
{
	unsigned long long int k[N], res=0;
	
	for(int i=0; i<5; i++) {
		cin >> k[i];
		res += k[i]*k[i];
	}
	
	cout << res%10;	
	
	
	return 0;
}
