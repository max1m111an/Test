#include "SecondLevel.h"

int main() {

    RotaryWheeledVehicles wheeledVehicles("Electric car", 2, 4, 5, "Tesla Model S");
    RotaryTrackedVehicles trackedVehicles(1, 1, 2, 54400, "M1 Abrams");

    wheeledVehicles.move();
    wheeledVehicles.info();
    cout << endl;

    trackedVehicles.move();
    trackedVehicles.info();
    cout << endl;

    return 0;
}