#include <iostream>
using namespace std;

int main()
{
	int num[9], max = 0, maxIndex = -1;
	
	for(int i=0; i<9; i++) {
		cin >> num[i];
		if(num[i] > max) {
			max = num[i];
			maxIndex = i+1;
		}
	}
	
	cout << max << '\n' << maxIndex << '\n';	
	
	return 0;
}
