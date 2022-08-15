#ifndef TABLE_H
#define TABLE_H
#include "Pixel.h"

class Table {
	Pixel** arr;
	const unsigned int x;
	const unsigned int y;
public:
	Table(const unsigned int& _x, const unsigned int& _y) : x(_x),y(_y);
	Pixel* getPix( const unsigned int& _x, const unsigned int& _y );  
};
#endif
