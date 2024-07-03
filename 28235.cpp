#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	
	cin >> str;
	
	if(str == "SONGDO") {
		cout << "HIGHSCHOOL" << endl;
	}
	else if(str == "CODE") {
		cout << "MASTER" << endl;
	}
	else if(str == "2023") {
		cout << "0611" << endl;
	}
	else if(str == "ALGORITHM") {
		cout << "CONTEST" << endl;
	}
	else {
		cout << "error" << endl;
		exit(0);
	}
	
	return 0;
}
