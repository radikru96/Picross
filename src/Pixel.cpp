#include "Pixel.h"

Pixel::Pixel(const Brick* ptrBrck)
{
	ptrBrick = ptrBrck;
	busy = true;
}

Pixel::~Pixel()
{
	ptrBrick = nullptr;
}

bool& Pixel::getBusy()
{
	return busy;
}

Brick* Pixel::getBrick()
{
	return ptrBrick;
}

void Pixel::set(const Brick* ptrBrck)
{
	ptrBrick = ptrBrck;
	busy = true;
}

Pixel Pixel::&operator=(const Pixel& other)
{
	this->ptrBrick = other.ptrBrick;
	this->ptrBrick = other.ptrBrick;
	return this;
}

