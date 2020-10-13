//
// Created by Ryan Fischback on 9/30/2019.
// a class Plane that at least holds its “ready” time and plane's unique serial number; it may as well store its status
// (landing or taking off) and anything else one may need to know about a plane (but that can be added later, if needed);

#ifndef A2_PLANE_H
#define A2_PLANE_H
#include <iostream>
#include "Timer.h"
#include "Delay.h"
using namespace std;

class Plane
{

private:
    Timer timer_;

    Delay delay_;

    int timeSpentInQueue_;

    int serialNumber_;

    bool isLanded_ = false;

public:

    Plane(int serialNum, bool isLanded, int timeSpentInQueue);

    void setIsLanded();
    void setIsTakeOff();
    void setProcessingTime();

    int getTimeInQueue();
    int getSerial();

    void ticTimer();
    int getTimerTime();


    friend std::ostream& operator<<(std::ostream& os, const Plane& plane);
};

#endif //A2_PLANE_H
