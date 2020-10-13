#include <iostream>
#include "Timer.h"
#include "PlaneGenerator.h"
#include "Queue.h"
#include "Runway.h"
#include "AirportSimulator.h"

int main()
{
    auto *simulator = new AirportSimulator(2, 25, 25, 15);
    simulator->run_simulation();
    return 0;
}