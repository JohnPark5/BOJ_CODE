#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, r, c, res = 0;
	bool xLoc[15] = {false};
	bool yLoc[15] = {false};
	
	cin >> n >> r >> c;
	
	for(int i=0; i<n; i++) {
		static int ix = 0, iy = 0;
		int k = pow(2, n-1-i);
		
		if(c < ix + k) {
			xLoc[i] = false;
		}
		else {
			ix += k;
			xLoc[i] = true;
		}
		
		if(r < iy + k) {
			yLoc[i] = false;
		}
		else {
			iy += k;
			yLoc[i] = true;
		}
		
		int x = pow(4,n-1-i);
		
		if(xLoc[i] == false) {
			if(yLoc[i] == false) {
				
			}
			else {
				res += x * 2;
			}
		}
		else {
			if(yLoc[i] == false) {
				res += x * 1;
			}
			else {
				res += x * 3;
			}
		}
		
	}
	cout << res << '\n';
	
	
	return 0;
}
