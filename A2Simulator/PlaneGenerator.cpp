//
// Created by Ryan Fischback on 9/30/2019.
//

#include "PlaneGenerator.h"
#include "Plane.h"

PlaneGenerator::PlaneGenerator()
{}

Plane * PlaneGenerator::generatePlaneInAir(int t)
{
    serial_++;
    cout<<"Created Plane " << serial_ << " into air queue\n";
    return new Plane{serial_, false, t+delay.getDelay()};
}

Plane *PlaneGenerator::generateLandedPlane(int t) {
    serial_++;
    cout<<"Created Plane " << serial_ << " into land queue\n";
    return new Plane{serial_, true, t+delay.getDelay()};
}



