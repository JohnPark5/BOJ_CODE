#include <iostream>
using namespace std;

int main()
{
	int a, b, tmp;
	
	cin >> a >> b;
	
	if(a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	
	int gcd = 1;
	for(int i=1; i <= b; i++) {
		if(a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	
	cout << gcd << endl << a * b / gcd << endl;
	
	
	return 0;
}

