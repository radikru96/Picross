#ifndef BRICKFIELD_H
#define BRICKFIELD_H

#include "Brick.h"
#include "DataTable.h"

class BrickField : public DataTable<Brick> {
public:
	bool move(const unsigned int &_y, const unsigned int &_index, const unsigned int &_value);
};

#endif