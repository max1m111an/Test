#pragma once
#include "Transport.h"

class Wheel : public Transport {
public:
    
    Wheel(unsigned short, unsigned int, string);
    Wheel();
    ~Wheel();
protected:
    unsigned short num_wheels;
};

class Track : public Transport {
public:
   
    Track(unsigned short, unsigned int, string);
    Track();
    ~Track();
protected:
    unsigned short num_tracks;
};

class Rotor : public Transport {
public:
    Rotor(unsigned short, unsigned int, string);
    Rotor();
    ~Rotor();
protected:
    unsigned short num_rotors;
};