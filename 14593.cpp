#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Participant {
	int num, score, cnt, time;
	Participant(int num, int score, int cnt, int time) {
		this->num = num;
		this->score = score;
		this->cnt = cnt;
		this->time = time;
	}
};

bool mySort(const Participant& a, const Participant& b) {
	if(a.score != b.score) return a.score > b.score;
	if(a.cnt != b.cnt) return a.cnt < b.cnt;
	return a.time < b.time;
}

int main()
{
	vector<Participant> arr;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Participant p(i+1, x, y, z);
		
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end(), mySort);
	
	cout << arr[0].num << '\n';
	
	
	return 0;
}
