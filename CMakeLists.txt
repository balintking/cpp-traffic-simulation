cmake_minimum_required(VERSION 3.25)
project(traffic_simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-DMEMTRACE -DCPORTA")

add_compile_options(-Wall -Werror)
add_executable(traffic_simulation traffic-simulation.cpp Simulation.cpp Simulation.h Highway.cpp Highway.h Car.cpp Car.h Vehicle.cpp Vehicle.h memtrace.cpp)