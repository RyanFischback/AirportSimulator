//
// Created by Ryan Fischback on 9/30/2019.
//

#include "Runway.h"
#include "Queue.h"
#include "Plane.h"

Runway::Runway(int num, bool isBusy) : num_{num}, isBusy_{isBusy}{}

void Runway::setBusy(){isBusy_ = true;}

void Runway::processing(Queue *landingQ, Queue *takeOffQ)
{
//    if (landingQ->inspect() == nullptr)
//    {
//        free(landingQ);
//    }
//    if (takeOffQ->inspect() == nullptr)
//    {
//        free(takeOffQ);
//    }
    setBusy();
    while (isBusy_)
    {
        if(!takeOffQ->isEmpty() || !landingQ->isEmpty())
        {
            if (takeOffQ->inspect()->getTimeInQueue() <= landingQ->inspect()->getTimeInQueue()) {
                landingQ->inspect()->ticTimer();
                planeLanding(landingQ->inspect());
                landingQ->dequeue();
            } else {
                takeOffQ->inspect()->ticTimer();
                planeTakeOff(takeOffQ->inspect());
                takeOffQ->dequeue();
            }
        }
        isBusy_ = false;
    }
}

void Runway::planeTakeOff(Plane *p)
{
    cout<<"Plane " << p->getSerial() << " Took off!" << endl;
    p->setIsTakeOff(); p->setProcessingTime();
    takeoffQsResults(p->getTimerTime());
}

void Runway::planeLanding(Plane *p)
{
    cout<<"Plane " << p->getSerial() << " Landed!" << endl;
    p->setIsLanded(); p->setProcessingTime();
    landingQsResults(p->getTimerTime());
}

void Runway::takeoffQsResults(int queueTime){takeoffQTimeTotal += queueTime; numTakeOffPlanes++;}

void Runway::landingQsResults(int i){landingQTimeTotal += i; numLandingPlanes++;}

double Runway::mland(){return (double)landingQTimeTotal / numLandingPlanes;}

double Runway::mtakeoff() {return (double)takeoffQTimeTotal / numTakeOffPlanes;}

int Runway::getNum() {return  num_;}


