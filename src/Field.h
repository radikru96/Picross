#ifndef FIELD_H
#define FIELD_H

#include "Pixel.h"

class Field {
private:
	Pixel** arr;
	unsigned int x;
	unsigned int y;
public:
	Field(){}
	Field(const unsigned int& _x, const unsigned int& _y);
	~Field();
	void init(const unsigned int& _x, const unsigned int& _y);
	const Pixel& getPix( const unsigned int& _x, const unsigned int& _y) const;
	void setPix( const unsigned int& _x, const unsigned int& _y, const Color& _color);
};
#endif
