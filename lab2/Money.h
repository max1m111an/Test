#pragma once
#include "Amount.h"
using namespace std;

class Money {
private:
	Amount amount;
public:
	Money(long Arub, unsigned char Akop) :
			amount(Arub, Akop){}

	Money() {
		amount.instream();
	}
	long getAmountRub();
	unsigned char getAmountKop();

	void setMoney(long, unsigned char);

	void operator + (Money);

	void compareWith(Money&);

	friend ostream& operator << (ostream&, Money);
};