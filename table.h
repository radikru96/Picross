#pragma once
#include "pixel.h"

class table
{
    pixel **Table;

    int id, pos_x=0, pos_y=0;
public:
    static int count;
    static int X,Y;

    table(const int &x, const int &y);
    table(const table& other);
    ~table();
    void set_table(const int& x, const int& y, const pix& pix);
    pix& get_table(const int& x, const int& y);
    int get_pos();
    void set_pos(const int& pos_x,const int& pos_y);
    int& get_id();
};

int table::count=0;
int table::X;
int table::Y;

table::table(const int &x, const int &y)
{
    X=x;
    Y=y;
    id=count++;
    Table = new pixel*[X];
    for (int i = 0; i < X; ++i)
    {
        Table[i] = new pixel[Y];
    }
}

table::table(const table& other)
{
    Table = new pixel*[X];
    for (int i = 0; i < X; ++i)
    {
        Table[i] = new pixel[Y];
    }
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            this->Table[i][j]=other.Table[i][j];
        }
    }
    id=count++;
}

table::~table()
{
    for (int i = 0; i < X; ++i)
    {
        delete[] Table[i];
    }
    delete[] Table;
    count--;
}

void table::set_table(const int& x, const int& y, const pix& pix)
{
    Table[x][y]=pix;
}

pix& table::get_table(const int& x, const int& y)
{
    
    pixel temp_pixel = Table[x][y];
    return temp_pixel.get_pix();
}

int table::get_pos()
{
    return ((pos_x*100)+(pos_y));
}

void table::set_pos(const int& pos_x,const int& pos_y)
{
    this->pos_x=pos_x;
    this->pos_y=pos_y;
}

int& table::get_id()
{
    return id;
}
