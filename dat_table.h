#pragma once
#include "dat_stack.h"

class dat_table
{
    int Width;
    int *Sizes;
    orientation Orient;
    dat_stack *Dat_table;
public:
    dat_table(const int &width, const int *sizes, const orientation &orient);
    ~dat_table();
    void set_table(const int &width, const int &index, const int &data);
    int &get_table(const int &width, const int &index);
    int &get_size(const int &width);
    state &get_state(const int &width, const int &index);
    void finish(const int &width, const int &index, const int &range_from, const int &range_to);
    void reset(const int &width, const int &index);
    int &get_range_from(const int &width, const int &index);
    int &get_range_to(const int &width, const int &index);
};
//width-
dat_table::dat_table(const int &width, const int *sizes, const orientation &orient)
{
    this->Width = width;
    this->Orient = orient;
    this->Sizes = new int[this->Width];
    for (int i = 0; i < this->Width; i++)
    {
        this->Sizes[i] = sizes[i];
    }
    this->Dat_table = new dat_stack[Width];
    for (int i = 0; i < this->Width; i++)
    {
        this->Dat_table[i].set_size(Sizes[i]);
    }
}

dat_table::~dat_table()
{
    if (Sizes!=nullptr){delete[]Sizes;Sizes=nullptr;}
    if (Dat_table!=nullptr){delete[]Dat_table;Dat_table=nullptr;}
}

void dat_table::set_table(const int &width, const int &index, const int &data)
{
    Dat_table[width].set_data(index,data);
}

int &dat_table::get_table(const int &width, const int &index)
{
    return Dat_table[width].get_data(index);
}

int &dat_table::get_size(const int &width)
{
    return Dat_table[width].get_size();
}

state &dat_table::get_state(const int &width, const int &index)
{
    return Dat_table[width].get_state(index);
}

void dat_table::finish(const int &width, const int &index, const int &range_from, const int &range_to)
{
    Dat_table[width].finish(index,range_from,range_to);
}

void dat_table::reset(const int &width, const int &index)
{
    Dat_table[width].reset(index);
}

int &dat_table::get_range_from(const int &width, const int &index)
{
    return Dat_table[width].get_range_from(index);
}

int &dat_table::get_range_to(const int &width, const int &index)
{
    return Dat_table[width].get_range_to(index);
}