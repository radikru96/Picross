#ifndef TABLE_H
#define TABLE_H

class Table {
	bool** arr;
	const unsigned int x;
	const unsigned int y;
public:
	Table(const unsigned int& _x, const unsigned int& _y);
	~Table();
	bool& getPix( const unsigned int& _x, const unsigned int& _y );  
};
#endif
