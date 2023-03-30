#ifndef DATA_H
#define DATA_H

#include "Pixel.h"

class Data : public Pixel {
protected:
	unsigned int size;
public:
	Data(const Color &_color = Color::black,const unsigned int& _size = 0);
	virtual ~Data(){}
	void setSize(const unsigned int& _size);
	const unsigned int& getSize() const;
	virtual const Data& operator=(const Data& other);
};

#endif