//
// Created by Balint Kiraly on 2023. 05. 14..
//

#ifndef TRAFFIC_SIMULATION_SIMULATION_H
#define TRAFFIC_SIMULATION_SIMULATION_H

#include <cstdio>

#include "Simulation.h"
#include "Highway.h"

class Simulation {
    size_t cycleCount;
    size_t highwayCount;
    Highway* highways[];
public:
    Simulation():cycleCount(0), highwayCount(0) {}
    void config(const char* filename);
    int cycle();
    ~Simulation();
};


#endif //TRAFFIC_SIMULATION_SIMULATION_H
