#pragma once
#include <string>
#include <iostream>

using namespace std;

class Transport {
public:
    Transport(unsigned int, string);
    Transport();
    ~Transport();

    void move();
    virtual void info();

protected:
    unsigned int weight;
    string model;
};