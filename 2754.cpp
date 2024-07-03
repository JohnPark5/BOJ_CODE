#include <iostream>
using namespace std;

int main()
{
	string grade;
	double score = 0.0;
	
	cin >> grade;
	
	if(grade[0] != 'F') {
		score = 'D'-grade[0]+1;
		
		switch(grade[1]) {
		case '+':
			score += 0.3;
		break;
		case '-':
			score -= 0.3;
		break;
		default:
		break;
		}
	}
	else {
		score = 0;
	}
	
	printf("%.1lf\n",score);
	
	return 0;
}
