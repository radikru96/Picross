#ifndef DAT_STACK_H
#define DAT_STACK_H

class Dat_stack
{
    int *datStack;
    int size;
    
public:
    Dat_stack();
    Dat_stack(const int &_size);
    ~Dat_stack();
    int &get_size();
    int &get_data(const int &index);
    void set_data(const int &index, const int &data);
    void set_size(const int &_size);
};

#endif
