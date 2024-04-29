#include "FirstLevel.h"

Wheel::Wheel(unsigned short num_wheels, unsigned short passengCap, string model)
    :Transport::Transport(num_wheels, model), passengCap(passengCap) {}

Wheel::~Wheel() {}

Track::Track(unsigned short num_wheels, unsigned short weight, string model)
    :Transport::Transport(num_wheels, model), weight(weight) {}

Track::~Track() {}

