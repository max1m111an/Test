#pragma once
#include "Transport.h"

class Wheel : public Transport {
public:
    unsigned short passengCap;
    Wheel(unsigned short num_wheels, unsigned short passengCap, string model);
    ~Wheel();
};

class Track : public Transport {
public:
    unsigned short weight;
    Track(unsigned short num_wheels, unsigned short weight, string model);
    ~Track();
};