#include "Transport.h"

Transport::Transport(unsigned short num_wheels, string model)
    : num_wheels(num_wheels), model(model) {}

Transport::~Transport() {}

void Transport::move()
{
    cout << "Transport " << model << " is moving" << endl;
}

void Transport::info()
{
    cout << "Transport info: number of wheels " << num_wheels << ", " << model << endl;
}


