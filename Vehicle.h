//
// Created by Balint Kiraly on 2023. 05. 27..
//

#ifndef TRAFFIC_SIMULATION_VEHICLE_H
#define TRAFFIC_SIMULATION_VEHICLE_H

#include <iostream>

#include "memtrace.h"


class Vehicle {
protected:
    int position;
    int speed;
    int maxSpeed;
public:
    Vehicle(int position, int speed, int maxSpeed) : position(position), speed(speed), maxSpeed(maxSpeed) {}

    /**
     * Gets the velocity of the vehicle
     * @return speed
     */
    int getspeed() const;

    /**
     * Gets the position of the vehicle
     * @return position
     */
    int getpos() const;

    /**
     * Sets the position of the vehicle to pos
     * @param pos
     */
    void setpos(int pos);

    /**
     * increases speed by one if it is below the maximum
     */
    void accelerate();

    /**
     * decreases speed if it is greater than the emptyCells
     * @param emptyCells
     */
    void decelerate(int emptyCells);

    /**
     * At a p probability decreases the speed by one
     * @param p
     */
    void randomDeceleration(double p);

    virtual void display(std::ostream& os) = 0;

    virtual ~Vehicle() {}
};


#endif //TRAFFIC_SIMULATION_VEHICLE_H
