#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "boardmap.h"

class Algorithm
{
public:
    virtual void calculate(Boardmap *map) = 0;

};
#endif // ALGORITHM_H
