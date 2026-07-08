# Hashmap

A **Hash Map** is a data structure that stores data as **key–value pairs** and provides **average-case O(1)** time complexity for insertion, deletion, and searching. It uses a **hash function** to convert a key into an array index, called a **bucket**, where the corresponding value is stored. If multiple keys produce the same hash index a **collision** occurs, the hash map resolves it using techniques such as **separate chaining** or **open addressing**. Hash maps are widely used in applications requiring fast data retrieval, such as caching, symbol tables, database indexing, and frequency counting.

## Section 1 : Public Api

1. ```set(T key, Tvalue)``` : It takes a key-value pair as input and inserts it into the HashMap. If the key already exists, its corresponding value is updated with the new value. Since the user already knows the key and value they want to store, the return type is void. <br>

2. ```get(T key)``` : It searches for the given key in the HashMap and returns the value associated with it. If the key is not present, an exception (or suitable error handling based on the implementation) is performed. The return type is Value. <br>

3. ```exists(T key)``` : It checks whether the given key is present in the HashMap or not. Since the result can only be true or false, the return type is bool. <br>

4. ```remove(T key)``` : It deletes the key-value pair corresponding to the given key from the HashMap. Since its only purpose is to remove an element, the return type is void. <br>

5. ```size()``` : It returns the total number of key-value pairs currently stored in the HashMap, so the return type here is integer (size_t/int depending on the implementation). <br>

6. ```loadFactor()``` : It returns the current load factor of the HashMap, which is calculated as the ratio of the total number of stored elements to the total number of buckets. Since the result can be a decimal value, the return type is float. <br>

7. ```rehash()``` : It is an internal helper function that is automatically invoked whenever the current load factor exceeds the maximum allowed load factor. The function creates a new bucket array with a larger capacity ie 2X , recomputes the bucket index of every existing key using the new bucket count, and redistributes all key-value pairs into their appropriate buckets. After successfully transferring all elements, the old bucket array is deallocated and the internal bucket count is updated. <br>

## Constructors

__1. Default Constructor__

```HashMap();```

The default constructor initializes an empty HashMap with a predefined number of buckets (for example, 16). It allocates memory for the bucket array, initializes all bucket pointers to `nullptr`, sets the current size to `0`, and initializes the maximum load factor.


__2. Parameterized Constructor__

```HashMap(int initialBucketCount);```

The parameterized constructor allows the user to specify the initial number of buckets in the HashMap. It allocates the required bucket array, initializes every bucket to `nullptr`, and starts with an empty HashMap having a size of `0`.



__3. Copy Constructor__

```HashMap(const HashMap& other);```

The copy constructor creates a deep copy of another HashMap object. It allocates a new bucket array and copies every key-value pair into newly created nodes so that both HashMaps manage their own independent memory.


## Section 2 : Internal Representation

![Hashmap memory diagram](../images/HashMap%20memory%20diagram.jpeg)
The **HashMap** class is a data structure that stores data in the form of **key-value pairs**. Internally, it consists of an array of buckets, where each bucket points to the head of a linked list. The bucket corresponding to a key is determined using a **hash function**, and any collisions are handled using **separate chaining**, allowing multiple key-value pairs to be stored within the same bucket.<br>

In our implementation, the **Node** class and the bucket array are **internal implementation details** of the `HashMap` class. They are not intended to be accessed or manipulated directly by the user. Instead, all interactions with the HashMap are performed through its public member functions such as `set()`, `get()`, `exists()`, `remove()`, `size()`, and `loadFactor()`. This encapsulation hides the underlying hashing mechanism, collision resolution, and memory management while providing a clean, efficient, and user-friendly interface.<br>

### Rule of Three

Since the **HashMap** allocates memory dynamically for the bucket array and the linked list nodes, it must follow the **Rule of Three** to ensure proper memory management and avoid issues such as memory leaks, shallow copying, and double deletion.

__1. Destructor__

```~HashMap();```

The destructor is responsible for releasing all dynamically allocated memory. It traverses every bucket, deletes each node in the corresponding linked list, and finally deallocates the bucket array, ensuring that no memory leaks occur.


__2. Copy Constructor__

```HashMap(const HashMap& other);```

The copy constructor creates a **deep copy** of another HashMap object. It allocates a new bucket array and copies every key-value pair into newly created nodes, ensuring that both HashMap objects maintain independent copies of the data.


__3. Copy Assignment Operator__

```HashMap& operator=(const HashMap& other);```

The copy assignment operator replaces the contents of the current HashMap with those of another HashMap. It first releases the existing dynamically allocated memory, performs a deep copy of all buckets and their linked lists, and finally returns the current object to support chained assignments.

## Section 3 : Complexity Estimates

### 1. ```set(T key, T value)```<br>

**Best Case:** The operation takes **O(1)** time when the computed bucket is empty or the key already exists at the head of the bucket's linked list. The bucket is accessed directly using the hash function, and the insertion or update is completed without traversing any additional nodes.<br>

**Average Case:** The operation takes **O(1)** time assuming the hash function distributes keys uniformly across all buckets. The expected number of elements present in each bucket is equal to the **load factor**,

Since the HashMap maintains the load factor close to a constant value through rehashing, the expected length of each bucket's linked list also remains constant. Therefore, only a constant number of nodes are traversed before inserting a new key or updating an existing one.<br>

**Worst Case:** The operation takes **O(n)** time when all keys hash to the same bucket because of excessive collisions or a poor hash function. In this case, the entire linked list of the bucket must be traversed before inserting or updating the key-value pair. Although rehashing itself requires **O(n)** time, it occurs infrequently, making insertion **amortized O(1)**.<br>

---

### 2. ```get(T key)```<br>

**Best Case:** The operation takes **O(1)** time when the required key is found immediately at the beginning of the corresponding bucket or when the bucket is empty.<br>

**Average Case:** The operation takes **O(1)** because the hash function uniformly distributes keys among all buckets. As the load factor is maintained around a constant value (approximately **0.75**), each bucket contains only a constant number of elements on average. Consequently, only a few nodes need to be examined before locating the required key.<br>

**Worst Case:** The operation takes **O(n)** time when all keys collide into the same bucket, requiring traversal of the complete linked list before finding the requested key or determining that it does not exist.<br>

---

### 3. ```exists(T key)```<br>

**Best Case:** The operation takes **O(1)** time when the bucket corresponding to the key is empty or when the key is present in the first node of the linked list.<br>

**Average Case:** The operation takes **O(1)** because a good hash function distributes keys uniformly across all buckets. Since the load factor is maintained as a constant through rehashing, the expected number of nodes in each bucket remains constant, requiring only a constant number of comparisons to determine whether the key exists.<br>

**Worst Case:** The operation takes **O(n)** time when all elements are stored in the same bucket due to excessive collisions, requiring traversal of the complete linked list.<br>

---

### 4. ```remove(T key)```<br>

**Best Case:** The operation takes **O(1)** time when the key is located at the head of the bucket's linked list, allowing immediate deletion by updating the head pointer.<br>

**Average Case:** The operation takes **O(1)** because the hash function distributes keys uniformly among all buckets. Since the expected chain length is bounded by the constant load factor, only a constant number of nodes need to be traversed before locating and removing the required key.<br>

**Worst Case:** The operation takes **O(n)** time when every key hashes to the same bucket, forcing traversal of the complete linked list before deleting the required node.<br>

---

### 5. ```size()```<br>

The operation takes **O(1)** time in the best, average, and worst cases because the HashMap maintains the current number of stored key-value pairs as a member variable. Returning this value does not require any traversal, hashing, or computation.<br>

---

### 6. ```loadFactor()```<br>

The operation takes **O(1)** time in the best, average, and worst cases because the load factor is calculated directly using the stored values of the current size and the total number of buckets. Since both values are maintained by the HashMap, no traversal or hashing operation is required.

### 7. ```rehash()```<br>

**Best Case:** The operation takes **O(n)** time because every existing key-value pair must be visited, its bucket index recomputed using the new bucket count, and then inserted into the newly allocated bucket array. Even if collisions are minimal, all elements must still be processed once.<br>

**Average Case:** The operation takes **O(n)** time because each of the `n` stored key-value pairs is traversed exactly once. Assuming a good hash function distributes keys uniformly, recomputing the bucket index and inserting each node into the new bucket array takes **O(1)** time on average. Since this constant-time work is performed for every element, the total complexity becomes **O(n)**.<br>

**Worst Case:** The operation takes **O(n)** time because every key-value pair must be rehashed and transferred to the new bucket array. Even if excessive collisions occur, each existing node is still processed exactly once during rehashing. Therefore, the overall complexity remains **O(n)**.<br>




## Section 4 : Design Decision

# Design Decisions

---

## Decision 1 : Initial Bucket Size

### Options Considered

1. Start with a very small bucket count (e.g., 1 or 2).
2. Start with a fixed medium-sized bucket count (e.g., 8 or 16).
3. Allow the user to specify the initial bucket count.

### Decision Taken

The HashMap is initialized with a **small power-of-two bucket count** (e.g., 8).

### Reason

A small initial bucket count minimizes memory consumption when only a few elements are stored. As the number of elements increases, the HashMap automatically expands by rehashing. Choosing a power-of-two bucket count also simplifies bucket index computation and provides efficient resizing while maintaining good cache locality.

---

## Decision 2 : Choosing the Maximum Load Factor

### Options Considered

1. Low load factor (0.5)
2. Standard load factor (0.75)
3. High load factor (1.0 or above)

### Decision Taken

The maximum load factor is set to **0.75**.

### Reason

A load factor of 0.75 provides a good balance between memory utilization and performance. A lower load factor results in fewer collisions but wastes more memory due to a larger number of buckets. A higher load factor conserves memory but increases collisions, leading to longer linked lists and slower operations. A threshold of **0.75** is widely adopted in industry because it offers efficient average-case performance while keeping memory overhead reasonable.

---

## Decision 3 : Collision Resolution Technique

### Options Considered

1. Open Addressing
   - Linear Probing
   - Quadratic Probing
   - Double Hashing

2. Separate Chaining

### Decision Taken

The HashMap uses **Separate Chaining**.

### Reason

Separate Chaining is preferred because it is simple to implement, handles collisions naturally using linked lists, supports easy deletion, performs well even when collisions occur, and allows code reuse through linked lists. Although it uses a little extra memory for pointers, it provides a cleaner and more maintainable implementation than open addressing.

---

## Decision 4 : Hash Function Design

### Options Considered

1. Hardcode hash functions for every supported data type.
2. Use function overloading for primitive and custom types.
3. Design a generic `Hash` class that computes hash values.

### Decision Taken

A separate **`Hash`** class has been implemented, containing a **`createHash()`** function responsible for generating the hash value of a given key.

For primitive data types, predefined hashing logic is provided. For user-defined classes, the user specifies which data members should participate in hashing by implementing their own `createHash()` function. Additionally, the user must overload the **`==` operator** so that two keys can be correctly compared during searching, insertion, updating, and deletion.

### Reason

The HashMap is designed to work with any data type, whether it is a primitive type like int or a user-defined class like Student or Employee. Since the HashMap does not know the internal structure of a user-defined class, it cannot decide which data members should be used to generate the hash value. For example, in a Student class, one programmer may want to hash only the rollNo, while another may want to hash both rollNo and name. Therefore, the responsibility of generating the hash value is given to the user through the Hash class.

Similarly, when two keys are stored in the same bucket due to a collision, the HashMap must compare them to determine whether they represent the same object. Since the HashMap does not know how two user-defined objects should be compared, the user is required to overload the equality operator (==) in their class. This allows the HashMap to correctly identify matching keys during searching, insertion, updating, and deletion.




