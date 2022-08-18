#ifndef DAT_TABLE_H
#define DAT_TABLE_H
#include "Dat_stack.h"

class Dat_table
{
    int width;
    int *sizes;
    Dat_stack *datTable;
public:
    Dat_table(const int &_width, const int *_sizes);
    ~Dat_table();
    void set_table(const int &_width, const int &index, const int &data);
    int &get_table(const int &_width, const int &index);
    int &get_size(const int &_width);
};

