#include <iostream>
#include <cmath>
using namespace std;

class Area {
public:
	int x;
	int y;
	int r;
	void get();
	double dist(int x, int y);
	bool contains(int x, int y);
};


int main()
{
	int T=0,*res;
	
	cin>>T;
	
	res = new int[T];
	
	for(int i=0; i<T; i++) {
		int x1,x2,y1,y2,n;
		Area* area;
		res[i] = 0;
		
		cin>>x1>>y1>>x2>>y2;
		cin>>n;
		
		area = new Area[n];
		
		for(int j=0; j<n; j++) {
			
			area[j].get();
		}
		
		//calculate start~
		
		for(int j=0; j<n; j++) {
			bool containsA=area[j].contains(x1,y1), containsB=area[j].contains(x2,y2);
			if(containsA != containsB) {
				res[i]++;
			}
			/*else { //containsA && containsB or !containsA && !containsB
				
			}*/
			
		}
		
		
		
		//~calculate fin
		
		delete[] area;
	}
	
	
	for(int i=0; i<T; i++) {
		cout<<res[i]<<endl;
	}
	
	
	delete[] res;
	return 0;
}

void Area::get() {
	cin>>this->x>>this->y>>this->r;
}

double Area::dist(int x, int y) {
	return sqrt( pow(this->x - x,2) + pow(this->y - y,2) );
}

bool Area::contains(int x, int y) {
	if(dist(x,y)<=this->r) {
		return true;
	}
	return false;
}
