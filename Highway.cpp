//
// Created by Balint Kiraly on 2023. 05. 14..
//

#include "Highway.h"


void Highway::addVehicle(char type, int position, int speed) {
    Vehicle* newvehic;
    switch (type) {
        case 'c':
            newvehic = new Car(position, speed);
        break;

        default: throw std::invalid_argument("Unknown vehicle type");
    }

    vehicleCount++;

    vehicles[position] = newvehic;
    /*
    if (vehicles == nullptr) {
        vehicles = new Vehicle*;
        vehicles[0] = newvehic;
    }
    else {
        Vehicle** temp = vehicles;
        delete[] vehicles;
        vehicles = new Vehicle*[vehicleCount];
        for (size_t i = 0; i < vehicleCount-1; ++i) {
            vehicles[i] = temp[i];
        }
        vehicles[vehicleCount-1] = newvehic;
    }*/
}

void Highway::moveVehicle(Vehicle *vehicle, int numOfCells) {
    int currentPosition = vehicle->getpos();
    int newPosition = currentPosition + numOfCells;

    vehicles[currentPosition] = nullptr;
    if (newPosition >= length) {
        delete vehicle;
    }
    else {
        vehicles[newPosition] = vehicle;
        vehicle->setpos(newPosition);
    }
}

void Highway::simulate() {
    int emptyCells = 5;
    for (int i = length-1; i >= 0; --i) {
        Vehicle* currentVehicle = vehicles[i];

        if (currentVehicle == nullptr) {
            emptyCells++;
        }
        else {
            currentVehicle->accelerate();
            currentVehicle->decelerate(emptyCells);
            currentVehicle->randomDeceleration(0.15);

            moveVehicle(currentVehicle, currentVehicle->getspeed());

            emptyCells = 0;
        }
    }
}

void Highway::printState(std::ostream &os) {
    for (size_t i = 0; i < length; ++i) {
        if (vehicles[i] != nullptr) {
            vehicles[i]->display(os);
        }
        else {
            os << "-";
        }
    }
}
