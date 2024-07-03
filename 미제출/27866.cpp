#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int target=-1;
	
	cin >> str >> target;
	
	cout << str[target-1] << '\n';
	
	return 0;
}
