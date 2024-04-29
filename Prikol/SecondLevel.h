#pragma once
#include "FirstLevel.h"

class WheeledVehicles : public Wheel {
public:
    WheeledVehicles(unsigned short num_wheels, unsigned short passengCap, string model);

    void move() override;
    void info() override;
};

class TrackedVehicles : public Track {
public:
    TrackedVehicles(unsigned short num_wheels, unsigned short weight, string model);

    void move() override;
    void info() override;
};

class WheeledTrackedVehicles : public Wheel, public Track {
public:
    WheeledTrackedVehicles(unsigned short num_wheels, unsigned short weight, unsigned short passengCap, string model);

    void move() override;
    void info() override;
};