//
// Created by Ryan Fischback on 10/9/2019.
//

#ifndef A2C___AIRPORTSIMULATOR_H
#define A2C___AIRPORTSIMULATOR_H
#include "Queue.h"
#include "Plane.h"
#include "PlaneGenerator.h"
#include "Runway.h"


class AirportSimulator{
private:
    int numRunways_; double mLand_; double mTakeOff_; int mClearTime_;
    Queue *takeOffQ = new Queue(); Queue *landingQ = new Queue();
    PlaneGenerator *planeGenerator = new PlaneGenerator(); double mLandResults; double mTakeOffResults;
    Runway *runways[2];
public:
    AirportSimulator(int numRunways, double mLand, double mTakeOff, int mClearTime);

    void run_simulation();
    void generate_runways();
    void generate_planes();

};


#endif //A2C___AIRPORTSIMULATOR_H
