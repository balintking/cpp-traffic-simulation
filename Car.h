//
// Created by Balint Kiraly on 2023. 05. 14..
//

#ifndef TRAFFIC_SIMULATION_CAR_H
#define TRAFFIC_SIMULATION_CAR_H

#include "Car.h"

class Car {
    int speed;
    int position;
public:
    Car(int speed, int position) :speed(speed), position(position) {}
    int getPos() const;
    void cycle();
    ~Car() {}
};


#endif //TRAFFIC_SIMULATION_CAR_H
