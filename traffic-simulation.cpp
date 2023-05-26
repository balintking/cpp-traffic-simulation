//
// Created by Balint Kiraly on 2023. 05. 14..
//


#include <iostream>

#include "traffic-simulation.h"

void config(Simulation& simulation) {
    char filename[5];

    std::cout << "Config file: ";
    std::cin >> filename;

    try {
        simulation.config(filename);
    }
    catch (...) {
        std::cout << "configuration unsuccessful";
    }

}

int main() {
    Simulation simulation;

    std::cout << "Add Highway [1]\t\tExit [2]" << std::endl;

    char option;

    while ((std::cin >> option) && option != EOF) {
        switch (option) {
            case ('1'): {
                config(simulation);
                break;
            }
            case ('2'): {
                exit(0);
            }
            case (' '): {
                simulation.cycle();
            }
        }
        std::cout << "Add Highway [1]\t\tNext Cycle [SPACE]\t\tExit [2]" << std::endl;
    }

    return 0;
}
