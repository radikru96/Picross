#ifndef DATATABLE_H
#define DATATABLE_H

#include "DataStack.h"
#include "Field.h"

template <class T>
class DataTable
{
protected:
    unsigned int width;
    unsigned int *sizes;
    DataStack<T> *dataTable;
    Field *field;
public:
    DataTable(Field *_field) : field(_field){}
    ~DataTable(){
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
    
    void init(const unsigned int &_width, const unsigned int *_sizes){
        width = _width;
        sizes = new unsigned int[width];
        for (unsigned int i = 0; i < width; i++)
        {
            sizes[i] = _sizes[i];
        }
        dataTable = new DataStack<T>[width];
        for (unsigned int i = 0; i < width; i++)
        {
            dataTable[i].setSize(sizes[i]);
        }
    }
    
    void setData(const unsigned int &_width, const unsigned int &_index, const T &_data){
        dataTable[_width].setData(_index, _data);
    }
    
    T &getData(const unsigned int &_width, const unsigned int &_index) const {
        return dataTable[_width].getData(_index);
    }
    
    const unsigned int &getSize(const unsigned int &_width) const {
        return dataTable[_width].getSize();
    }
};

#endif