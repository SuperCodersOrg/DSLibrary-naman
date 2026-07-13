#include "hashMap.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>

template<typename K,typename V>
HashNode<K,V>::HashNode(){
    key = K();
    value = V();
    next = NULL;
}

template<typename K,typename V>
HashNode<K,V>::HashNode(K key, V value){
    this->key = key;
    this->value = V();
    next = NULL;
}

template<typename K,typename V>
HashNode<K,V>::~HashNode(){

}

template<typename K>
size_t Hash<K>::operator()(const int & key) const{
    if(typeof(key) == int){
        uint32_t x = static_cast<uint32_t>(key);

        x = (x ^ 61) ^ (x >> 16);
        x += x << 3;
        x ^= x >> 4;
        x *= 0x27d4eb2d;
        x ^= x >> 15;

        return static_cast<size_t>(x);
    }
}
template<typename K,typename V>
int HashMap<K,V>::nextPowerOf2(int n)
{
    if (n <= 8)
        return 8;

    n--;

    for (int shift = 1; shift < sizeof(int) * 8; shift <<= 1)
        n |= n >> shift;

    return n + 1;
}

template<typename K>
size_t Hash<K>::operator()(const char & key) const{
    if(typeof(key) == int){
        uint32_t x = static_cast<uint32_t>(key);

        x = (x ^ 61) ^ (x >> 16);
        x += x << 3;
        x ^= x >> 4;
        x *= 0x27d4eb2d;
        x ^= x >> 15;

        return static_cast<size_t>(x);
    }
}
template<typename K>
size_t Hash<K>::operator()(const char& key) const
    {
        uint32_t x = static_cast<unsigned char>(key);
        x *= 2654435761u;
        return static_cast<size_t>(x);
    }

template<typename K>
size_t Hash<K>::operator()(const float& key) const
{
    uint32_t bits;
    std::memcpy(&bits, &key, sizeof(float));

    bits = (bits ^ 61) ^ (bits >> 16);
    bits += bits << 3;
    bits ^= bits >> 4;
    bits *= 0x27d4eb2d;
    bits ^= bits >> 15;

    return static_cast<size_t>(bits);
}

template<typename K, typename V>
HashMap<K, V>::HashMap()
{
    size = 0;
    capacity = 8;
    threshold = 0.75f;

    bucket = (HashNode<K, V>**)malloc(capacity * sizeof(HashNode<K, V>*));

    if (bucket == NULL)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < capacity; i++)
    {
        bucket[i] = NULL;
    }
}

template<typename K, typename V>
HashMap<K, V>::HashMap(int initialCapacity)
{
    size = 0;
    capacity = nextPowerOf2(initialCapacity);
    threshold = 0.75f;

    bucket = (HashNode<K, V>**)malloc(capacity * sizeof(HashNode<K, V>*));

    if (bucket == NULL)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < capacity; i++)
    {
        bucket[i] = NULL;
    }
}

template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
    for (int i = 0; i < capacity; i++)
    {
        HashNode<K, V>* current = buckets[i];
        while (current != NULL)
        {
            HashNode<K, V>* next = current->next;
            current->~HashNode<K, V>();   
            free(current);                

            current = next;
        }

        buckets[i] = NULL;
    }

    free(buckets);

    buckets = NULL;
    capacity = 0;
    size = 0;
    loadFactor = 0;
}
template<typename K, typename V>
void HashMap<K,V> :: set(const K key,const V value){
    size_t hashValue = hasher(key);
    int destinationBucket = hashValue % capacity;
    HashNode<K,V>* temp = bucket[destinationBucket];
    HashNode<K,V>* location = find(temp,key);
    if(location){ // That key already exists
        location->value = value;
        return;
    }
    HashNode<K,V>* newNode =  (HashNode<K,V>*)malloc(sizeof(HashNode<K,V>));
    if(newNode==NULL){
        throw std::bad_alloc();
    }
    new(newNode)HashNode<K,V>(key,value);
    newNode->next = temp;
    bucket[destinationBucket] = newNode;
    size++;
    return;
    
}
template<typename K, typename V>
void HashMap<K,V> :: remove(const K key){
    size_t index = hasher(key) % capacity;
    HashNode<K,V> *cur = find(bucket[index],key);
    if(!cur){
        std::cout<<"Key Does not exist";
        return;
    }
    if(bucket[index] == cur){
        bucket[index] = cur->next;

    }else{
        HashNode<K,V> *prev = bucket[index];
        while(prev->next != cur){
            prev = prev->next;
        }
        prev->next = cur->next;
    }
    
    cur->next = NULL;
    cur->~HashNode<K,V>();
    free(cur);
    size--;
    return;
}

template<typename K, typename V>
V& HashMap<K,V> :: get(const K key){
    size_t index = hasher(key) % capacity;
    HashNode<K,V> *cur = find(bucket[index],key);
    if(!cur){
        throw std::out_of_range("Key not found");
    }
    return cur->value;

}

template<typename K, typename V>
HashNode<K,V>* HashMap<K, V> ::find(HashNode<K,V>* head, K key){
    if(head == NULL){
        return NULL;
    }
    HashNode<K,V>* temp = head;
    while(temp){
        if(temp->key == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;

}

template<typename K, typename V>
bool HashMap<K, V> ::exists(const K key){
    size_t hashValue = hasher(key);
    int bucketIndex = hashValue % capacity;

    return find(bucket[bucketIndex], key) != NULL;
}

template<typename K, typename V>
int HashMap<K, V>:: getSize(){
    return size;
}

template<typename K, typename V>
float HashMap<K, V>:: getLoadFactor(){
    return loadFactor;
}
