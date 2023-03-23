#include "Brick.h"

Brick::Brick(const Color &_color, const unsigned int &_size,
		const unsigned int &_begin, const unsigned int &_end){
	color = _color;
	size = _size;
	begin = _begin;
	end = _end;
}

const unsigned int &Brick::getBegin() const {
	return begin;
}

const unsigned int &Brick::getEnd() const {
	return end;
}

void Brick::setBegin(unsigned int &_begin){
	begin = _begin;
}

void Brick::setEnd(unsigned int &_end){
	end = _end;
}

void Brick::move( const unsigned int &_value ){
	begin += _value;
	end += _value;
}

const Brick &Brick::operator=(const Brick& other){
	color = other.color;
	size = other.size;
	begin = other.begin;
	end = other.end;
	return *this;
}