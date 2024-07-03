#include <iostream>
using namespace std;

int main()
{
	int N = -1, target = -1, cnt = 0, *arr = nullptr;
	
	cin >> N;
	if(N<1) {
		cout << "error : out of bound" << endl;
	}
	arr = new int[N];
	
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	cin >> target;
	
	for(int i=0; i<N; i++) {
		if(arr[i] == target)
			cnt++;
	}
	
	cout << cnt << '\n';
	
	delete[] arr;
	return 0;
}
