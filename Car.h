//
// Created by Balint Kiraly on 2023. 05. 14..
//

#ifndef TRAFFIC_SIMULATION_CAR_H
#define TRAFFIC_SIMULATION_CAR_H

#include "memtrace.h"
#include "Car.h"
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int position, int speed) : Vehicle(position, speed, 5) {}

    /**
     * displays the car as symbol
     * @param os
     */
    void display(std::ostream& os);
    ~Car() {}
};

#endif //TRAFFIC_SIMULATION_CAR_H
