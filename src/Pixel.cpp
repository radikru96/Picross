#include "Pixel.h"

Pixel::Pixel(const Brck *ptrBrck)
{
	ptrBrck = ptrBrck;
	busy = true;
}

Pixel::~Pixel()
{
	this->empty();
}

bool& Pixel::getBusy() : const
{
	return busy;
}

Brck* Pixel::getBrck() : const
{
	return ptrBrck;
}

void Pixel::set(const Brck *ptrBrck)
{
	ptrBrck = ptrBrck;
	busy = true;
}

Pixel& Pixel::operator=(const Pixel &other)
{
	this->ptrBrck = other.getBrck();
	this->busy = other.getBusy();
	return this;
}

void Pixel::empty()
{
	ptrBrck = nullptr;
	busy = false;
}
