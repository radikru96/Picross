#ifndef PICROSS_H
#define PICROSS_H
#include "Table.h"
#include "Brck.h"
#include "Dat_table.h"

class Picross
{
private:
    Dat_table vert;
    Dat_table hori;
    Table table;
    Brck *bricks;
    unsigned int x,y,brckNum;
public:
    Picross(const unsigned int& _x, const unsigned int& _y, unsigned int *vert_sizes, unsigned int *hori_sizes );
    ~Picross();
    void set_data_vert(const unsigned int &_width, const unsigned int &data);
    void set_data_hori(const unsigned int &_width, const unsigned int &data);
    void start();
};

#endif