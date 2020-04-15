#include "logic/Mouse/include/boardmap.h"
#include <iostream>

Boardmap::Boardmap():visit_counter(0),boardSize(0)
{

}
void Boardmap::init(int size)
{
    if(boardSize != 0)
    {
        for(int i = 0; i < boardSize; ++i)
            delete[] map[i];
        delete[] map;
    }

    boardSize = size;
    visit_counter = 0;

    if(size > 0)
    {
        map = new Cell*[size];
        for(int i = 0; i < size; ++i)
            map[i] = new Cell[size];

        for(int i = 0;i<size;i++)
        {
            for(int j = 0;j<size;j++)
            {
                map[i][j].pos_x = i;
                map[i][j].pos_y = j;
            }
        }
    }
}
Boardmap::~Boardmap()
{
    for(int i = 0; i < boardSize; ++i)
        delete[] map[i];
    delete[] map;
}

bool Boardmap::checkIsCellVisited(int x, int y)
{
    return map[x][y].isVisited;
}

void Boardmap::addCell(int x, int y, bool walls[4])
{
    for(int i = 0;i<4;i++)
        map[x][y].walls[i]=walls[i];
    map[x][y].isVisited = true;
    visit_counter++;
    std::cout<<visit_counter<<std::endl;
}

int Boardmap::getVisitCounter()
{
    return visit_counter;
}
