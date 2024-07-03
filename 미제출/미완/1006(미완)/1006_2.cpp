#include <iostream>
#include "room.h"
#include "base2.h"
using namespace std;
#ifndef _DEBUG_
#define _DEBUG_
bool isDebug;
#endif



int main()
{
	int T, N, W, *res = nullptr;
	isDebug = false;
	
	
	cin>>T;
	res = new int[T];
	
	
	for(int i=0; i<T; i++) {
		Base2 base;
		cin>>N>>W;
		base.init(2*N,W);
		if(isDebug)printf("init finished\n");
		res[i] = -1;
		
		
		if(isDebug)printf("[start bunch of mergeAvailRooms()]\n");
		res[i] = 2*N - base.getMaxMergedRoomCnt();
		if(isDebug)printf("[finish bunch of mergeAvailRooms()]\n");
		
		if(isDebug)printf("%d - %d = %d\n", 2*N, 2*N-res[i], res[i]);
		
		//calculate start~
		//base.mergeAvailRooms();
		//~calculate fin
		//res[i] = 2*N - base.getMergedRoomCnt();
		//if(isDebug)printf("%d - %d = %d\n", 2*N, base.getMergedRoomCnt(), res[i]);
		
		
	}
	
	
	for(int i=0; i<T; i++) {
		cout<<res[i]<<endl;
	}
	
	delete[] res;
	return 0;
}










