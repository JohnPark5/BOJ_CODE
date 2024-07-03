#include <iostream>
using namespace std;

int main()
{
	int N, n, cnt=0;
	
	cin >> N;
	n = N;
	
	while(n>=5) {
		n-=5;
		cnt++;
	}
	
	while(n%3 != 0 && n<=N) {
		n+=5;
		cnt--;
	}
	
	if(n>N) {
		cout << -1 << '\n';
		exit(0);
	}
	
	cout << cnt + n/3 << '\n';
	
	
	return 0;
}

