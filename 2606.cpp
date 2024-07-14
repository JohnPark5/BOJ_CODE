#include <iostream>
#include <vector>
using namespace std;

struct Node {
	bool visited = false;
	vector<int> linkIndexList;
};

void dfs(vector<Node>& node, int index, int& cnt) {
	for(int x : node[index].linkIndexList) {
		if(!node[x].visited) {
			node[x].visited = true;
			cnt++;
			dfs(node, x, cnt);
		}
	}
}

int main()
{
	int n, m, cnt = 0;
	
	cin >> n >> m;
	
	vector<Node> arr(n);
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a-1].linkIndexList.push_back(b-1);
		arr[b-1].linkIndexList.push_back(a-1);
	}
	arr[0].visited = true;
	
	dfs(arr, 0, cnt);
	
	cout << cnt << '\n';
	
	
	return 0;
}
