//
// Created by Balint Kiraly on 2023. 05. 14..
//


#include <iostream>

#include "Simulation.h"
#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
using std::cin;
using std::cout;
using std::endl;

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
#ifdef CPORTA_INPUT
    std::ifstream testin("test_input.txt");
    cin.rdbuf(testin.rdbuf());
#endif

    cout << "Highway traffic simulation" << endl;
    cout << "Add Highway [2]\t\tExit [3]" << endl;

    char option;
    int cycle = 0;

    while ((cin >> option) && option != EOF) {
        try {
            switch (option) {
                case ('1'): {               //simulate
                    cycle = simulation.simulate();
                    break;
                }
                case ('2'): {               //new highway
                    config(simulation);
                    break;
                }
                case ('3'): {               //exit
                    simulation.~Simulation();
                    exit(0);
                }
                default: break;
            }
        } catch (std::exception& exc) {
            cout << "Error: " << exc.what() << std::endl;
        } catch(...) {
            cout << "Something went wrong." << endl;
            exit(1);
        }

        cout << endl;
        cout << "Cycle " << cycle << endl;
        cout << endl;
        simulation.printState(cout);
        cout << endl;

        cout << "Next Cycle [1]\t\tAdd Highway [2]\t\tExit [3]" << endl;
    }

    return 0;
}