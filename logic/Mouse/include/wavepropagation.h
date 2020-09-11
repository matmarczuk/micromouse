#ifndef WAVEPROPAGATION_H
#define WAVEPROPAGATION_H

#include "algorithm.h"

/*!
 * \brief The WavePropagation class implements wave propagation solve algorithm
 */
class WavePropagation : public Algorithm
{
public :
    std::vector<Cell> calculate(Boardmap *map);
};
#endif // WAVEPROPAGATION_H
