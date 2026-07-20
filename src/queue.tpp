#include "queue.h"
template<typename T>
Queue<T>::Queue()
{
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
    : list(other.list)
{
}

template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        list = other.list;
    }

    return *this;
}

template<typename T>
void Queue<T>::enqueue(T value)
{
    list.insertBack(value);
}

template<typename T>
T Queue<T>::dequeue()
{
    return list.deleteFront();
}

template<typename T>
T Queue<T>::front() const
{
    Node<T>* head = list.getHead();

    if (head == nullptr)
    {
        throw std::out_of_range("Queue is empty");
    }

    return head->value;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return list.getHead() == nullptr;
}

template<typename T>
int Queue<T>::size() const
{
    return list.size();
}