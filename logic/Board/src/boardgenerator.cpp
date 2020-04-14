#include "logic/Board/include/boardgenerator.h"
#include <vector>
#include <memory>
#include <stdlib.h>
#include <ctime>

BoardGenerator::BoardGenerator()
{

}
void BoardGenerator::generateNewBoard(int size)
{
    srand( time( NULL ) );
    std::vector<Cell> stack;
    Cell** cellBoard = new Cell*[size];
    for(int i = 0; i < size; ++i)
        cellBoard[i] = new Cell[size];

    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            cellBoard[i][j].pos_x = i;
            cellBoard[i][j].pos_y = j;
        }
    }

    // put square cell 2x2 inside the board
    cellBoard[size/2][size/2].isVisited=true;
    cellBoard[size/2][size/2].walls[0]=false;
    cellBoard[size/2][size/2].walls[1]=false;

    cellBoard[size/2-1][size/2].isVisited=true;
    cellBoard[size/2-1][size/2].walls[1]=false;
    cellBoard[size/2-1][size/2].walls[2]=false;

    cellBoard[size/2-1][size/2-1].isVisited=true;
    cellBoard[size/2-1][size/2-1].walls[2]=false;
    cellBoard[size/2-1][size/2-1].walls[3]=false;

    cellBoard[size/2][size/2-1].isVisited=true;
    cellBoard[size/2][size/2-1].walls[0]=false;
    cellBoard[size/2][size/2-1].walls[3]=false;

    int x_index = size/2;
    int y_index = size/2;

    //int check
    cellBoard[x_index][y_index].isVisited = true;
    stack.push_back(cellBoard[x_index][y_index]);

    while(1)
    {
        std::vector<int> rand_index;
        x_index = stack.back().pos_x;
        y_index = stack.back().pos_y;

        int tmp_index = x_index - 1;
        if (tmp_index > -1)
        {
            if(!cellBoard[x_index-1][y_index].isVisited)
                rand_index.push_back(0);
        }
        tmp_index=y_index - 1;
        if (tmp_index > -1)
        {
            if(!cellBoard[x_index][y_index-1].isVisited)
                rand_index.push_back(1);
        }
        tmp_index = x_index + 1;
        if (tmp_index < size)
        {
            if(!cellBoard[x_index+1][y_index].isVisited)
                rand_index.push_back(2);
        }
        tmp_index = y_index + 1;
        if(tmp_index < size)
        {
            if(!cellBoard[x_index][y_index+1].isVisited)
                rand_index.push_back(3);
        }

        if (rand_index.empty())
        {
            stack.pop_back();
            if(stack.empty())
                break;

            continue;
        }

        int rand_res = rand() % rand_index.size();

        switch(rand_index[rand_res])
        {
            case 0:
                cellBoard[x_index][y_index].walls[0]=false;
                x_index--;
                cellBoard[x_index][y_index].walls[2]=false;
                break;
            case 1:
                cellBoard[x_index][y_index].walls[1]=false;
                y_index--;
                cellBoard[x_index][y_index].walls[3]=false;
                break;
            case 2:
                cellBoard[x_index][y_index].walls[2]=false;
                x_index++;
                cellBoard[x_index][y_index].walls[0]=false;
                break;
            case 3:
                cellBoard[x_index][y_index].walls[3]=false;
                y_index++;
                cellBoard[x_index][y_index].walls[1]=false;
                break;
        }
        cellBoard[x_index][y_index].isVisited = true;
        stack.push_back(cellBoard[x_index][y_index]);
    }

    emit setNewBoard(cellBoard, size);
}
