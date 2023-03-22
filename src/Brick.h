#ifndef BRICK_H
#define BRICK_H

#include "Data.h"

class Brick : public Data {
private:
	unsigned int begin,end;
public:
	Brick(const Color &_color = Color::white, const unsigned int &_size = 0,
		const unsigned int &_begin = 0, const unsigned int &_end = 0);
	unsigned int &getBegin() const;
	unsigned int &getEnd() const;
	void setBegin(unsigned int &_begin);
	void setEnd(unsigned int &_bnd);
	void stepUp( const unsigned int &value );
	void stepDown( const unsigned int &value );
	virtual const Brick &operator=(const Brick &other);
};

#endif
