#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "algorithm.h"

/*!
 * \brief The TimeTable class implements time table algorithm
 */
class TimeTable : public Algorithm
{
public :
    std::vector<Cell> calculate(Boardmap *map);
};
#endif // TIMETABLE_H
