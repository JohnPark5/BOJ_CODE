#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int testcase;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> testcase;
	
	while(testcase--) {
		int x, y, d;
		
		cin >> x >> y;
		d = y - x;
		
		int sqrtfloor = floor(sqrt(d));
		if(sqrtfloor * sqrtfloor == d) {
			cout << 2 * sqrtfloor - 1 << '\n';
		}
		else if(d <= sqrtfloor * (sqrtfloor + 1)) {
			cout << 2 * sqrtfloor << '\n';
		}
		else {
			cout << 2 * sqrtfloor + 1 << '\n';
		}
	}
	
	
	return 0;
}
