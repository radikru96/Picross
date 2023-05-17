#ifndef FIELD_H
#define FIELD_H

#include "Pixel.h"

class Field {
private:
	Pixel** arr;
	unsigned int x;
	unsigned int y;
public:
	Field(const unsigned int& _x, const unsigned int& _y);
	~Field();
	void init(const unsigned int& _x, const unsigned int& _y);
	const Color& getColor( const unsigned int& _x, const unsigned int& _y) const;
	void setPix( const unsigned int& _x, const unsigned int& _y, const Color& _color);
	const unsigned int &getX() const;
	const unsigned int &getY() const;
};
#endif
