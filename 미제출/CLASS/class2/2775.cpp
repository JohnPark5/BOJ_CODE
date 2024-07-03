#include <iostream>
using namespace std;

int getPopulation(int floor, int room) {
	if(floor == 0)
		return room + 1;
	if(room == 0)
		return 1;
	return getPopulation(floor, room-1) + getPopulation(floor-1, room);
} 

int main()
{
	int T, *res;
	
	cin >> T;
	
	if(T<1)exit(0);
	
	res = new int[T];
	
	for(int t=0; t<T; t++) {
		int k, n;
		
		cin >> k >> n;
		
		res[t] = getPopulation(k, n-1);
	}
	
	for(int t=0; t<T; t++)
		cout << res[t] << '\n';
	
	
	delete[] res;
	return 0;
}

