#ifndef BOARDMAP_H
#define BOARDMAP_H
#include "logic/Board/include/cell.h"
#include "position.h"

/*!
 * \brief The Boardmap class is representation of board seen by mouse
 */
class Boardmap
{
    Cell** map;
    int visit_counter;
    int boardSize;
public:
    Boardmap();
    ~Boardmap();
    void init(int size);
    bool checkIsCellVisited(int x, int y);
    void addCell(int x, int y, bool walls[4]);
    int getVisitCounter();
    Cell** getMap();
    int getBoardSize();

};

#endif // BOARDMAP_H
