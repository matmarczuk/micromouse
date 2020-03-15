#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

struct Cell
{
    int pos_x;
    int pos_y;
    bool isVisited;
    bool walls[4];
    Cell(){for(int i = 0;i<4;i++) walls[i] = true; isVisited=false;}
};

class BoardGenerator
{
public:
    BoardGenerator();
    Cell** generate(int size);
};

#endif // BOARDGENERATOR_H
