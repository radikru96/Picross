#include "Pixel.h"

Pixel::Pixel(const Brck* ptrBrck)
{
	ptrBrck = ptrBrck;
	busy = true;
}

Pixel::~Pixel()
{
	this->empty();
}

bool& Pixel::getBusy()
{
	return busy;
}

Brck* Pixel::getBrck()
{
	return ptrBrck;
}

void Pixel::set(const Brck* ptrBrck)
{
	ptrBrck = ptrBrck;
	busy = true;
}

Pixel& Pixel::&operator=(const Pixel& other)
{
	this->ptrBrck = other.ptrBrck;
	this->ptrBrck = other.ptrBrck;
	return this;
}

void Pixel::empty()
{
	ptrBrck = nullptr;
	busy = false;
}
