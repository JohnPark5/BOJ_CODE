#include <iostream>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;

class myBigInt {
	friend std::istream& operator>>(std::istream&, myBigInt&);
	friend const std::ostream& operator<<(std::ostream&, myBigInt&);
private:
	char myInt[10001];
	char res[10001];
public:
	myBigInt();
	int length();
	const myBigInt& operator+(myBigInt&);
	const myBigInt& operator=(const myBigInt&);
	const myBigInt& operator=(const char*);
};

int main()
{
	myBigInt a, b, result;
	int len1, len2;
	
	cin >> a>> b;
	
	// cal a + b;
	
	result = a + b;
	
	cout << result;
	
	
	return 0;
}

myBigInt::myBigInt() {
	memset(myInt, 0, sizeof(myInt));
	memset(res, 0, sizeof(res));
}

const myBigInt& myBigInt::operator=(const myBigInt& otherMyInt) {
	strcpy(this->myInt, otherMyInt.res);
	strcpy(this->res, otherMyInt.res);
	return *this;
}

const myBigInt& myBigInt::operator=(const char* otherCharArr) {
	strcpy(this->myInt, otherCharArr);
	strcpy(this->res, otherCharArr);
	return *this;
}

const myBigInt& myBigInt::operator+(myBigInt& otherInt) {
	char result[10001];
	memset(result,0,sizeof(result));
	
	// do addition to this->tmp
	
	if(this->length() == otherInt.length()) {
		
	}
	else {
		
	}
	
	
	
	
	
	
	strcpy(this->res,result);
	return (*this);
}

int myBigInt::length() {
	if(this->res[0] == '-') {
		return strlen(res) - 1;
	}
	return strlen(myInt);
}
const std::ostream& operator<<(std::ostream& os, myBigInt& myInt) {
	os << myInt.res;
	return os;
}

std::istream& operator>>(std::istream& is, myBigInt& myInt) {
	string str;
	is >> str;
	strcpy(myInt.myInt,str.c_str());
	strcpy(myInt.res,str.c_str());
	return is;
}












