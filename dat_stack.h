#pragma once
#include "data.h"

class dat_stack
{
    data *Dat_stack;
    int SIZE;
    
public:
    dat_stack();
    dat_stack(const int &size);
    ~dat_stack();
    int &get_size();
    state& get_state(const int &index);
    void finish(const int &index, const int &range_from, const int &range_to);
    void reset(const int &index);
    int &get_data(const int &index);
    void set_data(const int &index, const int &data);
    void set_size(const int &size);
    int &get_range_from(const int &index);
    int &get_range_to(const int &index);
};

dat_stack::dat_stack()
{
    this->SIZE=0;
}

dat_stack::dat_stack(const int &size)
{
    this->SIZE=size;
    if (SIZE==0)
    {
        this->Dat_stack=new data [++SIZE];
    }
    else 
    {
        this->Dat_stack=new data [SIZE];
    }
}

dat_stack::~dat_stack()
{
    if (Dat_stack!=nullptr)
    {
        delete[] this->Dat_stack;
        this->Dat_stack=nullptr;
    }
}

int &dat_stack::get_size()
{
    return this->SIZE;
}

state& dat_stack::get_state(const int &index)
{
    return this->Dat_stack[index].get_state();
}

void dat_stack::finish(const int &index, const int &range_from, const int &range_to)
{
    this->Dat_stack[index].finish(range_from,range_to);
}

void dat_stack::reset(const int &index)
{
    this->Dat_stack[index].reset();
}

int &dat_stack::get_data(const int &index)
{
    return this->Dat_stack[index].get_data();
}

void dat_stack::set_data(const int &index, const int &data)
{
    this->Dat_stack[index]=data;
}

void dat_stack::set_size(const int &size)
{
    if (this->Dat_stack==nullptr)
    {
        this->SIZE=size;
        if (SIZE==0)
        {
            this->Dat_stack=new data[++SIZE];
        }
        else
        {
            this->Dat_stack=new data[SIZE];
        }
    }
}

int &dat_stack::get_range_from(const int &index)
{
    return Dat_stack[index].get_range_from();
}

int &dat_stack::get_range_to(const int &index)
{
    return Dat_stack[index].get_range_to();
}