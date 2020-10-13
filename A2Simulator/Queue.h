//
// Created by Ryan Fischback on 9/16/2019.
//

#ifndef A1_QUEUE_H
#define A1_QUEUE_H

#include <iostream>
#include "Plane.h"

class Queue
{

public:

    Queue(int cnt = 0);

    bool enqueue(Plane *p);

    Plane *dequeue();

    Plane *inspect();

    bool isEmpty();

    bool isFull();


private:
    static const int MAXSIZE{200};
    Plane * q_[MAXSIZE];
    int tail_;
    int head_;
    int cnt_;
};
#endif //A1_QUEUE_H
