#include "hashMap.h"
#include "dynamicArray.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <cstdint>

template<typename K,typename V>
HashNode<K,V>::HashNode(){
    key = K();
    value = V();
}
template<typename K,typename V>
HashNode<K,V>::HashNode(K &key, V &value){
    this->key = key;
    this->value = value;
    
}
template<typename K, typename V>
bool HashNode<K,V>::operator==(const HashNode<K,V>& other) const
{
    return key == other.key;
}
template<typename K,typename V>
HashNode<K,V>::~HashNode(){

}
template<typename K>
size_t Hash<K>::operator()(const int & key) const{
        uint32_t x = static_cast<uint32_t>(key);

        x = (x ^ 61) ^ (x >> 16);
        x += x << 3;
        x ^= x >> 4;
        x *= 0x27d4eb2d;
        x ^= x >> 15;

        return static_cast<size_t>(x);
    
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
template<typename K, typename V>
void HashMap<K,V>::rehash()
{
    int oldCapacity = capacity;
    capacity *= 2;

    DynamicArray<HashNode<K,V>*> newBuckets(capacity);

    for (int i = 0; i < capacity; i++)
    {
        newBuckets.append(NULL);
    }

    for (int i = 0; i < oldCapacity; i++)
    {
        HashNode<K,V>* cur = buckets[i];

        while (cur)
        {
            HashNode<K,V>* nextNode = cur->next;

            int index = hasher(cur->key) % capacity;

            cur->next = newBuckets[index];
            newBuckets[index] = cur;

            cur = nextNode;
        }

        buckets[i] = NULL;
    }

    buckets = newBuckets;

    loadFactor = static_cast<float>(size) / capacity;
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
template<typename K>
size_t Hash<K>::operator()(const std::string& key) const
{
    uint64_t hash = 14695981039346656037ULL; // FNV offset basis

    for (char c : key)
    {
        hash ^= static_cast<unsigned char>(c);
        hash *= 1099511628211ULL;            // FNV prime
    }

    return static_cast<size_t>(hash);
}
template<typename K, typename V>
HashMap<K, V>::HashMap()
{
    size = 0;
    capacity = 8;
    threshold = 0.75f;
    loadFactor = 0.0f;

    buckets = DynamicArray<LinkedList<HashNode<K,V>>>(capacity);

    for (int i = 0; i < capacity; i++)
    {
        buckets.append(LinkedList<HashNode<K,V>>());
    }
}
template<typename K, typename V>
HashMap<K,V>::HashMap(int initialCapacity)
{
    size = 0;
    capacity = nextPowerOf2(initialCapacity);
    threshold = 0.75f;
    loadFactor = 0.0f;

    buckets = DynamicArray<LinkedList<HashNode<K,V>>>(capacity);

    for (int i = 0; i < capacity; i++)
    {
        buckets.append(LinkedList<HashNode<K,V>>());
    }
}
template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V>& other)
{
    size = 0;
    capacity = other.capacity;
    threshold = other.threshold;
    loadFactor = 0.0f;
    hasher = other.hasher;

    buckets = DynamicArray<LinkedList<HashNode<K,V>>>(capacity);

    for (int i = 0; i < capacity; i++)
    {
        buckets.append(LinkedList<HashNode<K,V>>());
    }

    for (int i = 0; i < other.capacity; i++)
    {
        Node<HashNode<K,V>>* cur = other.buckets[i].getHead();

        while (cur)
        {
            set(cur->value.key, cur->value.value);
            cur = cur->next;
        }
    }
}
template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
    size = 0;
    capacity = 0;
    loadFactor = 0.0f;
}


template<typename K, typename V>
void HashMap<K,V>::set(const K &key, const V &value)
{
    size_t hashValue = hasher(key);
    int destinationBucket = hashValue % capacity;

    HashNode<K,V>* temp = buckets[destinationBucket];
    HashNode<K,V>* location = find(temp, key);

    if (location)
    {
        location->value = value;
        return;
    }

    HashNode<K,V>* newNode =
        (HashNode<K,V>*)malloc(sizeof(HashNode<K,V>));

    if (newNode == nullptr)
    {
        throw std::bad_alloc();
    }

    new (newNode) HashNode<K,V>(key, value);

    newNode->next = temp;
    buckets[destinationBucket] = newNode;

    size++;

    if (getLoadFactor() > threshold)
    {
        rehash();
    }
}
template<typename K, typename V>
void HashMap<K,V>::remove(const K& key)
{
    int index = hasher(key) % capacity;
    HashNode<K,V>* cur = find(buckets[index], key);
    if (!cur)
    {
        std::cout << "Key Does not exist";
        return;
    }
    if (buckets[index] == cur)
    {
        buckets[index] = cur->next;
    }
    else
    {
        HashNode<K,V>* prev = buckets[index];
        while (prev->next != cur)
        {
            prev = prev->next;
        }
        prev->next = cur->next;
    }

    cur->next = NULL;
    cur->~HashNode<K,V>();
    free(cur);
    size--;
}
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other)
{
    if (this == &other)
    {
        return *this;
    }
    for (int i = 0; i < capacity; i++)
    {
        HashNode<K, V>* cur = buckets[i];

        while (cur)
        {
            HashNode<K, V>* next = cur->next;
            cur->~HashNode<K, V>();
            free(cur);
            cur = next;
        }
    }

    capacity = other.capacity;
    size = 0;
    threshold = other.threshold;
    loadFactor = other.loadFactor;
    hasher = other.hasher;
    buckets = DynamicArray<HashNode<K,V>*>(capacity);

    for (int i = 0; i < capacity; i++)
    {
        buckets.append(NULL);
    }

    // Deep copy all nodes
    for (int i = 0; i < other.capacity; i++)
    {
        HashNode<K,V>* cur = other.buckets[i];

        while (cur)
        {
            set(cur->key, cur->value);
            cur = cur->next;
        }
    }

    return *this;
}
template<typename K, typename V>
V& HashMap<K,V> :: get(const K& key){
    size_t index = hasher(key) % capacity;
    HashNode<K,V> *cur = find(buckets[index],key);
    if(!cur){
        throw std::out_of_range("Key not found");
    }
    return cur->value;

}
template<typename K, typename V>
HashNode<K,V>* HashMap<K, V> ::find(HashNode<K,V>* head,const K &key){
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
bool HashMap<K, V> ::exists(const K& key) {
    size_t hashValue = hasher(key);
    int bucketIndex = hashValue % capacity;

    return find(buckets[bucketIndex], key) != NULL;
}
template<typename K, typename V>
int HashMap<K, V>:: getSize() const{
    return size;
}
template<typename K, typename V>
float HashMap<K, V>:: getLoadFactor() const{
    return loadFactor;
}
