#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, *num, *forSum, nn;
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	num = new int[n];
	
	nn = n/10;
	
	//cout << "nn : " << nn << '\n';
	
	forSum = new int[nn];
	
	for(int i=0; i<n; i++) 
		cin >> num[i];
	
	for(int i=0; i<nn; i++) {
		//cout << "for[ " << i+1 << " / " << nn << " ]\n";
		forSum[i] = 0;
		for(int j=0; j<10; j++) {
			forSum[i] += num[i*10 + j];
			//cout << "adding num[" << i << "*10 + " << j << "](" << num[i*10 + j] << ")\n";
		}
		//cout << "forSum[" << i << "] : " << forSum[i] << '\n';
	}
	
	for(int i=0; i<m; i++) {
		int x, y, res = 0;
		cin >> x >> y;
		x--;
		y--;
		
		if(y-x > 20) {
			while(x%10 != 0) {
				res += num[x];
				x++;
			}
			while(y%10 != 9) {
				res += num[y];
				y--;
			}
			for(int k=x/10; k<(y+1)/10; k++) {
				res += forSum[k];
			}
		}
		else {
			for(int j=x; j<=y; j++) {
				res += num[j];
			}
		}
		cout << res << '\n';
	}
	
	
	delete[] num;
	delete[] forSum;
	return 0;
}
