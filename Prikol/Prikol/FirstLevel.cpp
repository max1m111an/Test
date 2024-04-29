#include "FirstLevel.h"

Wheel::Wheel(unsigned short num_wheels, unsigned int weight, string model)
	: num_wheels(num_wheels), Transport(weight, model) {}

Wheel::Wheel()
	: Wheel(0, 0, "No-name"){}

Wheel::~Wheel(){}

Track::Track(unsigned short num_tracks, unsigned int weight, string model)
	: num_tracks(num_tracks), Transport(weight, model) {}

Track::Track()
	: Track(0, 0, "No-name"){}

Track::~Track(){}

Rotor::Rotor(unsigned short num_rotors, unsigned int weight, string model)
	: num_rotors(num_rotors), Transport(weight, model) {}

Rotor::Rotor()
	: Rotor(0, 0, "No-name") {}

Rotor::~Rotor(){}