#include <iostream>
using namespace std;

int main()
{
	int T, a, b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	
	if(T<1) {
		cout << "error! T<0" << endl;
		exit(0);
	}
	
	for(int i=0; i<T; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	
	
	return 0;
}
