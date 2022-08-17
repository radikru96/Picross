#include "Brck.h"

//static unsigned int count;
//unsigned int id,x,by,ey,size;

Brck::Brck(		unsigned const int &_size,	unsigned const int &_x,
				unsigned const int &_by,	unsigned const int &_ey )
{
	id = count++;
	size = _size;
	x = _x;
	by = _by;
	ey = _ey;
}

unsigned int& Brck::getSize()
{
	return size;
}

unsigned int& Brck::getId()
{
	return id;
}


unsigned int &Brck::getX()
{
	return x;
}

unsigned int &Brck::getBy()
{
	return by;
}

unsigned int &Brck::getEy()
{
	return ey;
}
