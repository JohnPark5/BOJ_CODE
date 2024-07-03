#include <iostream>
using namespace std;

int main()
{
	int n, Y = 0, M = 0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int time;
		cin >> time;
		
		Y += time/30 + 1;
		M += time/60 + 1;
	}
	
	if(Y*10 < M*15) {
		cout << "Y " << Y*10 << '\n';
	}
	else if(M*15 < Y*10) {
		cout << "M " << M*15 << '\n';
	}
	else {
		cout << "Y M " << Y*10 << '\n';
	}
	
	
	return 0;
}
