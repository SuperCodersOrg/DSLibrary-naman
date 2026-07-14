#ifndef HASHMAP_H
#define HASHMAP_H
#include "dynamicArray.h"
#include "linkedList.h"
#include <cstddef>
#include <cstring>

template<typename K, typename V>
class HashNode
{
public:
    K key;
    V value;
    
    HashNode();
    HashNode(const K &key,const V &value);
    HashNode(const K &key);
    bool operator==(const HashNode& other) const;
    ~HashNode();
};

template<typename K>
class Hash
{
public:
    size_t operator()(const K& key) const;
};
template<>
class Hash<int>
{
public:
    size_t operator()(const int& key) const;
};
template<>
class Hash<char>
{
public:
    size_t operator()(const char& key) const;
};
template<>
class Hash<std::string>
{
public:
    size_t operator()(const std::string& key) const;
};
template<>
class Hash<float>
{
public:
    size_t operator()(const float& key) const;
};

template<typename K, typename V>
class HashMap
{
private:
    DynamicArray<LinkedList<HashNode<K,V>>> buckets;

    int size;
    int capacity;
    float threshold;
    float loadFactor;

    Hash<K> hasher;

    int nextPowerOf2(int n);
    void rehash();

public:
    HashMap();
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