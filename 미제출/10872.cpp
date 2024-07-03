#include <iostream>
using namespace std;

int main()
{
	int N; // 0~12
	long long int res=1;
	
	cin >> N;
	
	for(int i=2; i<=N; i++)
		res *= i;
	
	cout << res << endl;
	
	
	return 0;
}
