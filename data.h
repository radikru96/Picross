#pragma once

class data
{
    int range_from,range_to;
    int dat;
    state State=RUN;
public:
    data(const int &dat);
    data();
    ~data();
    void set_data(const int &dat);
    int &get_data();
    void finish(const int &range_from, const int &range_to);
    void reset();
    state &get_state();
    int &operator= (const int &dat);
    int &get_range_from();
    int &get_range_to();
};

data::data(const int &dat)
{
    if (dat<100)
    {
        this->dat=dat;
    }
}

data::data ()
{
    dat=0;
}

data::~data(){}

void data::set_data(const int &dat)
{
    if (dat<100)
    {
        this->dat=dat;
    }    
}

int &data::get_data()
{
    return this->dat;
}

void data::finish(const int &range_from, const int &range_to)
{
    this->range_from=range_from;
    this->range_to=range_to;
    this->State=FINISH;
}

void data::reset()
{
    this->State=RUN;
}

state &data::get_state()
{
    return this->State;
}

int &data::operator= (const int &dat)
{
    return this->dat=dat;
}


int &data::get_range_from()
{
    return range_from;
}
int &data::get_range_to()
{
    return range_to;
}