#include <iostream>
using namespace std;
bool isDebug;

class Room {
	friend const std::istream &operator >>(std::istream &, Room &room);
private:
	void moveTargetIndexToEnd(int target);
	bool deleteEndIndex();
	int enemy;
	int availCnt;
	int availIndex[3];
	bool merged;
public:
	Room();
	
	bool isTargetInAvailIndex(int target);
	bool deleteTargetIndexSafe(int target);
	void setEnemy(int cnt);
	bool addAvailIndex(int idx);
	void setMerged(bool b);
	
	int getEnemy();
	int getAvailCnt();
	int getAvailIndex(int idx);
	int containsAvailIndex(int i);
	bool isMerged();
};

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

int main()
{
	int T, N, W, *res;
	isDebug = false;
	
	
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



int Room::containsAvailIndex(int idx) {
	for(int i=0; i<availCnt; i++) {
		if(availIndex[i] == idx) {
			return true;
		}
	}
	return false;
}

const std::istream &operator >>(std::istream &is, Room &room) {
	is >> room.enemy;
	return is;
}

void Room::setMerged(bool b) {
	merged = b;
}

bool Room::addAvailIndex(int idx) {
	if(availCnt==3 || containsAvailIndex(idx))
		return false;
	availIndex[availCnt++] = idx;
	return true;
}

int Room::getEnemy() {
	return this->enemy;
}

int Room::getAvailCnt() {
	return this->availCnt;
}

int Room::getAvailIndex(int i) {
	if(0<=i && i<availCnt)
		return availIndex[i];
	return -1;
}

bool Room::isMerged() {
	return merged;
}

void Room::setEnemy(int cnt) {
	enemy = cnt;
}

// cant know whether target is not merged
bool Room::isTargetInAvailIndex(int target) {
	for(int i=0; i<availCnt; i++) {
		if(availIndex[i] == target)
			return true;
	}
	return false;
}

void Room::moveTargetIndexToEnd(int target) {
	if(availCnt == 2 && availIndex[0] == target) {
		int tmp = availIndex[0];
		availIndex[0] = availIndex[1];
		availIndex[1] = tmp;
	}
	else if(availCnt == 3) {
		if(availIndex[0] == target) {
			int tmp = availIndex[0];
			availIndex[0] = availIndex[1];
			availIndex[1] = availIndex[2];
			availIndex[2] = tmp;
		}
		else if(availIndex[1] == target) {
			int tmp = availIndex[1];
			availIndex[1] = availIndex[2];
			availIndex[2] = tmp;
		}
	}
}

bool Room::deleteEndIndex() {
	if(availCnt!=0) {
		availIndex[availCnt-1] = -1;
		availCnt--;
		return true;
	}
	return false;
}

bool Room::deleteTargetIndexSafe(int target) {
	if(isTargetInAvailIndex(target)) {
		moveTargetIndexToEnd(target);
		deleteEndIndex();
		return true;
	}
	return false;
}

Room::Room() {
	enemy = 0;
	availCnt = 0;
	availIndex[0] = availIndex[1] = availIndex[2] = 0;
	merged = false;
}



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
void Base::init(int roomCnt, int W) {
	room = new Room[roomCnt];
	this->roomCnt = roomCnt;
	int N = roomCnt/2;
	
	getEnemyCntForRoom();
	
	//calculate does merge available
	if(isDebug) printf("[calculate merge]\n");
	for(int i=0; i<N; i++) {
		if(isDebug) printf("	[about %d]\n",i+1);
		if(room[i].getEnemy()+room[i+N].getEnemy()<=W) {
			if(isDebug) printf("	%d�� %d�� available\n",i+1,i+N+1);
			room[i].addAvailIndex(i+N);
			room[i+N].addAvailIndex(i);
		}
		if(room[i].getEnemy()+room[(i+1)%N].getEnemy()<=W) {
			if(isDebug) printf("	%d�� %d�� available\n",i+1,(i+1)%N+1);
			room[i].addAvailIndex((i+1)%N);
			room[(i+1)%N].addAvailIndex(i);
		}
		if(room[i+N].getEnemy()+room[(i+1)%N+N].getEnemy()<=W) {
			if(isDebug) printf("	%d�� %d�� available\n",i+N+1,(i+1)%N+N+1);
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
		if(isDebug)printf("	[%d���� ������(availCnt:%d)]\n",i+1,room[i].getAvailCnt());
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
			if(isDebug)printf("		[%d���� ������]\n",i+1);
			
			if(room[i].getAvailCnt() == 2) {
				
				if(isDebug)printf("		[%d����-AvailCnt:2 ����]\n",i+1);
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
			if(isDebug)printf("		[%d���� ������]\n",i+1);
			
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
		if(isDebug)printf("	[%d���� ������]\n",i+1);
		
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
	//��.... �ʿ��ϸ� return true (�����ϸ� false) 
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





