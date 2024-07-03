#include <iostream>
#include <memory.h>
#define MAX_INT 2147483647;
using namespace std;

bool isDebug;

// startX, startY : 0 ~ 42
// startCharacter : W or B
int needToPaint(int startX, int startY, char startCharacter,const char (*arr)[50]);

int main()
{
	int m, n, targetIndexX = -1, targetIndexY = -1, minPaintCnt = MAX_INT;
	char arr[50][50];
	memset(arr,0,sizeof(arr));
	
	isDebug = false;
	
	// 8 <= n,m <= 50
	cin >> n >> m;
	
	if(n<8 || m<8 || n>50 || m>50) {
		cout << "error : n,m bounds" << endl;
		exit(0);
	}
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> arr[i][j];
	if(isDebug)printf("start\n");
	for(int i=0; i<n-7; i++) {
		for(int j=0; j<m-7; j++) {
			int k;
			if(isDebug)printf("doing [%d,%d]\n",i+1,j+1);
			if(minPaintCnt > (k = needToPaint(i,j,'W',arr)))
				minPaintCnt = k;
			if(minPaintCnt > (k = needToPaint(i,j,'B',arr)))
				minPaintCnt = k;
		}
	}
	
	cout << minPaintCnt << '\n';
	
	return 0;
}

// startX, startY : 0 ~ 42
// startCharacter : W or B
int needToPaint(int startX, int startY, char startCharacter,const char (*arr)[50]) {
	int cnt = 0;
	char nextCharacter;
	
	if(startCharacter == 'W' || startCharacter == 'w')
		startCharacter = 'W', nextCharacter = 'B';
	else if(startCharacter == 'B' || startCharacter == 'b')
		startCharacter = 'B', nextCharacter = 'W';
	else {
		cout << "error : not w or b ar nTP_func" << endl;
		exit(0);
	}
	if(isDebug)printf("[starting nTP(%d,%d,%c)]\n",startX+1,startY+1,startCharacter);
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(isDebug)printf(" [i:%d,j:%d,cnt:%d]\n",i,j,cnt);
			if(i%2 == 0) {
				if(j%2 == 0) {
					if(arr[i+startX][j+startY] != startCharacter)
						cnt++;
				}
				else {
					if(arr[i+startX][j+startY] != nextCharacter)
						cnt++;
				}
			}
			else {
				if(j%2 == 0) {
					if(arr[i+startX][j+startY] != nextCharacter)
						cnt++;
				}
				else {
					if(arr[i+startX][j+startY] != startCharacter)
						cnt++;
				}
			}
		}
	}
	
	
	
	return cnt;
}



















