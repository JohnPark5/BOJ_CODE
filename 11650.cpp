#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool compare_asc(pair<int, int>& a, pair<int, int>& b) {
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	multimap<int, int> dot;
	int n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		
		dot.insert({x, y});
	}
	
	vector<pair<int, int>> v(dot.begin(), dot.end());
	sort(v.begin(), v.end(), compare_asc);
	
	for(pair<int, int> it : v) {
		cout << it.first << " " << it.second << '\n';
	}
	
	
	return 0;
}
