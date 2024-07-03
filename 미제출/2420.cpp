#include <iostream>
using namespace std;

int main()
{
	long long int N, M, res;
	
	cin >> N >> M;
	
	res = (N>M)?(N-M):(M-N);
	
	cout << res << endl;
	
	
	return 0;
}
