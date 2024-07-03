#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr1, arr2;
	int n;
	
	cin >> n;
	
	if(n<1) {
		cout << "error: n<1" << endl;
		exit(0);
	}
	
	for(int i=0; i<n; i++) {
		arr1.push_back(i+1);
	}
	int cnt = 0, phaseCnt = 0;
	do {
		if(phaseCnt%2 == 0) {
			arr2.clear();
			for(auto it = arr1.begin(); it != arr1.end(); it++) {
				if(cnt%2 == 1) {
					arr2.push_back(*it);
				}
				cnt++;
			}
		}
		else {
			arr1.clear();
			for(auto it = arr2.begin(); it != arr2.end(); it++) {
				if(cnt%2 == 1) {
					arr1.push_back(*it);
				}
				cnt++;
			}
		}
		phaseCnt++;
	}while(arr1.size() > 1 && arr2.size() > 1);
	if(arr1.size() == 1) {
		cout << arr1.front() << endl;
	}
	else {
		cout << arr2.front() << endl;
	}
	
	
	
	
	return 0;
}
