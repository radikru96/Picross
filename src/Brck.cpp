#include "Brck.h"

//static unsigned int count;
//unsigned int id,x,by,ey,size;

Brck::Brck(	Table *_table,
				unsigned const int &_size,	unsigned const int &_x,
				unsigned const int &_by,	unsigned const int &_ey )
{
	id = count++;
	table = _table;
	size = _size;
	x = _x;
	by = _by;
	ey = _ey;
	for( unsigned int y = by; y <= ey; y++ )
	{
		table->getPix( x, y )->set( this* );
	}
}
Brck::~Brck()
{
	for( unsigned int y = by; y <= ey; y++ )
	{
		table->getPix( x, y )->empty();
	}
	table = nullptr;
}

unsigned int& Brck::getSize() : const
{
	return size;
}

unsigned int& Brck::getId() : const
{
	return id;
}

void Brck::stepUp()
{
	table->getPix( x, ey+1 )->set(this);
	table->getPix( x, by )->empty();
	ey++; by++;
}

void Brck::stepDown()
{
	table->getPix( x, by-1 )->set(this);
	table->getPix( x, ey )->empty();
	ey--; by--;
}
