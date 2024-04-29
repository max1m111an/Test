#include "Transport.h"

Transport::Transport(unsigned int weight, string model){
    this->weight = weight;
    this->model = model;
}

Transport::Transport()
    : Transport(0, "No-name") {}

Transport::~Transport() {}

void Transport::move()
{
    cout << "Transport " << model << " is moving" << endl;
}

void Transport::info()
{
    cout << "Transport info: " << weight << " kilograms, " << model << endl;
}