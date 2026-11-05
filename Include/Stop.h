// Defines one stop node in the bus route.
#ifndef STOP_H
#define STOP_H

#include <string>

struct Stop
{
    int stopID;
    std::string name;
    Stop* left;
    Stop* right;

    Stop(int id, std::string n) : stopID(id), name(n), left(nullptr), right(nullptr) {}
};

#endif
