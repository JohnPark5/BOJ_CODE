#include <iostream>
#include <memory.h>
using namespace std;

struct Node {
	bool isPlanted;
	bool isChecked;
};

class Map {
private:
	Node map[50][50];
	int m, n;
public:
	Map() {
		memset(map,false,sizeof(map));
	}
	void init(int m, int n, int k);
	void checkAround(int, int);
	void check(int x, int y) {
		if(isValidRange(x,y))
			map[x][y].isChecked = true;
	}
	bool isValidRange(int x, int y) {
		if(x<0 || x>=m || y<0 || y>=n) return false;
		return true;
	}
	bool isPlantedButNotChecked(int x, int y) {
		if(map[x][y].isPlanted == true && map[x][y].isChecked == false)
			return true;
		return false;
	}
};

void Map::checkAround(int targetX, int targetY) {
	if(!isValidRange(targetX, targetY)) return;
	if(map[targetX][targetY].isPlanted == false) return;
	if(map[targetX][targetY].isChecked == false) check(targetX, targetY);
	
	checkAround(targetX-1, targetY-1);
	checkAround(targetX-1, targetY+1);
	checkAround(targetX+1, targetY-1);
	checkAround(targetX+1, targetY+1);
}

void Map::init(int m, int n, int k) {
	this->m = m;
	this->n = n;
	for(int i=0; i<k; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y].isPlanted = true;
	}
	
}

int main()
{
	int T, *res;
	
	cin >> T;
	
	if(T<1)exit(0);
	
	res = new int[T];
	
	for(int t=0; t<T; t++) {
		int m, n, k;
		Map map;
		res[t] = 0;
		
		cin >> m >> n >> k;
		
		map.init(m, n, k);
		
					cout << "!";
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(map.isPlantedButNotChecked(i,j)) {
					res[t]++;
					map.checkAround(i,j);
					cout << "*";
				}
			}
		}
		
	}
	
	for(int t=0; t<T; t++)
		cout << res[t] << '\n';
			
	
	delete[] res;
	return 0;
}









