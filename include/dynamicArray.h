#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cstdlib>

template <typename T>
class DynamicArray {
private:
    int size;
    int capacity;
    T* ptr;

    int nextPowerOf2(int n);
    double growthFactor(int currentCapacity);
    void resize();

public:
    
    DynamicArray();
    DynamicArray(int initialCapacity);
    DynamicArray(const DynamicArray& obj);

    
    ~DynamicArray();

    
    DynamicArray& operator=(const DynamicArray& obj);
    T& operator[](int index);
    const T& operator[](int index) const;
    
    void append(T value);
    void insert(int index, T value);
    T remove(int index);
 
    T get(int index) const;
    int getSize() const;
    int getCapacity() const;
    
};


#include "dynamicArray.tpp"

#endif