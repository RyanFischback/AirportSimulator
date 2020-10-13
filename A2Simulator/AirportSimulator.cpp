//
// Created by Ryan Fischback on 10/9/2019.
//

#include "AirportSimulator.h"

AirportSimulator::AirportSimulator(int numRunways, double mLand, double mTakeOff, int mClearTime)
        : numRunways_{numRunways}, mLand_{mLand}, mTakeOff_{mTakeOff}, mClearTime_{mClearTime}{}

void AirportSimulator::run_simulation()
{
    generate_planes();
    generate_runways();
    // have queues of planes, have runways. Processing time!
    while(!takeOffQ->isEmpty() || !landingQ->isEmpty())
    {
        for(int i = 0; i < numRunways_; i++)
        {
            runways[i]->processing(landingQ, takeOffQ);
        }
    }
    cout << "***----!Results of simulation!***----\n" << endl;
    for (int i = 0; i < numRunways_; i++)
    {
        cout << "Average time planes spend in landing queue in runway #:" <<  runways[i]->getNum() << " = " << runways[i]->mland() << " seconds " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Average time planes spend in take off queue in runway #:" <<  runways[i]->getNum() << " = " << runways[i]->mtakeoff() << " seconds " << endl;

        cout << "Average time planes spend in landing queue in runway #:" <<  runways[i]->getNum() << " = " << runways[i]->mland() << " seconds " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Average time planes spend in take off queue in runway #:" <<  runways[i]->getNum() << " = " << runways[i]->mtakeoff() << " seconds " << endl;
    }
    cout << "\n***----!Exiting The Simulation!***----" << endl;

}

void AirportSimulator::generate_runways()
{
    for (int i = 0; i < numRunways_; i++)
    {
        auto *runway = new Runway(i+1);
        runways[i] = runway;
    }
}

void AirportSimulator::generate_planes()
{
    for (int i = 1; i < 10; i++)
    {
        takeOffQ->enqueue(planeGenerator->generateLandedPlane(0));
        landingQ->enqueue(planeGenerator->generatePlaneInAir(0));
    }
}
