#ifndef BRCK_H
#define BRCK_H
#include "Table.h"

class Brck {
	Table* table;
	static unsigned int count;
	unsigned int id,x,by,ey,size;
public:
	Brck(	Table* _table,
			unsigned const int& _size,	unsigned const int& _x,
			unsigned const int& _by,	unsigned const int& _ey );
	~Brck();
	unsigned int& getSize();
	unsigned int& getId();
	void stepUp( Table& _table );
	void stepDown( Table& _table );
};
#ifndef BRCK_COUNT
#define BRCK_COUNT
static unsigned int count = 0;
#endif
#endif
