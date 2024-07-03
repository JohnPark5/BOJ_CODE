#include <iostream>
using namespace std;

int main()
{
	int n; // 0~500
	int cnt_2 = 0, cnt_5 = 0, cnt_10 = 0;
	
	cin >> n;
	
	for(int i=2; i<=n; i++) {
		int k=i;
		//cout<<i<<"¿¡¼­"<<endl;
		while(k%10 == 0) 
			k/=10, cnt_10++;//, cout<<"10"<<endl;
		while(k%5 == 0) 
			k/=5, cnt_5++;//, cout<<"5"<<endl;
		while(k%2 == 0) 
			k/=2, cnt_2++;//, cout<<"2"<<endl;
	}
	
	cnt_2 += cnt_10;
	cnt_5 += cnt_10;
	cnt_10 = 0;
	
	if(cnt_2<cnt_5)
		cout << cnt_2 << endl;
	else
		cout << cnt_5 << endl;
	
	
	return 0;
}
