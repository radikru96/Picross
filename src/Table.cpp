#include "Table.h"

Table::Table(const unsigned int& _x, const unsigned int& _y)
{
    x = _x;
    y = _y;
    arr = new Pixel[x][y];
}

Pixel* Table::getPix( const unsigned int& _x, const unsigned int& _y )
{
    return arr[_x][_y];
}