#include <iostream>
using namespace std;

int main()
{
	int N,X,*arr; //  (1 ¡Â N, X ¡Â 10,000)
	
	cin >> N >> X;
	if(N<1 || X<1 || N>10000 || X>10000) {
		cout << "error : out of bound" << endl;
	}
	arr = new int[N];
	
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<N; i++) {
		if(arr[i] < X) {
			cout << arr[i] << " ";
		}
	}
	
	
	
	
	delete[] arr;
	return 0;
}
