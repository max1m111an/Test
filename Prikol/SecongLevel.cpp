#include "SecondLevel.h"

WheeledVehicles::WheeledVehicles(unsigned short num_wheels, unsigned short passengCap, string model)
    : Wheel::Wheel(num_wheels, passengCap, model) {}

void WheeledVehicles::move()
{
    cout << "Wheeled Vehicle " << model << " is moving" << endl;
}

void WheeledVehicles::info()
{
    cout << "Wheeled Vehicle info: number of wheels " << num_wheels << ", passenger capacity " << passengCap << ", " << model << endl;
}

TrackedVehicles::TrackedVehicles(unsigned short num_wheels, unsigned short weight, string model)
    : Track::Track(num_wheels, weight, model) {}

void TrackedVehicles::move()
{
    cout << "Tracked Vehicle " << model << " is moving" << endl;
}

void TrackedVehicles::info()
{
    cout << "Tracked Vehicle info: number of wheels " << num_wheels << ", weight " << weight << ", " << model << endl;
}

WheeledTrackedVehicles::WheeledTrackedVehicles(unsigned short num_wheels, unsigned short weight, unsigned short passengCap, string model)
    : Wheel::Wheel(num_wheels, passengCap, model), Track::Track(num_wheels, weight, model) {}

void WheeledTrackedVehicles::move()
{
    cout << "Wheeled-Tracked Vehicle " << Transport::model << " is moving" << endl;
}

void WheeledTrackedVehicles::info()
{
    cout << "Wheeled-Tracked Vehicle info: number of wheels " << Wheel::num_wheels << ", weight " << weight << ", passenger capacity " << passengCap << ", " << Wheel::model << endl;
}