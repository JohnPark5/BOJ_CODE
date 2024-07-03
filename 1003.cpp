#include <iostream>
using namespace std;

int main()
{
	int T=0, **res;
	
	cin>>T;
	if(T<1) {
		cout<<"error:T<1"<<endl;
		exit(0);
	}
	res = new int*[T]; 
	
	
	for(int i=0; i<T; i++) {
		res[i] = new int[2];
		int k=0, a=0, b=1;
		cin>>k;
		
		if(k==0) {
			res[i][0] = 1;
			res[i][1] = 0;
		} 
		else if(k==1) {
			res[i][0] = 0;
			res[i][1] = 1;
		}
		else {
			int j;
			for(j=0; j<k-1; j++) {
				if(j%2==0) {
					a += b;
				}
				else {
					b += a;
				}
			}
			if(j%2==0) {
				res[i][0] = a;
				res[i][1] = b;
			}
			else {
				res[i][0] = b;
				res[i][1] = a;
			}
		}
	}
	
	
	for(int i=0; i<T; i++) {
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
		delete[] res[i];
	}
	
	delete[] res;
	return 0;
}
