#ifndef PIXEL_H
#define PIXEL_H

#include "structs.h"

class Pixel {
public:
	Pixel(const Color &_color = Color::white);
	virtual ~Pixel(){}
	void setColor(const Color& _color = Color::white);
	const Color& getColor() const;
	virtual const Pixel& operator=(const Pixel& other);
protected:
	Color color;
};

#endif