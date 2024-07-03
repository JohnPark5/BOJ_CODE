#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

struct Node {
	int num;
	int priority;
	void init(int num) {
		this->num = num;
		cin >> priority;
		priority--;
	}
};

int main()
{
	int T, n, targetIndex, *res = nullptr;
	queue<Node> nq;
	int priorCnt[9];
	memset(priorCnt,0,sizeof(priorCnt));
	
	cin >> T;
	
	if(T<1) {
		cout << "error : T<1" << endl;
		exit(0);
	}
	res = new int[T];
	
	for(int t=0; t<T; t++) {
		int curMaxPrior = -1;
		nq = queue<Node>(); // clear
		memset(priorCnt,0,sizeof(priorCnt));
		
		cin >> n >> targetIndex;
		
		for(int i=0; i<n; i++) {
			Node n;
			n.init(i);
			nq.push(n); // hmm..
			if(curMaxPrior < n.priority) curMaxPrior = n.priority;
			priorCnt[n.priority]++;
		}
		
		int orderNum = 0;
		
		while(nq.size()>0) {
			if(nq.front().priority == curMaxPrior) {
				orderNum++;
				
				if(nq.front().num == targetIndex) {
					res[t] = orderNum;
					while(nq.size()>0)nq.pop();
					break;
				}
				
				nq.pop();
				
				priorCnt[curMaxPrior]--;
				for(int i=curMaxPrior; i>=0; i--) {
					if(priorCnt[i] > 0) {
						curMaxPrior = i;
						break;
					} 
				}
			}
			else {
				nq.push(nq.front());
				nq.pop();
			}
		}
	}
	
	for(int t=0; t<T; t++) {
		cout << res[t] << '\n';
	}
	
	
	delete[] res;
	return 0;
}

