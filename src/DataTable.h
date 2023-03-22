#ifndef DATATABLE_H
#define DATATABLE_H
#include "DataStack.h"

template <class T>
class DataTable
{
    unsigned int width;
    unsigned int *sizes;
    DataStack<T> *dataTable;
public:
    DataTable(){}
    ~DataTable();
    void init(const unsigned int &_width, const unsigned int *_sizes);
    void set_table(const unsigned int &_width, const unsigned int &_index, const T &_data);
    T &get_table(const unsigned int &_width, const unsigned int &_index) const;
    const unsigned int &get_size(const unsigned int &_width) const;
};

DataTable::~DataTable()
{
    if (sizes!=nullptr)
    {
        delete [] sizes;
        sizes = nullptr;
    }
    if (dataTable != nullptr)
    {
        delete [] dataTable;
        dataTable = nullptr;
    }
}

void DataTable::init(const unsigned int &_width, const unsigned int *_sizes)
{
    width = _width;
    sizes = new unsigned int[width];
    for (unsigned int i = 0; i < width; i++)
    {
        sizes[i] = _sizes[i];
    }
    dataTable = new DataStack<T>[width];
    for (unsigned int i = 0; i < width; i++)
    {
        dataTable[i].set_size(sizes[i]);
    }
}

void DataTable::set_table(const unsigned int &_width, const unsigned int &index, const T &data)
{
    dataTable[_width].set_data(index, data);
}

T &DataTable::get_table(const unsigned int &_width, const unsigned int &index) const
{
    return dataTable[_width].get_data(index);
}

const unsigned int &DataTable::get_size(const unsigned int &_width) const
{
    return dataTable[_width].get_size();
}

#endif