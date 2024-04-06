#pragma once
#include "Money.h"

void Money::setMoney(long a, unsigned char b) {
	this->amount.setRub(a);
	this->amount.setKop(b);
}
long Money::getAmountRub() { return this->amount.getRub(); }
unsigned char Money::getAmountKop() { return this->amount.getKop(); }

void Money::compareWith(Money& a) {
	if (this->getAmountRub() == a.getAmountRub() && this->getAmountRub() == a.getAmountRub()) {
		cout << "�������� ����� �����";
	}else{
		if (this->getAmountRub() > a.getAmountRub()) {
			cout << "����� " << *this << " ������ ����� " << a << endl;
		}else{
			if (this->getAmountRub() < a.getAmountRub()) {
				cout << "����� " << *this << " ������ ����� " << a << endl;
			}else{
				if (this->getAmountRub() == a.getAmountRub() && this->getAmountKop() > a.getAmountKop()) {
					cout << "����� " << *this << " ������ ����� " << a << endl;
				}else{
					cout << "����� " << *this << " ������ ����� " << a << endl;
				}
			}
		}
	}
}

void Money::operator + (Money a) {
	Money temp(0, 0);
	temp.setMoney(this->getAmountRub() + a.getAmountRub(), this->getAmountKop() + a.getAmountKop());
	cout << *this << " + " << a << " = " << temp << endl;
}

ostream& operator << (ostream& os, Money m){
	return os << m.getAmountRub() << "," << (int)m.getAmountKop() / 10 << (int)m.getAmountKop() % 10;
}