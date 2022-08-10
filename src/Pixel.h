#ifndef PIXEL_H
#define PIXEL_H
#include "Brick.h"

class Pixel{
	Brick* ptrBrick = nullptr;
	bool busy = false;
public:
	Pixel(const Brick* ptrBrck);
	~Pixel();
	bool& getBusy();
	Brick* getBrick();
	void set(const Brick* ptrBrck);
	Pixel &operator=(const Pixel& other);
};
#endif
