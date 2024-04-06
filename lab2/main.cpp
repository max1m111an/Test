#include "Money.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Money mon1(1, 20);
	Money mon2(3, 44);
	Money mon3;
	Money mon4;

	mon1 + mon2;
	mon1.compareWith(mon2);
	mon3 + mon4;
	mon3.compareWith(mon4);
	return 0;
}