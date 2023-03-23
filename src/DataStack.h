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
        size = _size;
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
            size = _size;
            arr = new unsigned int [size];
        }
    }
};

#endif