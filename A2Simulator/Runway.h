//
// Created by Ryan Fischback on 9/30/2019.
//a class Runway, which stores the info whether or not the runway is currently busy, and, if so, till when

#ifndef A2_RUNWAY_H
#define A2_RUNWAY_H


#include <array>

class Plane;
class Queue;
class Timer;

class Runway
{
    int num_=0;
    bool isBusy_;
    int numLandingPlanes=0;
    int numTakeOffPlanes=0;
    int landingQTimeTotal=0;
    int takeoffQTimeTotal=0;

public:
    Runway(int num, bool isBusy=false);
    void setBusy();
    void processing(Queue *landingQ, Queue *takeOffQ);
    void planeTakeOff(Plane *p);
    void planeLanding(Plane *p);
    void landingQsResults(int i);
    void takeoffQsResults(int queueTime);
    double mland();
    double mtakeoff();
    int getNum();
};


#endif //A2_RUNWAY_H
