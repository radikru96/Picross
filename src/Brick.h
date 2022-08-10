
#ifndef BRICK_H
#define BRICK_H
//#include "Pixel.h"

class Brick{
	static unsigned int count;
	int id;
	int bx,by,ex,ey;
public:
	Brick( const int& b_x, const int& b_x,
	       const int& e_x, const int& e_y ) :;
	~Brick();
	bool& getBusy();
	Brick* getBrick();
	void set(const Brick* ptrBrck);
	Pixel &operator=(const Pixel& other);
};
#ifndef BRICK_COUNT
#define BRICK_COUNT
static unsigned int count = 0;
#endif
#endif
