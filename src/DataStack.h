#ifndef DATASTACK_H
#define DATASTACK_H

template <class T>
class DataStack{
private:
    T *arr;
    unsigned int size;
public:
    DataStack(){
        size = 0;
        arr = nullptr;
    }
    
    DataStack(const unsigned int &_size){
        if (_size > 0)
            size = _size;
        else
            size = 1;
        arr = new T [size];
    }
    
    ~DataStack(){
        if (arr != nullptr){
            delete[] arr;
            arr = nullptr;
        }
    }
    
    const unsigned int &getSize() const{
        return size;
    }
    
    T &getData(const unsigned int &index){
        return arr[index];
    }
    
    void setData(const unsigned int &index, const T &data){
        arr[index] = data;
    }
    
    void setSize(const unsigned int &_size){
        if (arr == nullptr)
        {
            if (_size > 0)
                size = _size;
            else
                size = 1;
            arr = new T [size];
        }
    }
};

#endif