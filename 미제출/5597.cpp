#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	bool stu[30];
	memset(stu,false,sizeof(bool)*30);
	
	for(int i=0; i<28; i++) {
		int idx;
		cin >> idx; 
		stu[idx-1] = true;
	}
	
	for(int i=0; i<30; i++) {
		if(!stu[i])
			cout << i+1 << endl;
	}
	
	return 0;
}
