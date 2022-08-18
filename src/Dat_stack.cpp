#include "Dat_stack.h"

Dat_stack::Dat_stack()
{
    size = 0;
    datStack = nullptr;
}

Dat_stack::Dat_stack(const int &_size)
{
    size = _size;
    datStack = new int [size];
}

Dat_stack::~Dat_stack()
{
    if (datStack != nullptr)
    {
        delete[] datStack;
        datStack = nullptr;
    }
}

int &Dat_stack::get_size()
{
    return size;
}

int &Dat_stack::get_data(const int &index)
{
    return datStack[index];
}

void Dat_stack::set_data(const int &index, const int &data)
{
    datStack[index] = data;
}

void Dat_stack::set_size(const int &_size)
{
    if (datStack == nullptr)
    {
        size = _size;
        datStack = new int [size];
    }
}

