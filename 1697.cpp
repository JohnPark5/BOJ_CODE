#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getMinTime_Queue(int start, int goal) {
	queue<int> arr;
	vector<int> tmp;
	bool visited[200001] = {false};
	int depth = 0;
	if(start == goal) return 0;
	
	if(start-1>=0) arr.push(start-1);
	if(start+1<=goal) arr.push(start+1);
	if(start<goal) arr.push(start*2);
	
	//cout << "front : " << arr.front() << '\n';
	
	while(true) {
		while(arr.size()>0) {
			int x = arr.front();
			arr.pop();
			visited[x] = true;
			
			if(x == goal) return depth+1;
			
			if(x-1>=0 && !visited[x-1]) tmp.push_back(x-1);
			if(x+1<=goal && !visited[x+1]) tmp.push_back(x+1);
			if(x<goal && !visited[x*2]) tmp.push_back(x*2);
			//cout << "front : " << arr.front() << ", depth : " << depth << '\n';
		}
		for(auto it : tmp) {
			arr.push(it);
		}
		tmp.clear();
		depth++;
	}
}

//최대깊이 30으로 지정(여유있게) 
int main()
{
	int n, k, res;
	
	cin >> n >> k;
	
	res = getMinTime_Queue(n, k);
	
	cout << res << '\n';
	
	
	return 0;
}
