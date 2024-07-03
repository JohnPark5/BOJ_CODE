#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 1;
	
	cin >> n;
	
	for(int k=1; ; k++) {
		if(n > 3*k*(k-1)+1) {
			cnt++;
			continue;
		}
		break;		
	}
	
	cout << cnt << endl;
	
	
	return 0;
}

