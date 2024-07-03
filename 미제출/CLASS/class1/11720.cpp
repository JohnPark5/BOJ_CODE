#include <iostream>
using namespace std;

int main()
{
	int N, sum=0;
	
	cin >> N;
	
	for(int i=0; i<N; i++) {
		char c;
		cin >> c;
		sum += c-'0';
	}
	
	cout << sum << endl;
	
	return 0;
}
