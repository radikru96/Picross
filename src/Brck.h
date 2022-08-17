#ifndef BRCK_H
#define BRCK_H

class Brck {
	static unsigned int count;
	unsigned int id,x,by,ey,size;
public:
	Brck(	unsigned const int &_size,	unsigned const int &_x,
			unsigned const int &_by,	unsigned const int &_ey );
	unsigned int &getSize();
	unsigned int &getId();
	unsigned int &getX();
	unsigned int &getBy();
	unsigned int &getEy();
};
#ifndef BRCK_COUNT
#define BRCK_COUNT
unsigned int Brck::count = 0;
#endif
#endif
