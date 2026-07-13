#ifndef HASHMAP_H
#define HASHMAP_H
#include "dynamicArray.h"
#include <cstddef>

template<typename K, typename V>
class HashNode
{
public:
    K key;
    V value;
    HashNode<K,V>* next;

    HashNode();
    HashNode(K key, V value);
    ~HashNode();
};

template<typename K>
class Hash
{
public:
    size_t operator()(const int& key) const;
    size_t operator()(const char& key) const;
    size_t operator()(const float& key) const;
};

template<typename K, typename V>
class HashMap
{
private:
    DynamicArray<HashNode<K,V>*> buckets;

    int size;
    int capacity;
    float threshold;
    float loadFactor;

    Hash<K> hasher;

    int nextPowerOf2(int n);
    HashNode<K,V>* find(HashNode<K,V>* head, const K& key);
    void rehash();

public:
    HashMap<K,V>();
    HashMap(int capacity);
    HashMap(const HashMap<K,V>& obj);
    ~HashMap();

    HashMap<K,V>& operator=(const HashMap<K,V>& obj);

    void set(const K& key, const V& value);
    V& get(const K& key);
    void remove(const K& key);
    bool exists(const K& key) ;

    int getSize() const;
    float getLoadFactor() const;
};




#include "hashMap.tpp"

#endif