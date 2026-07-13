#ifndef LINKEDLIST_H
#define LINKEDLIST_H



template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;

    Node();
    Node(T value);
    ~Node();
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    
    LinkedList();
    LinkedList(T arr[], int n);
    LinkedList(const LinkedList<T>& other);

    
    ~LinkedList();

    
    LinkedList<T>& operator=(const LinkedList<T>& other);

    
    void insertFront(T value);
    void insertBack(T value);
    void insert(int index, T value);


    Node<T>* getHead() const;
    Node<T>* getTail() const;
    T deleteFront();
    T deleteBack();

    
    bool search(T value);
    Node<T>* LinkedList<T>::findNode(const T& value);

    int size();
    void printForeward();
    void printBackward();
};

#include "LinkedList.tpp"

#endif