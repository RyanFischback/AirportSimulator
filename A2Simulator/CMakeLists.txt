cmake_minimum_required(VERSION 3.14)
project(A2Simulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(A2Simulator main.cpp AirportSimulator.cpp AirportSimulator.h Delay.cpp Delay.h Plane.cpp Plane.h PlaneGenerator.cpp PlaneGenerator.h Queue.cpp Queue.h Rand.cpp Rand.h Runway.cpp Runway.h Timer.cpp Timer.h)