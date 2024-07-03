#include <iostream>
using namespace std;

int main()
{
	int n, *score, max, sum = 0;
	double res;
	
	cin >> n;
	if(n<1) {
		cout << "error : n<1" << endl;
		exit(0);
	}
	score = new int[n];
	
	for(int i=0; i<n; i++) {
		cin >> score[i];
		sum += score[i];
		if(i==0) max = score[i];
		else if(score[i]>max) max = score[i];
	}
	
	res = double(100) / n / max * (sum);
	
	cout << res << '\n';
	
	
	delete[] score;
	return 0;
}
