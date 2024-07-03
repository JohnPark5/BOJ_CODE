#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <memory.h>
using namespace std;

struct Node {
	int num;
	bool isVisited = false;
	set<Node*> link;
};

void dfs(Node* node);
void bfs(Node* node);

int main()
{
	int n, m, v;
	Node* node = nullptr;
	
	cin >> n >> m >> v;
	if(n<1 || n > 1000)exit(123);
	node = new Node[n];
	
	for(int i=0; i<n; i++) node[i].num = i+1;
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		
		node[a-1].link.insert(&node[b-1]);
		node[b-1].link.insert(&node[a-1]);
	}
	
	dfs(&node[v-1]);
	cout << '\n';
	for(int i=0; i<n; i++) node[i].isVisited = false;
	bfs(&node[v-1]);
	
	
	return 0;
}

void dfs(Node* node) {
	node->isVisited = true;
	cout << node->num << " ";
	
	for(Node* link : node->link) {
		if(!link->isVisited) {
			dfs(link);
		}
	}
}

void bfs(Node* node) {
	queue<Node*> toVisit;
	toVisit.push(node);
	
	while(toVisit.size() > 0) {
		Node* now = toVisit.front();
		now->isVisited = true;
		cout << now->num << " ";
		toVisit.pop();
		for(Node* link : now->link) {
			if(!link->isVisited) {
				link->isVisited = true;
				toVisit.push(link);
			}
		}
	}
}

