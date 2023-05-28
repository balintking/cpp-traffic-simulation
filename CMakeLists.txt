cmake_minimum_required(VERSION 3.25)
project(traffic_simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-DMEMTRACE")

#add_executable(traffic_simulation test/test1.cpp)
add_executable(traffic_simulation traffic-simulation.cpp Simulation.cpp Simulation.h Highway.cpp Highway.h Car.cpp Car.h traffic-simulation.h Vehicle.cpp Vehicle.h)