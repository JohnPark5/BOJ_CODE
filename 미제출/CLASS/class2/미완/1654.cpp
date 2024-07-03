#include <iostream>
using namespace std;

inline unsigned long long int getValidLineSum(unsigned long long int* line, unsigned long long int k, unsigned long long int prd);

int main()
{
	unsigned long long int k,n,*line,sum=0,prd,res;
	
	cin >> k>> n;
	if(k<1) {
		cout << "error : k<1" << endl;
		exit(0);
	}
	line = new unsigned long long int[k];
	
	for(int i=0; i<k; i++) {
		cin >> line[i];
		sum += line[i];
	}
	
	for(prd=sum/n; prd>0; prd--) {
		if(getValidLineSum(line,k,prd) >= n) {
			res = prd;
			break;
		}
	}
	
	cout << res << '\n';
	
	
	
	delete [] line;
	return 0;
}


inline unsigned long long int getValidLineSum(unsigned long long int* line, unsigned long long int k, unsigned long long int prd) {
	unsigned long long int cnt = 0;
	for(int i=0; i<k; i++) {
		cnt += line[i]/prd;
	}
	return cnt;
}











