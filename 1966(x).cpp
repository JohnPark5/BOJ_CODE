#include <iostream>
#include <deque>
using namespace std;

struct Document {
	int priority;
	int num;
	Document(int n) {
		this->num = n;
	}
	void init() {
		cin >> priority;
	}
};

int getMaxPriority(deque<Document> documents, int cnt);

inline void myError(string s) {
	cout << "error : " << s << endl;
	exit(0);
}

int main()
{
	int T, n, targetIndex, *res = nullptr;
	deque<Document> docu;
	
	cin >> T;
	
	if(T<1)
		myError("T<1");
	res = new int[T];
	
	for(int t=0; t<T; t++) {
		int orderNum = 0;
		int maxPriority = -1;
		res[t] = -1;
		cin >> n >> targetIndex;
		
		
		for(int i=0; i<n; i++) {
			Document tmp(n);
			tmp.init();
			docu.push(tmp);
		}
		
		
		maxPriority = getMaxPriority(docu,n);
		
		while(docu.size()>0) {
			orderNum++;
			do {
				if(docu.front().priority!=maxPriority) {
					docu.push(docu.front());
					docu.pop();
				}
				maxPriority = getMaxPriority(docu,n);
			}while(docu.front().priority < maxPriority);
			if(docu.front().num-1 == targetIndex) {
				res[t] = orderNum;
				while(docu.size()>0)docu.pop();
			}
			else {
				docu.pop();
			}
			
		}
		
		
	}
	
	for(int t; t<T; t++) {
		cout << res[t] << '\n';
	}
	
	
	
	
	
	delete[] res;
	return 0;
}


int getMaxPriority(queue<Document> documents, int cnt) {
	int max;
	for(queue<Document>::iterator it = documents.begin(); it!=documents.end(); it++) {
		if(it == documents.begin())  {
			max = it->priority;
			continue;
		}
		
		if(it->priority > max) max = it->priority;
	}
	return max;
}






















