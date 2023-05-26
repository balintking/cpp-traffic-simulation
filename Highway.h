//
// Created by Balint Kiraly on 2023. 05. 14..
//

#ifndef TRAFFIC_SIMULATION_HIGHWAY_H
#define TRAFFIC_SIMULATION_HIGHWAY_H

#include <iostream>
#include <cstdio>

#include "Highway.h"
#include "Car.h"

class Highway {
    size_t length;
    size_t carCount;
    Car* cars[];
public:
    Highway(size_t length);
    void addCar(Car* newCar);
    int followDistance(size_t index);
    void print(std::ostream& os);
    void cycle();
    ~Highway() {}
};


#endif //TRAFFIC_SIMULATION_HIGHWAY_H
