#include <iostream>
using namespace std;

int main()
{
	long long int n, res=1, cnt_10=0, cnt_2=0, cnt_5=0;
	
	cin >> n;
	
	for(int i=n; i>0; i--) {
		int k = i;
		while(k%10 == 0) {
			cnt_10 ++;
			k/=10;
		}
		while(k%5 == 0) {
			cnt_5 ++;
			k/=5;
		}
		while(k%2 == 0) {
			cnt_2 ++;
			k/=2;
		}
		res *= k;
	}
	
	while(cnt_2>0 && cnt_5>0) {
		cnt_10 ++;
		cnt_2 --;
		cnt_5 --;
	}
	for(int i=0; i<cnt_2; i++) res*=2;
	for(int i=0; i<cnt_5; i++) res*=5;
	
	cout << res;
	for(int i=0; i<cnt_10; i++) cout << "0";
	
	
	return 0;
}
