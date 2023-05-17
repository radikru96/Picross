#ifndef DATATABLE_H
#define DATATABLE_H

#include "DataStack.h"
#include "Field.h"
#include "Brick.h"

class DataTable
{
protected:
    unsigned int width;
    unsigned int *sizes;
    DataStack<Brick> *dataTable;
public:
    virtual ~DataTable(){
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
            if ( _sizes[i] > 0 )
                sizes[i] = _sizes[i];
            else
                sizes[i] = 1;
        }
        dataTable = new DataStack<Brick>[width];
        for (unsigned int i = 0; i < width; i++)
        {
            dataTable[i].setSize(sizes[i]);
        }
    }
    
    void setData(const unsigned int &_width, const unsigned int &_index, const Brick &_data){
        dataTable[_width].setData(_index, _data);
    }
    
    Brick &getData(const unsigned int &_width, const unsigned int &_index) const {
        return dataTable[_width].getData(_index);
    }
    
    const unsigned int &getSize(const unsigned int &_width) const {
        return dataTable[_width].getSize();
    }

    const unsigned int &getShift() const {
        unsigned int i = 0;
        for ( unsigned int j = 1; j < width; ++j)
        {
            if ( getSize(i) < getSize(j) )
                i = j;
        }
        return getSize(i);
    }
};

#endif
