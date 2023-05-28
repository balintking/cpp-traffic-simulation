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
    Highway** highways;
public:
    /**
     * Simulation constructor
     */
    Simulation():cycleCount(0), highwayCount(0), highways(nullptr) {}

    /**
     * Adds new Highway to Simulation from config file
     * @param filename
     */
    void addHighWay(const char* filename);

    /**
     * Calls the simulate function of all the Highways it contains
     * @return
     */
    int simulate();

    /**
     * Calls every Highway's print function
     */
    void printState(std::ostream& os);

    /**
     * Simulation destructor
     */
    ~Simulation() {
        for (size_t i = 0; i < highwayCount; ++i) {
            delete highways[i];
        }
        delete[] highways;
    }
};


#endif //TRAFFIC_SIMULATION_SIMULATION_H
