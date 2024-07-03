#include <iostream>
using namespace std;

int main()
{
	int T, a, b, *res=NULL;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	
	if(T<1) {
		cout << "error! T<0" << endl;
		exit(0);
	}
	res = new int[T];
	
	for(int i=0; i<T; i++) {
		cin >> a >> b;
		res[i] = a + b;
	}
	
	for(int i=0; i<T; i++) {
		cout << res[i] << '\n';
	}
	
	delete[] res;
	return 0;
}
