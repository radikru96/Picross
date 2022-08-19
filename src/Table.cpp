#include "Table.h"

Table::Table(const unsigned int& _x, const unsigned int& _y) : x(_x), y(_y)
{
	arr = new bool * [x];
	for(unsigned int i = 0; i < x; i++)
		arr[i] = new bool[y];
}

Table::~Table()
{
	for(unsigned int i = 0; i < x; i++)
		delete [] arr[i];
	delete [] arr;
}

void Table::init(const unsigned int& _x, const unsigned int& _y) : x(_x), y(_y)
{
	arr = new bool * [x];
	for(unsigned int i = 0; i < x; i++)
		arr[i] = new bool[y];
}

bool& Table::getPix( const unsigned int& _x, const unsigned int& _y )
{
    return arr[_x][_y];
}
