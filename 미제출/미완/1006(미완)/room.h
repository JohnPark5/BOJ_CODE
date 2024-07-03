#ifndef _ROOM_H_
#define _ROOM_H_

#ifndef _DEBUG_
#define _DEBUG_
bool isDebug;
#endif
#include <iostream>

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



#endif
