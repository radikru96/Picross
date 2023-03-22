#include "Data.h"

Data::Data(const Color &_color, const unsigned int& _size){
	color = _color;
	size = _size;
}

void Data::setSize(const unsigned int& _size){
	size = _size;
}

const unsigned int& Data::getSize() const{
	return size;
}

const Data& Data::operator=(const Data& other){
	size = other.size;
	color = other.color;
	return *this;
}