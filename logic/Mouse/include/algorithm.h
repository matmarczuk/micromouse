#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "boardmap.h"
#include <vector>
enum algorithm_enum
{
    WAVE_PROPAGATION,
    TIME_TABLE,
    OTHER
};

class Algorithm
{
public:
    virtual std::vector<Cell> calculate(Boardmap *map) = 0;
    virtual ~Algorithm() {}

};
#endif // ALGORITHM_H
