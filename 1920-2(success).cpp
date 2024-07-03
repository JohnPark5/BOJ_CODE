#include <iostream>
#include <memory.h>
#include <unordered_set>
using namespace std;

inline void myError(string s) {
	cout << "error : " << s << endl;
	exit(0);
}

int main()
{
	int n = -1, m = -1;
	bool *resArr = nullptr;
	unordered_set<long long int> lliSet;
	
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	if(n<1) 
		myError("n<1");
	
	for(int i=0; i<n; i++) {
		long long int x;
		cin >> x;
		lliSet.insert(x);
	}
	
	cin >> m;
	if(m<1)
		myError("m<1");
	resArr = new bool[m];
	memset(resArr,false,sizeof(resArr));
	
	for(int i=0; i<m; i++) {
		long long int x;
		cin >> x;
		if(lliSet.find(x)!=lliSet.end())
			resArr[i] = true;
	}
	
	for(int i=0; i<m; i++)
		cout << int(resArr[i]) << '\n';
	
	
	return 0;
}

