#ifndef CELL_H
#define CELL_H

struct Cell
{
    int pos_x;
    int pos_y;
    bool isVisited;
    bool walls[4];
    static int size;
    Cell(){for(int i = 0;i<4;i++) walls[i] = true; isVisited=false; }
};

#define CELL_SIZE Cell::size

#endif // CELL_H
