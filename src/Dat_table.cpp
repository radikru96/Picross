#include "Dat_table.h"

//int width;
//int *sizes;
//Dat_stack *datTable;

Dat_table::Dat_table(const int &_width, const int *_sizes)
{
    width = _width;
    sizes = new int[width];
    for (int i = 0; i < width; i++)
    {
        sizes[i] = _sizes[i];
    }
    datTable = new Dat_stack[width];
    for (int i = 0; i < width; i++)
    {
        datTable[i].set_size(sizes[i]);
    }
}

Dat_table::~Dat_table()
{
    if (sizes!=nullptr)
    {
        delete [] Sizes;
        Sizes = nullptr;
    }
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
