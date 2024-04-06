#include "Amount.h"
using namespace std;

void Amount::setRub(long a) {
	this->rub = a;
}
void Amount::setKop(unsigned char a) {
	if (a >= 100) {
		this->setRub(this->rub + a / 100);
	}
	this->kop = a % 100;
}

long Amount::getRub() { return this->rub; }
unsigned char Amount::getKop() { return this->kop; }

void Amount::instream() {
	unsigned short kopeck;
	cout << "������� ���������� ������: ";
	cin >> rub;
	cout << "������� ���������� ������: ";
	cin >> kopeck;
	cout << endl;
	this->rub = rub;
	this->kop = kopeck;
}