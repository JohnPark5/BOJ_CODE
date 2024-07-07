#include <iostream>
using namespace std;

int getRes(int a, int b);

int main()
{
	int T=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> T;
	
	if(T<1) {
		cout << "error : T<1" << endl;
	}
	
	for(int i=0; i<T; i++) {
		int a=-1, b=-1;
		cin >> a >> b;
		
		cout << getRes(a,b) << '\n';
	}
	
	
	
	return 0;
}

//1<=a<100, 1<=b<1,000,000
int getRes(int a, int b) {
	switch(a%10) {
	case 0: // -> 10
		return 10;
	break;
	case 1: // -> 1
		return 1;
	break;
	case 2: // (2^b)%10 => [2,4,8,6,2,...] (b=1,...)
		switch(b%4) {
		case 0:
			return 6;
		break;
		case 1:
			return 2;
		break;
		case 2:
			return 4;
		break;
		case 3:
			return 8;
		break;
		}		
	break;
	case 3: // (3^b)%10 => [3,9,7,1,3,...] (b=1,...)
		switch(b%4) {
		case 0:
			return 1;
		break;
		case 1:
			return 3;
		break;
		case 2:
			return 9;
		break;
		case 3:
			return 7;
		break;
		
		}
	break;
	case 4: // (4^b)%10 => [4,6,4...] (b=1,...)
		switch(b%2) {
		case 0:
			return 6;
		break;
		case 1:
			return 4;
		break;
		}
	break;
	case 5: // (5^b)%10 => [5,5,...] (b=1,...)
		return 5;
	break;
	case 6: // (6^b)%10 => [6,6,...] (b=1,...)
		return 6;
	break;
	case 7: // (7^b)%10 => [7,9,3,1,7,...] (b=1,...)
		switch(b%4) {
		case 0:
			return 1;
		break;
		case 1:
			return 7;
		break;
		case 2:
			return 9;
		break;
		case 3:
			return 3;
		break;
		}
	break;
	case 8: // (8^b)%10 => [8,4,2,6,8,...] (b=1,...)
		switch(b%4) {
		case 0:
			return 6;
		break;
		case 1:
			return 8;
		break;
		case 2:
			return 4;
		break;
		case 3:
			return 2;
		break;
		}
	break;
	case 9: // (9^b)%10 => [9,1,9...] (b=1,...)
		switch(b%2) {
		case 0:
			return 1;
		break;
		case 1:
			return 9;
		break;
		}
	break;
	}
}
