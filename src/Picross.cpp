#include "Picross.h"

Picross::Picross(const unsigned int& _x, const unsigned int& _y, unsigned int *vert_sizes, unsigned int *hori_sizes )
{
    x = _x;
    y = _y;
    table.init(x,y);
    vert.init(x, vert_sizes);
    hori.init(y, hori_sizes);
}

Picross::~Picross()
{
    delete[] bricks;
    bricks = nullptr;
}

void Picross::set_data_vert(const unsigned int &_width, const unsigned int *data)
{
    for (unsigned int i = 0; i < vert.get_size(_width); i++)
    {
        vert.set_table(_width,i,data[i]);
    }
}

void Picross::set_data_hori(const unsigned int &_width, const unsigned int *data)
{
    for (unsigned int i = 0; i < hori.get_size(_width); i++)
    {
        hori.set_table(_width,i,data[i]);
    }
}

void Picross::start()
{
}

void Picross::init()
{
    unsigned int brckNum = 0;
    for (unsigned int i = 0; i < x; i++)
        brckNum += vert.get_size(i);
    bricks = new Brck*[brckNum];
    unsigned int brckN = 0;
    for (unsigned int i = 0; i < x; i++){
        for (unsigned int j = 0; j < vert.get_size(i); j++)
        {
            bricks[brckN] = new Brck(vert.get_table(i,j),i,
        }
        
    }
    
}

unsigned int findBY( const unsigned int& _x, const unsigned int& _index )
{
    unsigned int value = 0;
    for (unsigned int i = 0; i <= _index; i++)
    {
        
    }
    
}