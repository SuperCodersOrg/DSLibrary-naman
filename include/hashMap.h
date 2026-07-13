#ifndef HASHMAP_H
#define HASHMAP_H
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
class HashMap{
    private:
    HashNode<K,V>** bucket;
    int size;
    int capacity;
    float threshold;
    float loadFactor;
    Hash<K> hasher;

    int nextPowerOf2(int n);
    HashNode<K,V>* find(HashNode<K,V>* head, K key);

    public:
    HashMap();
    HashMap(int capacity);
    ~HashMap();

    void set(K key, V value);
    V& get(const K key);
    void remove(const K key);
    bool exists(const K key);
    int getSize();
    float getLoadFactor();

};




#include "hashMap.tpp"

#endif