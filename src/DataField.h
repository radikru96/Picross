#ifndef DATAFIELD_H
#define DATAFIELD_H

#include "Brick.h"
#include "DataTable.h"
#include "Field.h"
#include <iostream>

class DataField : public DataTable {
private:
	Field &field;
public:
	DataField(Field &_field, const unsigned int &_width, const unsigned int *_sizes);
	~DataField();
	bool check(const unsigned int &_x) const;
};

#endif
