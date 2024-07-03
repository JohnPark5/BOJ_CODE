#include <iostream>
#define PI 3.14159265358979
using namespace std;

int main()
{
	double a,r,p1,p2;
	
	cin >> a >> p1;
	cin >> r >> p2;
	
	if(a/p1 > r*r*PI/p2)
		cout << "Slice of pizza" << '\n';
	else
		cout << "Whole pizza" << '\n';
	
	
	return 0;
}
