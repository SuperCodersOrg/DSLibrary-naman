#ifndef QUEUE_H
#define QUEUE_H

#include "linkedList.h"

template<typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();

    Queue<T>& operator=(const Queue<T>& other);

    void enqueue(T value);
    T dequeue();

    T front() const;
    bool isEmpty() const;
    int size() const;
};

#include "queue.tpp"

#endif