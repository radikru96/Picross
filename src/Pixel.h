#ifndef PIXEL_H
#define PIXEL_H
#include "Brck.h"

class Pixel{
	Brck *ptrBrck = nullptr;
	bool busy = false;
public:
	Pixel(const Brck *ptrBrck);
	~Pixel();
	bool &getBusy() : const;
	Brck *getBrck() : const;
	void set(const Brck *ptrBrck);
	Pixel &operator=(const Pixel &other);
	void empty();
};
#endif
