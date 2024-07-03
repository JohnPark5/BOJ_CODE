#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

struct Node {
	bool isPlanted = false;
	bool isChecked = false;
};

bool isDebug = false;
void debug(string s, int tab) {
	cout << "[";for(int i=0; i<tab; i++) cout << "\t";
	cout << s << " ]" << '\n';
}

void check_around(Node (*area)[50], int m, int n, int x, int y) {
	int x1, y1;
	
	//범위문제 x  (미리 체크됨) 
	area[x][y].isChecked = true;
	if(isDebug){cout<<"[check_around start(checked : ("<<x<<","<<y<<")]\n";}
	x1 = x-1;
	y1 = y;
	if(0 <= x1 && x1 < m && 0 <= y1 && y1 < n) {
		if(isDebug)debug("check_around start[1]",1);
		if(area[x1][y1].isPlanted && !area[x1][y1].isChecked) {
			if(isDebug){cout<<"[		check_around start[1-1](checking : ("<<x1<<","<<y1<<")]\n";}
			check_around(area,m,n,x1,y1);
			if(isDebug){cout<<"[		check_around end[1-1](checking : ("<<x1<<","<<y1<<")]\n";}
		}
	} 
	x1 = x+1;
	y1 = y;
	if(0 <= x1 && x1 < m && 0 <= y1 && y1 < n) {
		if(isDebug)debug("check_around start[2]",1);
		if(area[x1][y1].isPlanted && !area[x1][y1].isChecked) {
			if(isDebug){cout<<"[		check_around start[2-1](checking : ("<<x1<<","<<y1<<")]\n";}
			check_around(area,m,n,x1,y1);
			if(isDebug){cout<<"[		check_around end[2-1](checking : ("<<x1<<","<<y1<<")]\n";}
		}
	} 
	x1 = x;
	y1 = y-1;
	if(0 <= x1 && x1 < m && 0 <= y1 && y1 < n) {
		if(isDebug)debug("check_around start[3]",1);
		if(area[x1][y1].isPlanted && !area[x1][y1].isChecked) {
			if(isDebug){cout<<"[		check_around start[3-1](checking : ("<<x1<<","<<y1<<")]\n";}
			check_around(area,m,n,x1,y1);
			if(isDebug){cout<<"[		check_around end[3-1](checking : ("<<x1<<","<<y1<<")]\n";}
		}
	} 
	x1 = x;
	y1 = y+1;
	if(0 <= x1 && x1 < m && 0 <= y1 && y1 < n) {
		if(isDebug)debug("check_around start[4]",1);
		if(area[x1][y1].isPlanted && !area[x1][y1].isChecked) {
			if(isDebug){cout<<"[		check_around start[4-1](checking : ("<<x1<<","<<y1<<")]\n";}
			check_around(area,m,n,x1,y1);
			if(isDebug){cout<<"[		check_around end[4-1](checking : ("<<x1<<","<<y1<<")]\n";}
		}
	} 
}

int main()
{
	int T;
	Node area[50][50];
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	//cin.tie(nullptr);
	
	for(int t=0; t<T; t++) {
		int m, n, k, cnt=0;
		memset(area,false,sizeof(area));
		
		cin >> m >> n >> k;
		
		for(int i=0; i<k; i++) {
			int x, y;
			
			cin >> x >> y;
			if(x<0 || x>=m || y<0 || y>=n) {
				cout << "out of bound" << endl;
				exit(0);
			}
			area[x][y].isPlanted = true;
			
		}
		
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(area[i][j].isPlanted && !area[i][j].isChecked) {
					cnt++;
					check_around(area, m, n, i, j);
				}
			}
		}
		cout << cnt << '\n';		
	}
	
	
	
	return 0;
}
