//
// Created by Ryan Fischback on 9/16/2019.
//
#include "Queue.h"

Queue::Queue(int cnt) : tail_{cnt}, head_{0}, cnt_{cnt}
{
}


bool Queue::enqueue(Plane *p)
{
    if (!isFull())
    {
        q_[tail_] = p;
        tail_ = (tail_ + 1) % MAXSIZE;
        cnt_++;
        return true;
    }
    else
    {
        std::cout<< "Queues full" << std::endl;
        return false;
    }
}

Plane *Queue::dequeue()
{
    if(!isEmpty())
    {
        int temp = head_;
        head_ = (head_ + 1) % MAXSIZE;
        cnt_--;
        return q_[temp];
    }
    else
    {
        std::cout << "Empty queue" << std::endl;
        return nullptr;
    }
}

Plane * Queue::inspect()
{
    if(isEmpty())
    {
        return nullptr;
    }
    return q_[head_];
}

bool Queue::isEmpty()
{
    return cnt_ == 0;
}

bool Queue::isFull()
{
    return cnt_ == MAXSIZE;
}

