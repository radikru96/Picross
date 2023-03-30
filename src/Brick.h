#ifndef BRICK_H
#define BRICK_H

#include "Data.h"

class Brick : public Data {
private:
	unsigned int begin,end;
public:
	Brick(const Color &_color = Color::black, const unsigned int &_size = 0,
		const unsigned int &_begin = 0, const unsigned int &_end = 0);
	~Brick(){}
	const unsigned int &getBegin() const;
	const unsigned int &getEnd() const;
	void setBegin(const unsigned int &_begin);
	void setEnd(const unsigned int &_end);
	void move( const int &value );
	virtual const Brick &operator=(const Brick &other);
};

#endif
