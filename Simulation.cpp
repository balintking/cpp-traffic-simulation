//
// Created by Balint Kiraly on 2023. 05. 14..
//

#include <iostream>
#include <fstream>

#include "Simulation.h"
using std::cin, std::cout, std::endl;


void Simulation::addHighWay(const char *filename) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);

    try {
        file.open(filename, std::ifstream::in);

        int l, n;
        file >> l >> n;

        Highway* newHighWay = new Highway(l);

        //adding vehicles
        for (int i = 0; i < n; ++i) {
            char type;
            int pos, speed;
            file >> type >> pos >> speed;

            newHighWay->addVehicle(type, pos, speed);
        }

        highwayCount++;
        //adding it to array
        Highway** temp = new Highway*[highwayCount];
        for (size_t i = 0; i < highwayCount-1; ++i) {
            temp[i] = highways[i];
        }
        temp[highwayCount-1] = newHighWay;
        delete[] highways;

        highways = temp;
    }
    catch (const std::exception& e) {
        cout << "Error during opening config file: " << e.what() << endl;
    }

    file.close();
}

int Simulation::simulate() {
    for (size_t i = 0; i < highwayCount; ++i) {
        highways[i]->simulate();
    }
    return ++cycleCount;
}

void Simulation::printState(std::ostream& os) {
    for (size_t i = 0; i < highwayCount; ++i) {
        highways[i]->printState(os);
        os << std::endl;
    }
}
