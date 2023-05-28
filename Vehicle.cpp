//
// Created by Balint Kiraly on 2023. 05. 27..
//

#include "Vehicle.h"

int Vehicle::getspeed() const {
    return speed;
}

int Vehicle::getpos() const {
    return position;
}

void Vehicle::setpos(int pos) {
    position = pos;
}

void Vehicle::accelerate() {
    if (speed < maxSpeed) {
        speed++;
    }
}

void Vehicle::decelerate(int emptyCells) {
    if (speed > emptyCells) {
        speed = emptyCells;
    }
}

void Vehicle::randomDeceleration(double p) {
    srand(static_cast<unsigned>(time(nullptr)));
    double randomValue = static_cast<int>(rand()) % 100;

    if (100*p > randomValue) {
        if (speed > 0) speed--;
    }
}
