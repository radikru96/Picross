#pragma once
// #include "Picross.cpp"

class pixel
{
    pix Pix;
    bool lock=false;

    void lock_pix();

public:
    pixel();
    ~pixel();
    pix& operator=(const pix& other);
    pix& get_pix();
    void set_pix(const pix &Pix);
    void uLock_pix();

};

pixel::pixel()
{
    Pix=pix::NON;
    lock=0;
}

pixel::~pixel(){}

pix& pixel::operator=(const pix& other)
{
    if (!lock)
    {
        Pix=other;
        lock_pix();
    }
    return Pix;
}

pix& pixel::get_pix()
{
    return Pix;
}

void pixel::set_pix(const pix &other)
{
    if (!lock)
    {
        Pix=other;
        lock_pix();
    }
}

void pixel::uLock_pix()
{
    lock=false;
}

void pixel::lock_pix()
{
    lock=true;
}