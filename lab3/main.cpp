#include <iostream>
#include <string>
using namespace std;

class Ground_Transport {
public:
	string type;
	void Movement() {}

};

class Wheel: public Ground_Transport {

};

class Track : public Ground_Transport {

};

int main() {
	setlocale(LC_ALL, "rus");
	
	return 0;
}