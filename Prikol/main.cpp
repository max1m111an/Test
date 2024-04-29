#include "SecondLevel.h"

int main() {

    WheeledVehicles wheeledVehicles(4, 5, "Tesla Model S");
    TrackedVehicles trackedVehicles(2, 54400, "M1 Abrams");
    WheeledTrackedVehicles wheeledTrackedVehicles(4, 10000, 2, "Schneider-Laurent");

    wheeledVehicles.move();
    wheeledVehicles.info();
    cout << endl;

    trackedVehicles.move();
    trackedVehicles.info();
    cout << endl;

    wheeledTrackedVehicles.move();
    wheeledTrackedVehicles.info();
    cout << endl;

    return 0;
}