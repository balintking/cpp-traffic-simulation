//
// Created by Balint Kiraly on 2023. 05. 14..
//


#include <iostream>

#include "traffic-simulation.h"
using std::cin, std::cout, std::endl;

/**
 * Gets config file name and calls Simulation's addHighWay function
 * @param simulation
 */
void config(Simulation& simulation) {
    char filename[40];

    cout << "Config file: ";
    cin >> filename;

    try {
        simulation.addHighWay(filename);
    }
    catch (...) {
        cout << "configuration unsuccessful";
    }

}

int main() {
    Simulation simulation;

// If defined, input will be taken from file.
#ifdef CPORTA
    std::ifstream testin("test_input.txt");
    cin.rdbuf(testin.rdbuf());
#endif

    cout << "Add Highway [1]\t\tExit [2]" << endl;

    char option;

    while ((cin >> option) && option != EOF) {
        try {
            switch (option) {
                case ('1'): {               //new highway
                    config(simulation);
                    break;
                }
                case ('2'): {               //exit
                    exit(0);
                }
                case (' '): {               //simulate
                    simulation.simulate();
                    break;
                }
                default: break;
            }
        } catch (std::exception& exc) {
            cout << "Error: " << exc.what() << std::endl;
        } catch(...) {
            cout << "Something went wrong." << endl;
            exit(1);
        }

        simulation.printState(cout);
        cout << endl;

        cout << "Add Highway [1]\t\tNext Cycle [SPACE]\t\tExit [2]" << endl;
    }

    return 0;
}