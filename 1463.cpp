#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, cnt = 0;
	bool flag = true;
	queue<int> q;
	vector<int> v;
	
	cin >> n;
	
	q.push(n);
	
	while(flag) {
		
		while(q.size() > 0) {
			int x = q.front();
			if(x == 1) {
				flag = false;
				break;
			}
			if(x%3 == 0) {
				v.push_back(x/3);
			}
			if(x%2 == 0) {
				v.push_back(x/2);
			}
			v.push_back(x-1);
			q.pop();
		}
		for(int x : v)
			q.push(x);
		v.clear();
		
		cnt ++;
	}
	
	cout << cnt-1 << '\n';
	
	
	return 0;
}
