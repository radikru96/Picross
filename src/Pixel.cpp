#include "Pixel.h"

Pixel::Pixel(const Color &_color){
	color = _color;
}

void Pixel::setColor(const Color& _color){
	color = _color;
}

const Color& Pixel::getColor() const{
	return color;
}

const Pixel &Pixel::operator=(const Pixel& other){
	color=other.color;
	return *this;
}