#include "Dat_stack.h"

Dat_stack::Dat_stack()
{
    size = 0;
    datStack = nullptr;
}

Dat_stack::Dat_stack(const unsigned int &_size)
{
    size = _size;
    datStack = new unsigned int [size];
}

Dat_stack::~Dat_stack()
{
    if (datStack != nullptr)
    {
        delete[] datStack;
        datStack = nullptr;
    }
}

unsigned int &Dat_stack::get_size()
{
    return size;
}

unsigned int &Dat_stack::get_data(const unsigned int &index)
{
    return datStack[index];
}

void Dat_stack::set_data(const unsigned int &index, const unsigned int &data)
{
    datStack[index] = data;
}

void Dat_stack::set_size(const unsigned int &_size)
{
    if (datStack == nullptr)
    {
        size = _size;
        datStack = new unsigned int [size];
    }
}

