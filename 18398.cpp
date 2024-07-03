#include <iostream>
using namespace std;

int main()
{
	int T, n;
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	cin.tie(nullptr);
	
	for(int t=0; t<T; t++) {
		cin >> n;
		for(int i=0; i<n; i++) {
			int a, b;
			cin >> a >> b;
			
			cout << a+b << " " << a*b << '\n';
		}
	}
	
	
	
	
	return 0;
}
