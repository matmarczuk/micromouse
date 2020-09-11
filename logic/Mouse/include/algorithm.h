#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "boardmap.h"
#include <vector>

/*!
 * \brief The algorithm_enum enum stores possible solve algorithms
 */
enum algorithm_enum
{
    WAVE_PROPAGATION,
    TIME_TABLE
};

/*!
 * \brief The Algorithm class is interface for all algorithms
 */
class Algorithm
{
public:
    virtual std::vector<Cell> calculate(Boardmap *map) = 0;
    virtual ~Algorithm() {}

};
#endif // ALGORITHM_H
