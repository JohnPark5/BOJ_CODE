#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	int n, max=0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int res;
		map<int, int> dice_cnt;
		
		for(int i=0; i<4; i++) {
			int diceInput;
			cin >> diceInput;
			map<int, int>::iterator it = dice_cnt.find(diceInput);
			if(it != dice_cnt.end()) {
				it->second++;
			}
			else {
				dice_cnt.insert({diceInput,1});
			}
			
		}
		vector<pair<int, int>> v(dice_cnt.begin(), dice_cnt.end());
		sort(v.begin(), v.end(), cmp);
		
		if(v[0].second == 4) {
			res = 50000 + v[0].first * 5000;
			if(res > max) max = res;
		}
		else if(v[0].second == 3) {
			res = 10000 + v[0].first * 1000;
			if(res > max) max = res;
		}
		else if(v[0].second == 2) {
			if(v[1].second == 2) {
				res = 2000 + v[0].first * 500 + v[1].first * 500;
				if(res > max) max = res;
			}
			else {
				res = 1000 + v[0].first * 100;
				if(res > max) max = res;
			}
		}
		else {
			//sort(v.begin(), v.end(), greater<pair<int, int>>());
			res = v[0].first * 100;
			if(res > max) max = res;
		}
		
	}
	cout << max << '\n';
	
	
	return 0;
}
