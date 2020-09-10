#ifndef WAVEPROPAGATION_H
#define WAVEPROPAGATION_H

#include "algorithm.h"

class WavePropagation : public Algorithm
{
public :
    std::vector<Cell> calculate(Boardmap *map);
};
#endif // WAVEPROPAGATION_H
