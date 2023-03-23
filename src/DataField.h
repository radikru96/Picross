#ifndef DATAFIELD_H
#define DATAFIELD_H

#include "Data.h"
#include "DataTable.h"

class DataField : public DataTable<Data> {
public:
	bool check(const unsigned int &_x);
};

#endif