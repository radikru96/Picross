#include "Field.h"

Field::Field(const unsigned int& _x, const unsigned int& _y) : x(_x), y(_y) {
	arr = new Pixel* [x];
	for(unsigned int i = 0; i < x; i++)
		arr[i] = new Pixel[y];
}

Field::~Field(){
	for(unsigned int i = 0; i < x; i++)
		delete [] arr[i];
	delete [] arr;
}

void Field::init(const unsigned int& _x, const unsigned int& _y){
	if ( arr != nullptr)
		return;
	x = _x;
	y = _y;
	arr = new Pixel* [x];
	for(unsigned int i = 0; i < x; i++)
		arr[i] = new Pixel[y];
}

const Pixel& Field::getPix(const unsigned int& _x, const unsigned int& _y) const{
    return arr[_x][_y];
}

void Field::setPix(const unsigned int& _x, const unsigned int& _y, const Color& _color){
	arr[_x][_y] = _color;
}

const unsigned int &Field::getX(){
	return x;
}

const unsigned int &Field::getY(){
	return y;
}