#include "hashMap.h"
#include "linkedList.h"
#include "dynamicArray.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <type_traits>
#include <utility>


template<typename, typename = void>
struct HasCreateHash : std::false_type
{
};


template<typename T>
struct HasCreateHash<
    T,
    std::void_t<
        decltype(std::declval<const T>().createHash())
    >
> : std::true_type
{
};

template<typename K,typename V>
HashNode<K,V>::HashNode(){
    key = K();
    value = V();
}
template<typename K,typename V>
HashNode<K,V>::HashNode(const K &key,const V &value){
    this->key = key;
    this->value = value;
    
}
template<typename K,typename V>
HashNode<K,V>::HashNode(const K &key){
    this->key = key;
    this->value = V();
    
}
template<typename K, typename V>
bool HashNode<K,V>::operator==(const HashNode<K,V>& other) const
{
    return key == other.key;
}
template<typename K,typename V>
HashNode<K,V>::~HashNode(){

}

size_t Hash<int>::operator()(const int& key) const{
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

    DynamicArray<LinkedList<HashNode<K,V>>> newBuckets(capacity);

    for (int i = 0; i < capacity; i++)
    {
        newBuckets.append(LinkedList<HashNode<K,V>>());
    }

    for (int i = 0; i < oldCapacity; i++)
    {
        Node<HashNode<K,V>>* cur = buckets[i].getHead();

        while (cur)
        {
            int index = hasher(cur->value.key) % capacity;

            newBuckets[index].insertFront(cur->value);

            cur = cur->next;
        }
    }

    buckets = newBuckets;

    loadFactor = static_cast<float>(size) / capacity;
}

size_t Hash<char>::operator()(const char& key) const
    {
        uint32_t x = static_cast<unsigned char>(key);
        x *= 2654435761u;
        return static_cast<size_t>(x);
    }

size_t Hash<float>::operator()(const float& key) const
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

size_t Hash<std::string>::operator()(const std::string& key) const
{
    uint64_t hash = 14695981039346656037ULL; // FNV offset basis

    for (char c : key)
    {
        hash ^= static_cast<unsigned char>(c);
        hash *= 1099511628211ULL;            // FNV prime
    }

    return static_cast<size_t>(hash);
}
template<typename K>
size_t Hash<K>::operator()(const K& obj) const{
    static_assert(
        HasCreateHash<K>::value,
        "User-defined type must implement createHash()"
    );
    return obj.createHash();
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
void HashMap<K,V>::set(const K& key, const V& value)
{
    int destinationBucket = hasher(key) % capacity;

    HashNode<K,V> temp(key, value);

    Node<HashNode<K,V>>* location =
        buckets[destinationBucket].findNode(temp);

    if (location)
    {
        location->value.value = value;
        return;
    }

    buckets[destinationBucket].insertFront(temp);

    size++;
    loadFactor = static_cast<float>(size) / capacity;

    if (loadFactor > threshold)
    {
        rehash();
    }
}
template<typename K, typename V>
void HashMap<K,V>::remove(const K& key)
{
    int index = hasher(key) % capacity;

    HashNode<K,V> temp(key,V());

    if (!buckets[index].remove(temp))
    {
        std::cout << "Key Does not exist";
        return;
    }

    size--;
    loadFactor = static_cast<float>(size) / capacity;
}
template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other)
{
    if (this == &other)
    {
        return *this;
    }

    capacity = other.capacity;
    size = 0;
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

    return *this;
}
template<typename K, typename V>
V& HashMap<K,V>::get(const K& key)
{
    int index = hasher(key) % capacity;

    HashNode<K,V> temp(key);

    Node<HashNode<K,V>>* node =
        buckets[index].findNode(temp);

    if (node == NULL)
    {
        throw std::out_of_range("Key not found");
    }

    return node->value.value;
}
template<typename K, typename V>
bool HashMap<K, V>::exists(const K& key)
{
    int bucketIndex = hasher(key) % capacity;
    HashNode<K,V> temp(key, V());
    return buckets[bucketIndex].findNode(temp) != NULL;
}
template<typename K, typename V>
int HashMap<K, V>:: getSize() const{
    return size;
}
template<typename K, typename V>
float HashMap<K, V>:: getLoadFactor() const{
    return loadFactor;
}
