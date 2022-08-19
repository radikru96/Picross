#ifndef TABLE_H
#define TABLE_H

class Table {
	bool** arr;
	unsigned int x;
	unsigned int y;
public:
	Table(){}
	Table(const unsigned int& _x, const unsigned int& _y);
	~Table();
	void init(const unsigned int& _x, const unsigned int& _y);
	bool& getPix( const unsigned int& _x, const unsigned int& _y );  
};
#endif
