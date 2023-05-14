cmake_minimum_required(VERSION 3.25)
project(traffic_simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(traffic_simulation main.cpp Simulation.cpp Simulation.h Highway.cpp Highway.h Car.cpp Car.h test.cpp)
