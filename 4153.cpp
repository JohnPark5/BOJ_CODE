#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int a = -1, b = -1, c = -1;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(true) {
		vector<int> side;
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		side.push_back(a);
		side.push_back(b);
		side.push_back(c);
		
		sort(side.begin(), side.end(), greater<int>());
		
		if(side[0]*side[0] != side[1]*side[1] + side[2]*side[2]) {
			cout << "wrong" << '\n';
		}
		else {
			cout << "right" << '\n';
		}
	}
	
	
	return 0;
}
