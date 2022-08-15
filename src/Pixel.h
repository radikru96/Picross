#ifndef PIXEL_H
#define PIXEL_H
#include "Brck.h"

class Pixel{
	Brck* ptrBrck = nullptr;
	bool busy = false;
public:
	Pixel(const Brck* ptrBrck);
	~Pixel();
	bool& getBusy();
	Brck* getBrck();
	void set(const Brck* ptrBrck);
	Pixel &operator=(const Pixel& other);
	void empty();
};
#endif
