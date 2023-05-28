//
// Created by Balint Kiraly on 2023. 05. 14..
//

#ifndef TRAFFIC_SIMULATION_HIGHWAY_H
#define TRAFFIC_SIMULATION_HIGHWAY_H

#include <iostream>
#include <cstdio>

#include "memtrace.h"
#include "Highway.h"
#include "Car.h"

class Highway {
    size_t length;
    size_t vehicleCount;
    Vehicle** vehicles;
public:
    /**
     * Highway constructor
     * @param length
     */
    explicit Highway(size_t length) : length(length), vehicleCount(0) {
        vehicles = new Vehicle*[length];
        for (size_t i = 0; i < length; i++) {
            vehicles[i] = nullptr;
        }
    }

    /**
    * Adds new vehicle to the array using dynamic memory allocation
    * @param type
    * @param position
    * @param speed
    */
    void addVehicle(char type, int position, int speed);

    /**
     * Moves vehicle numOfCells cells forward
     * @param vehicle
     * @param numOfCells
     */
    void moveVehicle(Vehicle* vehicle, int numOfCells);

    /**
     * Transforms the state of the Highway into the next cycle
     */
    void simulate();

    /**
     * Prints the current state
     * @param os
     */
    void printState(std::ostream& os);

    /**
     * Highway destructor
     */
    ~Highway() {
        for (size_t i = 0; i < length; ++i) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }
};


#endif //TRAFFIC_SIMULATION_HIGHWAY_H
