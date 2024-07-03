#include <iostream>
using namespace std;

int main()
{
	int N, *iArr, min, max;
	
	cin >> N;
	if(N<1) {
		cout << "error : N < 1" << endl;
		exit(0);
	}
	iArr = new int[N];
	
	for(int i=0; i<N; i++) {
		cin >> iArr[i];
		if(i==0) {
			min = max = iArr[i];
		}
		else {
			if(min>iArr[i])
				min = iArr[i];
			if(max<iArr[i])
				max = iArr[i];
		}
	}
	cout << min << " " << max << endl;	
	
	delete[] iArr;
	return 0;
}
