#include "Table.h"

bool& Table::getPix( const unsigned int& _x, const unsigned int& _y )
{
    return arr[_x][_y];
}