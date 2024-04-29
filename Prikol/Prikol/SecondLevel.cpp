#include "SecondLevel.h"

RotaryWheeledVehicles::RotaryWheeledVehicles(string type, unsigned short num_rotors, unsigned short num_wheels, unsigned short weight, string model)
: type(type), Rotor(num_rotors, weight, model), Wheel(num_wheels, weight, model){}

RotaryWheeledVehicles::RotaryWheeledVehicles()
:RotaryWheeledVehicles("No-name", 0, 0, 0, "No-name") {}

RotaryWheeledVehicles::~RotaryWheeledVehicles(){}

void RotaryWheeledVehicles::info()
{
	cout << "Rotary-Wheeled Transport info: " << type << ", " << Transport::weight << " kilograms, number of the rotors " << num_rotors << ", number of the wheels " << num_wheels << ", " << Transport::model << endl;
}

void RotaryWheeledVehicles::move()
{
	this->Transport::move();
}

RotaryTrackedVehicles::RotaryTrackedVehicles(bool violent, unsigned short num_rotors, unsigned short num_tracks, unsigned short weight, string model)
: violent(violent), Rotor(num_rotors, weight, model), Track(num_tracks, weight, model){}

RotaryTrackedVehicles::RotaryTrackedVehicles()
: RotaryTrackedVehicles(0, 0, 0, 0, "No-name") {}

RotaryTrackedVehicles::~RotaryTrackedVehicles(){}

void RotaryTrackedVehicles::info()
{
	cout << "Rotary-Tracked Transport info: ";
	if (!violent) {
		cout << "non-";
	}
	cout << "violent, " << Transport::weight << " kilograms, number of the rotors " << num_rotors << ", number of the tracks " << num_tracks << ", " << Transport::model << endl;
}

void RotaryTrackedVehicles::move()
{
	this->Transport::move();
}