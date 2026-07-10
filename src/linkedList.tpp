#include "linkedList.h"
#include <cstdlib>
#include <new>
#include <stdexcept>
#include <iostream>

template <typename T>
Node<T> :: Node() : value(), prev(NULL), next(NULL) {}

template <typename T>
Node<T> :: Node(T value){
    this->value = value;
    prev = NULL;
    next = NULL;
}

template <typename T>
Node<T> ::~Node(){}

template <typename T>
LinkedList<T> :: LinkedList(){
    head = tail = NULL;
    length = 0;
}

template <typename T>
LinkedList<T> ::LinkedList(T arr[], int n) {
    head = NULL;
    tail = NULL;
    length = 0;

    for (int i = 0; i < n; i++) {
        insertBack(arr[i]);
    }
}

template <typename T>
LinkedList<T> :: LinkedList(const LinkedList<T>& other) {
    head = NULL;
    tail = NULL;
    length = 0;

    Node<T>* temp = other.head;

    while (temp != NULL) {
    insertBack(temp->value);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T> ::~LinkedList() {
    Node<T>* temp = head;

    while (temp != NULL) {
        Node<T>* nextNode = temp->next;

        temp->~Node<T>();
        free(temp);

        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
LinkedList<T>& LinkedList<T> ::operator=(const LinkedList<T>& other)
{
    if (this == &other)
        return *this;
    Node<T>* temp = head;
    while (temp != NULL) {
            Node<T>* next = temp->next;

            temp->~Node<T>();
            free(temp);

            temp = next;
        }
        head = NULL;
        tail = NULL;
        length = 0;
        temp = other.head;
        while (temp != NULL) {
            insertBack(temp->value);
            temp = temp->next;
        }
        return *this;
}
template <typename T>
void LinkedList<T> ::insertBack(T value) {
    Node<T>* newNode = (Node<T>*) malloc(sizeof(Node<T>));
    if (newNode == NULL) {
        throw std::bad_alloc();
    }

    new (newNode) Node<T>(value);   

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    length++;
}

template <typename T>
void LinkedList<T> ::insertFront(T value) {
    Node<T>* newNode = (Node<T>*) malloc(sizeof(Node<T>));
    if (newNode == NULL) {
        throw std::bad_alloc();
    }

    new (newNode) Node<T>(value);   

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    length++;
}

template <typename T>
T LinkedList<T> ::deleteFront() {
    if (head == NULL) {
        throw std::out_of_range("List is empty");
    }

    Node<T>* temp = head;
    T ret = temp->value;

    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
    }

    temp->~Node<T>();
    free(temp);
    temp = NULL;
    length--;
    return ret;
}

template<typename T>
T LinkedList<T> ::deleteBack(){
    if(head == NULL){
        throw std::out_of_range("List is empty");
    }
    Node<T>* temp = tail;
    T ret = temp->value;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
    }
    temp->~Node<T>();
    free(temp);
    temp = NULL;
    length--;
    return ret;
}

template<typename T>
bool LinkedList<T> ::search(T value){
    Node<T>* temp = head;
    while(temp){
        if(temp->value == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
template<typename T>
void LinkedList<T> ::printForeward(){
    Node<T>* temp = head;
    while(temp->next){
        std::cout<<temp->value <<"<->";
        temp = temp->next;
    }
    std::cout<<temp->value<<std::endl;
}

template<typename T>
void LinkedList<T> ::printBackward(){
    Node<T>* temp = tail;
    while(temp->next){
        std::cout<<temp->value <<"<->";
        temp = temp->prev;
    }
    std::cout<<temp->value<<std::endl;
}

template<typename T>
int LinkedList<T> ::size(){
    return length;
}

template<typename T>
void LinkedList<T> ::insert(int index, T value) {
    if (index < 0) {
        throw std::out_of_range("Invalid index");
    }
    else if (index == 0) {
        insertFront(value);
        return;
    }
    else if (index >= length) {
        insertBack(value);
        return;
    }

    Node<T>* cur = head;
    Node<T>* pre = NULL;

    while (index--) {
        pre = cur;
        cur = cur->next;
    }

    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    if (newNode == NULL) {
        throw std::bad_alloc();
    }

    new (newNode) Node<T>(value);

    pre->next = newNode;
    newNode->prev = pre;
    newNode->next = cur;
    cur->prev = newNode;

    length++;
}
