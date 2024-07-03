#ifndef _BASE_H_
#define _Base_H_

#ifndef _DEBUG_
#define _DEBUG_
bool isDebug;
#endif

#include <iostream>
#include "room.h"
using namespace std;




class Base {
private:
	bool MAR_Phase1();
	bool MAR_Phase2();
	bool MAR_Phase3();
	Room *room;
	int roomCnt;
	int mergedRoomCnt;
public:
	Base();
	~Base();
	
	void init(int roomCnt, int W);
	void getEnemyCntForRoom();
	void mergeAvailRooms();
	void mergeRoom(int idx1, int idx2);
	bool isAvailCntRoomExist(int cnt);
	int getRoomCntOfAvailCnt(int cnt);
	bool finished();
	
	
	int getRoomCnt();
	int getMergedRoomCnt();
};

bool Base::finished() {
	for(int i=0; i<roomCnt; i++) {
		if(!room[i].isMerged() && room[i].getAvailCnt() > 0)
			return false;
	}
	return false;
}


/* TODO (#1#): add using : getRoomCntOfAvailCntIs(int cnt) */
void Base::mergeAvailRooms() {
	bool flag = true;

	if(roomCnt == 2) {
		if(isAvailCntRoomExist(1)) {
			mergeRoom(0,1);
			return;
		}
	}
	
	if(isAvailCntRoomExist(1)) {
		while(isAvailCntRoomExist(1) && flag && !finished())
			flag = MAR_Phase1();
	}
	
	if(!isAvailCntRoomExist(1) && isAvailCntRoomExist(2)) { // only availCnt>1 rooms are left
		while(isAvailCntRoomExist(2) && flag && !finished()) {
			
			while(!isAvailCntRoomExist(1) && flag && !finished())
				flag = MAR_Phase2();
		
			while(isAvailCntRoomExist(1) && flag && !finished())
				flag = MAR_Phase1();
		}
	}
	
	if(!isAvailCntRoomExist(1) && !isAvailCntRoomExist(2) && isAvailCntRoomExist(3) && !finished()) { // only availCnt>2 rooms are left
		while(isAvailCntRoomExist(3) && flag && !finished()) {
			
			while(!isAvailCntRoomExist(1) && !isAvailCntRoomExist(2) && flag && !finished())
				flag = MAR_Phase3();
			
			while(isAvailCntRoomExist(1) && flag && !finished())
				flag = MAR_Phase1();
		
			while(isAvailCntRoomExist(2) && flag && !finished())
				flag = MAR_Phase2();
			
			while(isAvailCntRoomExist(1) && flag && !finished())
				flag = MAR_Phase1();
		
		}
	}
	
}

int Base::getRoomCnt() {
	return this->roomCnt;
}

int Base::getMergedRoomCnt() {
	return this->mergedRoomCnt;
}

// before this func, roomCnt need to be init
void Base::getEnemyCntForRoom() {
	for(int i=0; i<roomCnt; i++) {
		cin>>room[i];
	}
}

int Base::getRoomCntOfAvailCnt(int cnt) {
	int sum = 0;
	for(int i=0; i<roomCnt; i++) {
		if(room[i].getAvailCnt() == cnt && !room[i].isMerged()) {
			sum++;
		}
	}
	return sum;
}

// roomCnt: 2*N
// N만큼의 테스트 케이스를 만들어 최소값 찾기. 
void Base::init(int roomCnt, int W) {
	room = new Room[roomCnt];
	this->roomCnt = roomCnt;
	int N = roomCnt/2;
	
	getEnemyCntForRoom();
	
	//calculate does merge available
	if(isDebug) printf("[calculate merge]\n");
	
	if(roomCnt == 2) {
		if(room[0].getEnemy() + room[1].getEnemy() <= W) {
			if(isDebug) printf("	1과 2는 available\n");
			room[0].addAvailIndex(1);
			room[1].addAvailIndex(0);
			return;
		}
		return;
	}
	
	for(int i=0; i<N; i++) {
		if(isDebug) printf("	[about %d]\n",i+1);
		if(room[i].getEnemy()+room[i+N].getEnemy()<=W) {
			if(isDebug) printf("	%d와 %d는 available\n",i+1,i+N+1);
			room[i].addAvailIndex(i+N);
			room[i+N].addAvailIndex(i);
		}
		if(room[i].getEnemy()+room[(i+1)%N].getEnemy()<=W) {
			if(isDebug) printf("	%d와 %d는 available\n",i+1,(i+1)%N+1);
			room[i].addAvailIndex((i+1)%N);
			room[(i+1)%N].addAvailIndex(i);
		}
		if(room[i+N].getEnemy()+room[(i+1)%N+N].getEnemy()<=W) {
			if(isDebug) printf("	%d와 %d는 available\n",i+N+1,(i+1)%N+N+1);
			room[i+N].addAvailIndex((i+1)%N+N);
			room[(i+1)%N+N].addAvailIndex(i+N);
		}
	
	}
	
}

bool Base::MAR_Phase1() {
	if(isDebug)printf("[MAR_Phase1 start]\n");
	bool needMorePhase = false;
	
	for(int i=0; i<roomCnt; i++) {
		if(room[i].isMerged())continue;
		if(isDebug)printf("	[%d번방 진행중(availCnt:%d)]\n",i+1,room[i].getAvailCnt());
		if(isDebug) {
			printf("	[	");
			for(int j=0; j<roomCnt; j++) {
				if(j==0)printf("%d",room[j].getAvailCnt());
				else printf(", %d",room[j].getAvailCnt());
			}
			printf("]\n");
		}
		
		if(room[i].getAvailCnt() == 1 && !room[room[i].getAvailIndex(0)].isMerged()) {
			if(isDebug)printf("[MAR_Phase1 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(0)+1);
			mergeRoom(i,room[i].getAvailIndex(0)); 
			
			return true;
		}
	
	}
	if(isDebug)printf("error[MAR_Phase1]?\n");
	return false;
	
	
}

// when all avail Room's availCnt>1 
bool Base::MAR_Phase2() {
	if(isDebug)printf("[MAR_Phase2 start]\n");
	if(getRoomCntOfAvailCnt(2)>1) {
		if(isDebug)printf("	[getRoomCntOfAvailCnt(2)>1]\n");
		for(int i=0; i<roomCnt; i++) {
			if(room[i].isMerged()) continue;
			if(isDebug)printf("		[%d번방 진행중]\n",i+1);
			
			if(room[i].getAvailCnt() == 2) {
				
				if(isDebug)printf("		[%d번방-AvailCnt:2 진행]\n",i+1);
				if(/*room[room[i].getAvailIndex(0)].getAvailCnt() == 2 && */!room[room[i].getAvailIndex(0)].isMerged()) {
					if(isDebug)printf("		[MAR_Phase2 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(0)+1);
					mergeRoom(i,room[i].getAvailIndex(0));
					return true;
				}
				else if(/*room[room[i].getAvailIndex(1)].getAvailCnt() == 2 && */!room[room[i].getAvailIndex(1)].isMerged()) {
					if(isDebug)printf("		[MAR_Phase2 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(1)+1);
					mergeRoom(i,room[i].getAvailIndex(1));
					return true;
				}
			}
		}
	}
	else { // room's availCnt is -> 0,0,..,2,3,3,...
		if(isDebug)printf("	[getRoomCntOfAvailCnt(2)==1]\n");
		for(int i=0; i<roomCnt; i++) {
			if(room[i].isMerged()) continue;
			if(isDebug)printf("		[%d번방 진행중]\n",i+1);
			
			if(room[i].getAvailCnt() == 2) {
				if(!room[room[i].getAvailIndex(0)].isMerged()) {
					if(isDebug)printf("	[MAR_Phase2 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(0)+1);
					mergeRoom(i,room[i].getAvailIndex(0));
					return true;
				}
				else if(!room[room[i].getAvailIndex(1)].isMerged()) {
					if(isDebug)printf("	[MAR_Phase2 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(1)+1);
					mergeRoom(i,room[i].getAvailIndex(1));
					return true;
				}
				else {
					if(isDebug)printf("error[MAR_Phase2]_in for loop");
					exit(0);
				}
				
			}
		}
	}
	if(isDebug)printf("error[MAR_Phase2]?\n");
	return false;
}

// when all avail Room's availCnt>2
bool Base::MAR_Phase3() {
	if(isDebug)printf("[MAR_Phase3 start]\n");
	for(int i=0; i<roomCnt; i++) {
		if(room[i].isMerged()) continue;
		if(isDebug)printf("	[%d번방 진행중]\n",i+1);
		
		for(int j=0; j<3; j++) {
			if(!room[room[i].getAvailIndex(j)].isMerged()) {
				mergeRoom(i,room[i].getAvailIndex(j));
				if(isDebug)printf("	[MAR_Phase3 merged(%d,%d), finish phase]\n",i+1,room[i].getAvailIndex(j)+1);
				return true;
			}
		}
	}
	if(isDebug)printf("error[MAR_Phase3]?\n");
	return false;
	//정.... 필요하면 return true (웬만하면 false) 
}

void Base::mergeRoom(int idx1, int idx2) {
	//delete each idx and organize(pull)
	//room[idx1].findAndDeletefromAvailIndex(idx2);
	//room[idx2].findAndDeletefromAvailIndex(idx1);
	
	room[idx1].deleteTargetIndexSafe(idx2);
	room[idx2].deleteTargetIndexSafe(idx1);
	
	
	for(int i=0; i<room[idx1].getAvailCnt(); i++) {
		room[room[idx1].getAvailIndex(i)].deleteTargetIndexSafe(idx1);
	}
	for(int i=0; i<room[idx2].getAvailCnt(); i++) {
		room[room[idx2].getAvailIndex(i)].deleteTargetIndexSafe(idx2);
	}
	
	room[idx1].setMerged(true);
	room[idx2].setMerged(true);
	
	mergedRoomCnt++;
}

bool Base::isAvailCntRoomExist(int cnt) {
	for(int i=0; i<roomCnt; i++) {
		if(room[i].getAvailCnt()==cnt && !room[i].isMerged()) {
			return true;
		}
	}
	return false;
}

Base::Base() {
	room = NULL;
	roomCnt = 0;
	mergedRoomCnt = 0;
}

Base::~Base() {
	delete[] room;
}


#endif




		/*기존merges for문안에 
		if(room[i].availCnt>0 && !room[i].merged) {
			if(room[i].availCnt == 1) {
				if(isDebug)printf("yet merged, availCnt : 1\n");
				if(!room[room[i].availIndex[0]].merged) {
					if(isDebug)printf("%d번방(%d)과 %d번방(%d)이 병합 가능하므로\n",i+1,room[i].enemy,room[i].availIndex[0]+1,room[room[i].availIndex[0]].enemy);
					if(isDebug)printf("(%d,%d) 병합\n",i+1,room[i].availIndex[0]+1);
					mergeRoom(i,room[i].availIndex[0]); 
					if(isDebug)printf("병합 이후 %d번방의availCnt:%d, %d번방의 availCnt:%d\n",i+1,room[i].availCnt,room[i].availIndex[0]+1,room[room[i].availIndex[0]].availCnt);
				}
			}
			else {
				if(isDebug)printf("yet merged, availCnt>1\n");
				bool flag = true;
				for(int j=0; j<room[i].availCnt && flag; j++) {
					if(room[room[i].availIndex[j]].availCnt == 1 && !room[room[i].availIndex[j]].merged) {
						
						if(isDebug)printf("%d번방(%d)과 %d번방(%d)이 병합 가능하므로\n",i+1,room[i].enemy,room[i].availIndex[j]+1,room[room[i].availIndex[j]].enemy);
						if(isDebug)printf("(%d,%d) 병합\n",i+1,room[i].availIndex[j]+1);
						mergeRoom(i,room[i].availIndex[j]);
						if(isDebug)printf("병합 이후 %d번방의availCnt:%d, %d번방의 availCnt:%d\n",i+1,room[i].availCnt,room[i].availIndex[j]+1,room[room[i].availIndex[j]].availCnt);
						flag = false;
					}
					else {
						needMorePhase = true;
					}
				}
			}
		}
		else
			if(isDebug)printf("다음방바로진행사유:availCnt:%d, meged:%s\n",room[i].availCnt,(room[i].merged)?"true":"false");
			*/
