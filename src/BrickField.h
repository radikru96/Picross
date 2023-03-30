#ifndef BRICKFIELD_H
#define BRICKFIELD_H

#include "Brick.h"
#include "DataTable.h"
#include "Field.h"

class BrickField : public DataTable<Brick> {
private:
	Field &field;
public:
	BrickField(Field &_field, const unsigned int &_width, const unsigned int *_sizes);
	~BrickField();
	bool move(const unsigned int &_y, const unsigned int &_index, const int &_value);
	bool startPos();
private:
	int isBusy(const unsigned int &_y, const unsigned int &_begin, const unsigned int &_end);
};

#endif