#include <iostream>
#include "room.h"
#include "base.h"
using namespace std;
#ifndef _DEBUG_
#define _DEBUG_
bool isDebug;
#endif



int main()
{
	int T, N, W, *res;
	isDebug = true;
	
	
	cin>>T;
	res = new int[T];
	
	
	for(int i=0; i<T; i++) {
		Base base;
		cin>>N>>W;
		base.init(2*N,W);
		if(isDebug)printf("init finished\n");
		res[i] = 0;
		
		//calculate start~
		if(isDebug)printf("[start mergeAvailRooms()]\n");
		base.mergeAvailRooms();
		if(isDebug)printf("[finish mergeAvailRooms()]\n");
		//~calculate fin
		res[i] = 2*N - base.getMergedRoomCnt();
		if(isDebug)printf("%d - %d = %d\n", 2*N, base.getMergedRoomCnt(), res[i]);
		
		
	}
	
	
	for(int i=0; i<T; i++) {
		cout<<res[i]<<endl;
	}
	
	delete[] res;
	return 0;
}










