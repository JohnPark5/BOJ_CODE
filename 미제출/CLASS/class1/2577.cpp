#include <iostream>
using namespace std;

int main()
{
	int A, B, C, res, cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	
	cin >> A >> B >> C;
	
	res = A*B*C;
	
	
	while(res>=1) {
		int k = res%10;
		res/=10;
		cnt[k]++;
	}
	
	for(int i=0; i<10; i++) {
		cout << cnt[i] << endl;
	}
	
	return 0;
}
