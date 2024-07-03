#include <iostream>
using namespace std;

int main()
{
	int T = -1;
	string* str = nullptr;
	
	cin >> T;
	if(T<1) {
		cout << "error : T < 1" << endl;
		exit(0);
	}
	str = new string[T];
	
	for(int i=0; i<T; i++) {
		string tmp;
		int R;
		cin >> R >> tmp;
		for(int j=0; j<tmp.length(); j++) {
			for(int k=0; k<R; k++)
				str[i].push_back(tmp[j]);
		}
	}
	
	for(int i=0; i<T; i++) {
		cout << str[i] << endl;
	}
	
	delete[] str;
	return 0;
}
