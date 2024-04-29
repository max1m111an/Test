#pragma once
#include <string>
#include <iostream>

using namespace std;

class Transport {
public:
    Transport(unsigned short num_wheels, string model);
    ~Transport();

    virtual void move();
    virtual void info();

    int num_wheels;
    string model;
};