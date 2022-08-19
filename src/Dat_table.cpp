#include "Dat_table.h"

//int width;
//int *sizes;
//Dat_stack *datTable;

Dat_table::~Dat_table()
{
    if (sizes!=nullptr)
    {
        delete [] sizes;
        sizes = nullptr;
    }
    if (datTable != nullptr)
    {
        delete [] datTable;
        datTable = nullptr;
    }
}

void Dat_table::init(const unsigned int &_width, const unsigned int *_sizes)
{
    width = _width;
    sizes = new unsigned int[width];
    for (unsigned int i = 0; i < width; i++)
    {
        sizes[i] = _sizes[i];
    }
    datTable = new Dat_stack[width];
    for (unsigned int i = 0; i < width; i++)
    {
        datTable[i].set_size(sizes[i]);
    }
}

void Dat_table::set_table(const unsigned int &_width, const unsigned int &index, const unsigned int &data)
{
    datTable[_width].set_data(index, data);
}

unsigned int &Dat_table::get_table(const unsigned int &_width, const unsigned int &index)
{
    return datTable[_width].get_data(index);
}

unsigned int &Dat_table::get_size(const unsigned int &_width)
{
    return datTable[_width].get_size();
}
