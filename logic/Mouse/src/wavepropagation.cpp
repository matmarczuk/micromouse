#include "logic/Mouse/include/wavepropagation.h"
#include <vector>
struct index
{
    index(int x_, int y_) {x=x_;y=y_;}
    int x;
    int y;
};

/*!
 * \brief Virtual function implementation. Based on recorded map it uses water flow rule
 * to find shortest way to maze center
 *
 * \param map - recorded by mouse
 * \return vector of final path cells
 */
std::vector<Cell> WavePropagation::calculate(Boardmap *map)
{
    Cell** solve_map = map->getMap();
    int board_size = map->getBoardSize();
    int tmp_board[board_size][board_size];
    for (int i = 0; i<board_size; i++)
    {
        for (int j = 0; j<board_size; j++)
        {
            tmp_board[i][j] = -1; //unseted value
        }
    }
    tmp_board[0][0] = 0; //first cell

    std::vector<index> indexes_to_check;
    indexes_to_check.push_back((index(0,0)));

    while(!indexes_to_check.empty()) {

        int i = indexes_to_check.back().x;
        int j = indexes_to_check.back().y;
        indexes_to_check.pop_back();

        if(!solve_map[i][j].walls[0] && i-1>=0)
        {
            if(tmp_board[i-1][j] == -1)
            {
                tmp_board[i-1][j] = tmp_board[i][j] + 1;
                indexes_to_check.push_back(index(i-1,j));
            }
        }
        if(!solve_map[i][j].walls[1] && j-1>=0)
        {
            if(tmp_board[i][j-1] == -1)
            {
                tmp_board[i][j-1] = tmp_board[i][j] + 1;
                indexes_to_check.push_back(index(i,j-1));
            }

        }
        if(!solve_map[i][j].walls[2] && i+1<board_size)
        {
            if(tmp_board[i+1][j] == -1)
            {
                tmp_board[i+1][j] = tmp_board[i][j] + 1;
                indexes_to_check.push_back(index(i+1,j));
            }
        }
        if(!solve_map[i][j].walls[3] && j+1<board_size)
        {
            if(tmp_board[i][j+1] == -1)
            {
                tmp_board[i][j+1] = tmp_board[i][j] + 1;
                indexes_to_check.push_back(index(i,j+1));
            }
        }
    }

    //pick middle of map
    int i = board_size/2, j=i;
    std::vector<Cell> path;
    path.push_back(solve_map[i][j]);

    while(i !=0 || j!=0)
    {
        if(tmp_board[i-1][j] == tmp_board[i][j]-1 && i-1>=0)
        {
            if(!solve_map[i][j].walls[0])
            {
                path.push_back(solve_map[i-1][j]);
                i=i-1;
                continue;
            }
        }
        if (tmp_board[i][j-1] == tmp_board[i][j]-1 && j-1>=0)
        {
            if(!solve_map[i][j].walls[1])
            {
                path.push_back(solve_map[i][j-1]);
                j=j-1;
                continue;
            }
        }
        if (tmp_board[i+1][j] == tmp_board[i][j]-1 && i+1<board_size)
        {
            if(!solve_map[i][j].walls[2])
            {
                path.push_back(solve_map[i+1][j]);
                i=i+1;
                continue;
            }
        }
        if ( tmp_board[i][j+1] == tmp_board[i][j]-1 && j+1<board_size)
        {
            if(!solve_map[i][j].walls[3])
            {
                path.push_back(solve_map[i][j+1]);
                j=j+1;
                continue;
            }
        }
    }
    return path;
}

