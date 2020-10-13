//
// Created by Ryan Fischback on 9/30/2019.
//

#include "Plane.h"

Plane::Plane(int serialNum, bool isLanded, int timeSpentInQueue) : serialNumber_{serialNum}, isLanded_{isLanded}, timeSpentInQueue_{timeSpentInQueue}
{
}

std::ostream &operator<<(std::ostream &os, const Plane &plane)
{
    os << "Plane " << plane.serialNumber_ << " was in queue for ";
    if(plane.isLanded_)
    {
        os << "landing " ;
    }
    else{
        os << "take off " ;
    }
    os << "for " << plane.timeSpentInQueue_ << " seconds";
    return os;
}

void Plane::setIsLanded()
{
    isLanded_ = true;
}

void Plane::setIsTakeOff()
{
    isLanded_ = false;
}


int Plane::getTimeInQueue()
{
    return timeSpentInQueue_;
}

void Plane::setProcessingTime() {
    timeSpentInQueue_ = timer_.time() + delay_.getDelay();
}

int Plane::getSerial() {
    return serialNumber_;
}

void Plane::ticTimer()
{
    timer_.tic();
}

int Plane::getTimerTime()
{
    return timer_.time();
}

