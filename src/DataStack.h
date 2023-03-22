#ifndef DATASTACK_H
#define DATASTACK_H

template <class T>
class DataStack{
private:
    T *arr;
    unsigned int size;
public:
    DataStack();
    DataStack(const unsigned int &_size);
    ~DataStack();
    const unsigned int &get_size() const;
    T &get_data(const unsigned int &index);
    void set_data(const unsigned int &index, const T &data);
    void set_size(const unsigned int &_size);
};

DataStack::DataStack(){
    size = 0;
    arr = nullptr;
}

DataStack::DataStack(const unsigned int &_size){
    size = _size;
    arr = new T [size];
}

DataStack::~DataStack(){
    if (arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
}

const unsigned int &DataStack::get_size() const {
    return size;
}

T &DataStack::get_data(const unsigned int &index){
    return arr[index];
}

void DataStack::set_data(const unsigned int &index, const T &data){
    arr[index] = data;
}

void DataStack::set_size(const unsigned int &_size){
    if (arr == nullptr)
    {
        size = _size;
        arr = new unsigned int [size];
    }
}

#endif