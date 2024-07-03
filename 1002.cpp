#include <iostream>
#include <cmath>
using namespace std;

double diff(int x1, int y1, int x2, int y2) {
	return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

int main()
{
	int T=0, x1=0, x2=0, y1=0, y2=0, r1=0, r2=0, *res;
	
	cin>>T;
	if(T < 1) {
		cout<<"error:T<1"<<endl;
		exit(0);
	}
	
	res = new int[T];
	
	for(int i=0; i<T; i++) {
		x1 = y1 = r1 = x2 = y2 = r2 = 0;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		if(r1 < r2) {
			int tmp=r1;
			r1=r2;
			r2=tmp;
		}
		//r1>r2
		
		if(x1==x2 && y1==y2) {
			if(r1 == r2) {
				res[i] = -1;
			}
			else {
				res[i] = 0;
			}
		}
		else {
			double len = diff(x1,y1,x2,y2);
			
			if(r1 + r2 < len) {
				res[i] = 0;
			}
			else if(r1 + r2 == len) {
				res[i] = 1;
			}
			else if(r1 + r2 > len) {
				if(r1>len+r2) {
					res[i] = 0;
				}
				else if(r1 == len + r2) {
					res[i] = 1;
				}
				else {
					res[i] = 2;
				}
			}
			else {
				cout<<"error:if"<<endl;
			}
			
			
		}
	}
	
	for(int i=0; i<T; i++) {
		cout<<res[i]<<endl;
	}
	
	
	delete[] res;
	return 0;
}
