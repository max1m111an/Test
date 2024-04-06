#pragma once
#include <iostream>
using namespace std;

class Amount {
private:
	long rub;
	unsigned char kop;
public:
	Amount(long Arub, unsigned char Akop) 
		:rub(Arub), kop(Akop) {}
	Amount() {}
	~Amount() {}

	void setRub(long);
	void setKop(unsigned char);

	long getRub();
	unsigned char getKop();

	void instream();
};