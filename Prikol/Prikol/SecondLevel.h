#pragma once
#include "FirstLevel.h"

class RotaryWheeledVehicles : public Wheel, public Rotor {
public:
    RotaryWheeledVehicles(string, unsigned short, unsigned short, unsigned short, string);
    RotaryWheeledVehicles();
    ~RotaryWheeledVehicles();
    void info() override;
    void move();
protected:
    string type;
};

class RotaryTrackedVehicles : public Track, public Rotor {
public:
    RotaryTrackedVehicles(bool, unsigned short, unsigned short, unsigned short, string);
    RotaryTrackedVehicles();
    ~RotaryTrackedVehicles();
    void info() override;
    void move();
protected:
    bool violent;
};