#include "logic/Mouse/include/timetable.h"
#include <vector>

std::vector<Cell> TimeTable::calculate(Boardmap *map)
{
    struct index
    {
        index(int x_, int y_, int orient_) {x=x_;y=y_;orientation=orient_;}
        int x;
        int y;
        int orientation;
    };

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
    indexes_to_check.push_back((index(0,0,1)));

    while(!indexes_to_check.empty()) {

        int i = indexes_to_check.back().x;
        int j = indexes_to_check.back().y;
        int current_orientation = indexes_to_check.back().orientation;
        indexes_to_check.pop_back();

        if(!solve_map[i][j].walls[0] && i-1>=0) // 0 direction
        {
            if(tmp_board[i-1][j] == -1)
            {
                tmp_board[i-1][j] = tmp_board[i][j] + calculateCost(current_orientation, 0);
                indexes_to_check.push_back(index(i-1,j,0));
            }
        }
        if(!solve_map[i][j].walls[1] && j-1>=0) // 1 direction
        {
            if(tmp_board[i][j-1] == -1)
            {
                tmp_board[i][j-1] = tmp_board[i][j] + calculateCost(current_orientation, 1);
                indexes_to_check.push_back(index(i,j-1,1));
            }
        }
        if(!solve_map[i][j].walls[2] && i+1<board_size) // 2 direction
        {
            if(tmp_board[i+1][j] == -1)
            {
                tmp_board[i+1][j] = tmp_board[i][j] + calculateCost(current_orientation, 2);
                indexes_to_check.push_back(index(i+1,j,2));
            }
        }
        if(!solve_map[i][j].walls[3] && j+1<board_size) //3 direction
        {
            if(tmp_board[i][j+1] == -1)
            {
                tmp_board[i][j+1] = tmp_board[i][j] + calculateCost(current_orientation, 3);
                indexes_to_check.push_back(index(i,j+1,3));
            }
        }
    }

    //pick middle of map
    int i = board_size/2, j=i;
    std::vector<Cell> path;
    path.push_back(solve_map[i][j]);

    struct cell_cost
    {
        int x;
        int y;
        int cost;
        cell_cost(int x_, int y_, int cost_){x=x_;y=y_;cost=cost_;}
    };

    while(i !=0 || j!=0)
    {

        std::vector<cell_cost> cost_vec;
        if(i-1>=0)
        {
            if(!solve_map[i][j].walls[0])
            {
                int cost = tmp_board[i][j] - tmp_board[i-1][j];
                cost_vec.push_back(cell_cost(i-1,j,cost));
            }
        }
        if (j-1>=0)
        {
            if(!solve_map[i][j].walls[1])
            {
                int cost = tmp_board[i][j] - tmp_board[i][j-1];
                cost_vec.push_back(cell_cost(i,j-1,cost));
            }
        }
        if (i+1<board_size)
        {
            if(!solve_map[i][j].walls[2])
            {
                int cost = tmp_board[i][j] - tmp_board[i+1][j];
                cost_vec.push_back(cell_cost(i+1,j,cost));
            }
        }
        if (j+1<board_size)
        {
            if(!solve_map[i][j].walls[3])
            {
                int cost = tmp_board[i][j] - tmp_board[i][j+1];
                cost_vec.push_back(cell_cost(i,j+1,cost));
            }
        }

        // find best direction
        cell_cost min_cost = cost_vec[0];
        for (std::vector<cell_cost>::iterator it = cost_vec.begin() ; it != cost_vec.end(); ++it)
        {
           if(min_cost.cost>(*it).cost)
                min_cost = *it;
        }
        i=min_cost.x;
        j=min_cost.y;
        path.push_back(solve_map[i][j]);
    }
    return path;
}

int TimeTable::calculateCost(int current_orient, int direction)
{
    if(current_orient-direction == 0)
        return 1; // same direction
    else
        return 2; // turn needed
}
