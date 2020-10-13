//
// Created by Ryan Fischback on 9/30/2019.
//a class PlaneGenerator that places randomly delayed planes in a queue
// (an instance of suitably adapted Queue from your Assignment#1).

#ifndef A2_PLANEGENERATOR_H
#define A2_PLANEGENERATOR_H
#include "Plane.h"
#include "Rand.h"

class PlaneGenerator
{
    int serial_ = 0;
    Delay delay;
public:
    PlaneGenerator();

    Plane * generatePlaneInAir(int t);
    Plane * generateLandedPlane(int t);

};


#endif //A2_PLANEGENERATOR_H
