#ifndef BOARDMAP_H
#define BOARDMAP_H
#include "cell.h"
#include "position.h"

class Boardmap
{
    Cell** map;
    int visit_counter;
public:
    Boardmap();
    ~Boardmap();
    bool checkIsCellVisited(int x, int y);
    void addCell(int x, int y, bool walls[4]);

};

#endif // BOARDMAP_H
