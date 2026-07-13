#include "dynamicArray.h"
#include <cstdlib>
#include <new>
#include <stdexcept>

template<typename T>
int DynamicArray<T>::nextPowerOf2(int n)
{
    if (n <= 4)
        return 4;

    n--;

    for (int shift = 1; shift < sizeof(int) * 8; shift <<= 1)
        n |= n >> shift;

    return n + 1;
}

template<typename T>
double DynamicArray<T>::growthFactor(int currentCapacity)
{
    size_t bytes = (size_t)currentCapacity * sizeof(T);

    if (bytes < 1 * 1024 * 1024) // 1MB
        return 2.0;
    else if (bytes < 16 * 1024 * 1024) // 1 - 16MB
        return 1.5;
    else // greater then this
        return 1.25;
}

template<typename T>
void DynamicArray<T>::resize()
{
    double factor = growthFactor(capacity);
    int newCapacity = (int)(capacity * factor);

    if (newCapacity <= capacity)
        newCapacity = capacity * 2;

    T* newPtr = (T*)malloc(newCapacity * sizeof(T));

    if (ptr == nullptr) {
        throw std::bad_alloc();
    }

    for (int i = 0; i < size; i++)
        new (&newPtr[i]) T(ptr[i]);

    for (int i = 0; i < size; i++)
        ptr[i].~T();

    free(ptr);

    ptr = newPtr;
    newPtr = NULL;
    capacity = newCapacity;
}

template<typename T>
DynamicArray<T>::DynamicArray()
{
    this->size = 0;
    this->capacity = 4;
    this->ptr = (T*)malloc(capacity * sizeof(T));
    if (ptr == nullptr) {
        throw std::bad_alloc();
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(int initialCapacity)
{
    this->size = 0;
    this->capacity = nextPowerOf2(initialCapacity);
    this->ptr = (T*)malloc(capacity * sizeof(T));
    if (ptr == nullptr) {
        throw std::bad_alloc();
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& obj)
{
    this->capacity = obj.capacity;
    this->size = obj.size;

    this->ptr = (T*)malloc(capacity * sizeof(T));
    if (ptr == NULL) {
        throw std::bad_alloc();
    }

    for (int i = 0; i < size; i++)
        new (&ptr[i]) T(obj.ptr[i]);
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i].~T();
    }

    free(ptr);
    ptr = NULL;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& obj)
{
    if (this == &obj)
        return *this;

    T* newPtr = (T*)malloc(obj.capacity * sizeof(T));
    if (newPtr == NULL)
        throw std::bad_alloc();

    for (int i = 0; i < obj.size; i++)
        new (&newPtr[i]) T(obj.ptr[i]);

    for (int i = 0; i < size; i++)
        ptr[i].~T();

    free(ptr);

    ptr = newPtr;
    size = obj.size;
    capacity = obj.capacity;

    return *this;
}

template<typename T>
void DynamicArray<T>::append(T value)
{
    if (size == capacity)
        resize();

    ptr[size] = value;
    size++;
}


template<typename T>
T& DynamicArray<T>::operator[](int index) {
    return ptr[index];
}
template<typename T>
const T& DynamicArray<T>::operator[](int index) const
{
    return ptr[index];
}

template<typename T>
T DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= size)
    {
        std::out_of_range("Cannot access this memory");
    }

    T savedValue = ptr[index];

    for (int i = index; i < size - 1; i++)
    {
        ptr[i].~T();
        new (&ptr[i]) T(ptr[i + 1]);
    }

    size--;
    return savedValue;
}

template<typename T>
T DynamicArray<T>::get(int index) const
{
    if (index < 0 || index >= size)
    {
        std::out_of_range("Cannot access this memory");
    }

    return ptr[index];
}

template<typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}

template<typename T>
int DynamicArray<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
void DynamicArray<T>::insert(int index, T value)
{
    if (index < 0 || index > size)
    {
        std::out_of_range("Cannot access this memory");
    }

    if (size == capacity)
        resize();

    if (index == size)
    {
        append(value);
        return;
    }

    for (int i = size - 1; i >= index; i--)
    {
        new (&ptr[i + 1]) T(ptr[i]);
        ptr[i].~T();
    }

    new (&ptr[index]) T(value);

    size++;
}