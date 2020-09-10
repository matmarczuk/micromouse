#include "logic/Mouse/include/boardmap.h"
#include <iostream>

Boardmap::Boardmap():visit_counter(0),boardSize(0)
{

}

/*!
 * \brief Initiates new board to store mouse exploration
 * \param size - size of generated
 */
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

/*!
 * \brief Check if given cell was already visited
 * \param x - x position of cell
 * \param y - y position of ccell
 * \return boolean
 */
bool Boardmap::checkIsCellVisited(int x, int y)
{
    return map[x][y].isVisited;
}

/*!
 * \brief Add new cell to boardmap
 * \param x - coordinate
 * \param y - coordinate
 * \param walls - walls position (left, top, right, bottom)
 */
void Boardmap::addCell(int x, int y, bool walls[4])
{
    for(int i = 0;i<4;i++)
        map[x][y].walls[i]=walls[i];
    map[x][y].isVisited = true;
    visit_counter++;
}

/*!
 * \brief Check number of already visited cells.
 * Based on that mouse can determine wheather it has already scanned all board
 * \return Number of visited cells
 */
int Boardmap::getVisitCounter()
{
    return visit_counter;
}

/*!
 * \brief Get recorded map
 * \return map
 */
Cell** Boardmap::getMap()
{
    return map;
}

/*!
 * \brief Returns board size
 * \return
 */
int Boardmap::getBoardSize()
{
    return boardSize;
}
