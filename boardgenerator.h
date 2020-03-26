#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H
#include "cell.h"

class BoardGenerator
{
public:
    BoardGenerator();
    Cell** generate(int size);
};

#endif // BOARDGENERATOR_H
