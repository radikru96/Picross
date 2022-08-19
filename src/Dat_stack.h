#ifndef DAT_STACK_H
#define DAT_STACK_H

class Dat_stack
{
    unsigned int *datStack;
    unsigned int size;
    
public:
    Dat_stack();
    Dat_stack(const unsigned int &_size);
    ~Dat_stack();
    unsigned int &get_size();
    unsigned int &get_data(const unsigned int &index);
    void set_data(const unsigned int &index, const unsigned int &data);
    void set_size(const unsigned int &_size);
};

#endif
