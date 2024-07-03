#include <iostream>
#include <random>
using namespace std;

//목표: 완전한 랜덤 
int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,99);
	int res = dis(gen) % 3;
	
	cout << "rd : " << rd() << '\n';
	
	switch(res) {
	case 0:
		cout << "Vaporeon";
	break;
	case 1:
		cout << "Jolteon";
	break;
	case 2:
		cout << "Flareon";
	break;
	}
	
	
	
	
	return 0;
}
