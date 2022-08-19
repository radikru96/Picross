#ifndef DAT_TABLE_H
#define DAT_TABLE_H
#include "Dat_stack.h"

class Dat_table
{
    unsigned int width;
    unsigned int *sizes;
    Dat_stack *datTable;
public:
    Dat_table(){}
    ~Dat_table();
    void init(const unsigned int &_width, const unsigned int *_sizes);
    void set_table(const unsigned int &_width, const unsigned int &index, const unsigned int &data);
    unsigned int &get_table(const unsigned int &_width, const unsigned int &index);
    unsigned int &get_size(const unsigned int &_width);
};
#endif
