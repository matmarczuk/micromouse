#include "logic/Mouse/include/boardmap.h"
#include <iostream>

Boardmap::Boardmap():visit_counter(0)
{
    int size = 16;
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
Boardmap::~Boardmap()
{
    for(int i = 0; i < 16; ++i)
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
