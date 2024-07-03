#include <iostream>
#include <functional>
#include <memory.h>
using namespace std;
// using bloom filter with 8 hash functions
// 3,000,000 bit array
// maximum 100,000 items
// false positive prob : 1 in 110,971

/* solved by unordered_set, not by bloom filter.
class myBloomFilter
{
private:
	bool* bitArr;
	int bitArrSize;
	int hashFuncCnt;
	int myHash(long long int x, int hashFuncNum);
public:
	int isInArray(long long int x);
	void push(long long int x);
	myBloomFilter(int bitArrSize, int hashFuncCnt);
	~myBloomFilter();
};

inline void myError(string s) {
	cout << "error : " << s << endl;
	exit(0);
}

int main()
{
	myBloomFilter bf(3000000,8);
	int n = -1, m = -1;
	bool *resArr = nullptr;
	
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	if(n<1) 
		myError("n<1");
	
	for(int i=0; i<n; i++) {
		long long int x;
		cin >> x;
		bf.push(x);
	}
	
	cin >> m;
	if(m<1)
		myError("m<1");
	resArr = new bool[m];
	memset(resArr,false,sizeof(resArr));
	
	for(int i=0; i<m; i++) {
		long long int x;
		cin >> x;
		if(bf.isInArray(x))
			resArr[i] = true;
	}
	
	for(int i=0; i<m; i++)
		cout << int(resArr[i]) << '\n';
	
	
	
	
	return 0;
}

myBloomFilter::myBloomFilter(int bitArrSize, int hashFuncCnt) {
	if(hashFuncCnt<2)
		myError("hashFuncCnt<2");
	bitArr = new bool[bitArrSize];
	this->bitArrSize = bitArrSize;
	this->hashFuncCnt = hashFuncCnt;
}


myBloomFilter::~myBloomFilter() {
	delete[] bitArr;
}


int myBloomFilter::isInArray(long long int x) {
	for(int i=0; i<hashFuncCnt; i++) {
		if(bitArr[myHash(x,i)] == false)
			return false;
	}
	return true;
}


void myBloomFilter::push(long long int x) {
	for(int i=0; i<hashFuncCnt; i++) {
		bitArr[myHash(x,i)] = true;
	}
}


int myBloomFilter::myHash(long long int x, int hashFuncNum) {
	// myBloomFilter::int bitArrSize;
	// myBloomFilter::int hashFuncCnt;
	int result;
	hash<long long int> lliHash;
	result = lliHash(x);
	
	/*if(hashFuncCnt == 2) {
		if(hashFuncNum == 0) {
			long long int y = 11453246122;
			result = x&y*(hashFuncCnt+1);
		}
		else {
			long long int y = 11453246122 >> 1;
			result = x&y*(hashFuncCnt+1);
		}
	}
	else {
		result = 0;
	}*/
	
	for(int i=0; i<hashFuncNum+1; i++)result = lliHash(result);
	
	while(result<0)result = lliHash(result);
	
	return result%bitArrSize;
}




















