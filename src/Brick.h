
#ifndef BRICK_H
#define BRICK_H
#include "Pixel.h"
#include "Table.h"

class Brick{
	static unsigned int count;
	unsigned int id,bx,by,ex,ey,size;
public:
	Brick(unsigned const int& _bx,unsigned const int& _by,
	      unsigned const int& _ex,unsigned const int& _ey,
	      unsigned const int& _size )
	      : id(count++), size(_size),
	      bx(_bx), by(_by), ex(_ex), ey(_ey) {}
	~Brick();
	unsigned int& getSize();
	unsigned int& getId();
	void stepUp( Table& _table );
	void stepDown( Table& _table );
};
#ifndef BRICK_COUNT
#define BRICK_COUNT
static unsigned int count = 0;
#endif
#endif
