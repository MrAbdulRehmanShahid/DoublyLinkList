// Declares the doubly linked bus route list.
#ifndef BUS_ROUTE_H
#define BUS_ROUTE_H

#include "Stop.h"

class BusRoute
{
private:
    Stop* head;
    Stop* tail;
    Stop* current;
    int count;

    void Unlink(Stop* n);
    void LinkAfter(Stop* pos, Stop* n);

public:
    BusRoute();
    ~BusRoute();

    void AddAtEnd(Stop* n);
    void InsertAfterCurrent(Stop* n);
    Stop* RemoveCurrent();
    void Next();
    void Previous();
    void MoveCurrentRight();
    void MoveCurrentLeft();
    void PrintCurrent() const;
    void PrintOutbound() const;
    void PrintInbound() const;
};

#endif
