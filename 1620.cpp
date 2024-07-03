#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

bool isInteger(string s) {
	if(atoi(s.c_str())!=0 || s.compare("0")==0) return true;
	else return false;
}

void mk_reverse_map(const unordered_map<int, string>& m1, unordered_map<string, int>& m2) {
	for(const pair<int, string> it : m1) {
		m2.insert({it.second, it.first});
	}
}

int main()
{
	unordered_map<int, string> pokedex;
	unordered_map<string, int> reverse_pokedex;
	int n,m;
	
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	cin.tie(nullptr);
	
	for(int i=0; i<n; i++) {
		string input;
		cin >> input;
		pokedex.insert({i+1,input});
	}
	
	mk_reverse_map(pokedex, reverse_pokedex);
	
	for(int i=0; i<m; i++) {
		string input;
		cin >> input;
		if(isInteger(input)) {
			cout << pokedex.find(atoi(input.c_str()))->second << '\n';
		}
		else {
			cout << reverse_pokedex.find(input)->second << '\n';
		}
	}
	
	
	return 0;
}

