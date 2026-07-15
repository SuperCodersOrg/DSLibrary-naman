# Linked List

A **Doubly Linked List (DLL)** is a linear dynamic data structure in which each node contains three components: a **data** field, a pointer to the **next** node, and a pointer to the **previous** node. Unlike a singly linked list, a doubly linked list supports **bidirectional traversal**, allowing movement in both forward and backward directions. It enables efficient insertion and deletion of nodes at both the beginning and the end of the list without requiring traversal, provided that both **head** and **tail** pointers are maintained. Although each node requires additional memory to store the extra `prev` pointer, a doubly linked list offers greater flexibility and is widely used in applications such as browser history navigation, undo/redo systems, music playlists, image viewers, and LRU cache implementations.

## Section 1 : Public Api

1. ```insertFront(T value)``` : It takes the value as input and insert it to the front of linked list as the user knows the location there is no need toreturn anything i.e. void <br>
2. ```deleteFront()``` : it will delete the node from the start and in my implementation I have decided to return the element that is deleted so i will return T as return type <br>
3. ```insertIndex(int index , T value)``` : Here the user will enter the index at which they want to insert the value and the return type is also void here too <br>
4. ```search(T value)``` : it will return whether the value is present in linked list or not so the return type is bool in here <br>
5. ```size()``` : it will return the number of elements present in the linked list so the return type here is integer <br>
6. ```printForeward()``` : it will just traverse the array and print the values so the return type is void here 
7. ```printBackward()``` : it will just traverse the array and print the values in reverse order similar to ```printForeward()``` so the return type here also is void  
8. ```insertBack(T value)```<br>
   it will take a value of type `T` as input and insert a new node containing that value at the end of the linked list. If the list is empty, the new node becomes both the `head` and `tail`; otherwise, it is linked after the current `tail`, and the `tail` pointer is updated to reference the newly inserted node.
9. ```deleteBack()```<br>
it will not take any parameter and will remove the last node from the linked list. If the list contains only one node, both the `head` and `tail` pointers are updated to `nullptr`; otherwise, the `tail` pointer is moved to the previous node, the last node is deallocated, and the new `tail`'s `next` pointer is set to `NULL`.

10. `getHead()`

Returns a pointer to the first node of the linked list. This function is primarily intended for internal use by other data structures (such as `HashMap`) that need to traverse the linked list directly. If the list is empty, it returns `nullptr`.

Return Type: `Node<T>*`

---

11. `getTail()`

Returns a pointer to the last node of the linked list. Similar to `getHead()`, this function is mainly provided for internal use by other data structures.

Return Type: `Node<T>*`

---

12. `findNode(const T& value)`

Searches the linked list for a node containing the specified value. If the value exists, the function returns a pointer to the corresponding node; otherwise, it returns `nullptr`.

Return Type: `Node<T>*`

---

13. `remove(const T& value)`

Searches for the first occurrence of the specified value and removes it from the linked list. The function returns `true` if the element was found and removed successfully; otherwise, it returns `false`.

Return Type: `bool`

 
 ## Constructors 
### 1. Default Constructor
```LinkedList();```<br>
**Definition:**  
The default constructor initializes an empty doubly linked list by setting both the `head` and `tail` pointers to `nullptr` and initializing the size of the list to `0`. It ensures that the list is in a valid empty state immediately after object creation.

---

### Parameterized Constructor

```cpp
LinkedList(T arr[], int n);
```

This constructor initializes the linked list using the elements of an existing array. It creates one node for each array element while preserving the original order. Each newly created node is linked using both the `next` and `prev` pointers, and the `head`, `tail`, and `length` members are updated accordingly.

---

### 3. Copy Constructor
```LinkedList(const LinkedList& other);```<br>
**Definition:**  
The copy constructor creates a deep copy of an existing doubly linked list. Instead of copying the memory addresses of the nodes, it allocates new nodes, copies the data from the source list, reconstructs all `next` and `prev` links, and initializes the new list with its own `head`, `tail`, and size. This ensures that modifications to one list do not affect the other.

---


## Section 2 : Internal Representation
![Memory Diagram](../images/LinkedListMemoryDiagram.jpeg)
## Node Class Implementation

The **Node** class is the fundamental building block of the **Doubly Linked List**. Each node stores a single data element along with two pointers: one pointing to the **next** node and the other pointing to the **previous** node. These pointers enable bidirectional traversal, allowing the list to be traversed in both forward and backward directions.

In our implementation, the **Node** class is an **internal implementation detail** of the `DoublyLinkedList` class. It is not intended to be accessed or manipulated directly by the user. Instead, all interactions with the linked list are performed through the public member functions of the `DoublyLinkedList` class, such as insertion, deletion, searching, and traversal. This encapsulation hides the underlying implementation details and provides a clean and user-friendly interface.

### Constructors of the Node Class

The `Node` class only requires **default ** and **parameterized constructor** to initialize the node's data and set its `next` and `prev` pointers appropriately. 

## Why the Node Class Does Not Implement the Rule of Three

The **Rule of Three** is **not implemented** for the `Node` class because nodes are never created, copied, assigned, or destroyed directly by the user. Every node is dynamically allocated and managed exclusively by the `LinkedList` class.

When a linked list is copied, the implementation does **not** copy individual `Node` objects using a node copy constructor. Instead, the `LinkedList` copy constructor performs a **deep copy** by creating entirely new nodes and copying only the stored data while reconstructing the `next` and `prev` links. This ensures that the copied list owns its own memory and remains completely independent of the original list.

Similarly, the destructor of the `LinkedList` class is responsible for traversing the list and deallocating every node, preventing memory leaks. Since the lifetime of every node is fully controlled by the linked list itself, implementing a copy constructor, copy assignment operator, or destructor for the `Node` class would provide no additional benefit and would unnecessarily complicate the implementation.

Therefore, the **Rule of Three** is implemented only for the `LinkedList` class, which owns and manages all dynamically allocated nodes, while the `Node` class remains a lightweight internal structure used solely to represent individual elements of the list.

The LinkedList object itself is created in memory and contains three data members: head, tail, and length. 
The head pointer stores the address of the first node, the tail pointer stores the address of the last node, and length stores the total number 
of nodes in the list. The actual nodes are not stored inside the LinkedList object; instead, they are dynamically allocated on the heap. 
Each node contains a data field (value) , a pointer (next) and a pointer (prev) that stores the address of the next node. Starting from the head, we can traverse 
the entire list by repeatedly following the next pointers until we reach a node whose next is NULL, which is the tail node. 
During insertion and deletion, only these pointers are updated while the nodes themselves remain dynamically allocated or are freed using 
free when no longer needed.
### Rule of Three 

# Rule of Three

The **Rule of Three** is a fundamental principle in C++ that states:

> If a class manually manages a resource such as dynamically allocated memory, it should explicitly implement the following three special member functions:
>
> - Destructor
> - Copy Constructor
> - Copy Assignment Operator

The `LinkedList<T>` class dynamically allocates memory for its nodes using `malloc()` and constructs them using placement `new`. Since the linked list owns these nodes, it is responsible for correctly copying and destroying them. The compiler-generated versions of these functions perform only shallow copying, which is not suitable for a linked list.

---

# Why is the Rule of Three Required?

The linked list stores its elements using dynamically allocated nodes.

```cpp
Node<T>* head;
Node<T>* tail;
int length;
```

Both `head` and `tail` point to memory allocated on the heap.

If the compiler-generated copy constructor or assignment operator is used, only these pointer values are copied.

Both lists will be pointing to the same location.

When one list is destroyed, the nodes are deallocated. The second list still contains pointers to the same memory, resulting in dangling pointers. When the second list is destroyed, it attempts to free the same memory again, causing **double-free errors** and undefined behavior.

To avoid these problems, the linked list must implement the Rule of Three and perform **deep copying**.

---

# 1. Destructor

## Purpose

The destructor releases every node owned by the linked list before the object goes out of scope.

### Responsibilities

- Traverse the entire list.
- Call the destructor of every node.
- Release the memory occupied by each node.
- Reset the member variables.

### Why is it Required?

Every node is allocated dynamically.

```cpp
Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
new (node) Node<T>(value);
```

Since the nodes are constructed using placement `new`, they must also be destroyed manually before calling `free()`.

Without the destructor:

- Memory allocated for every node remains allocated.
- Stored objects are never destroyed.
- Memory leaks occur.

---

# 2. Copy Constructor

## Purpose

The copy constructor creates a completely independent copy of an existing linked list.

Example:

```cpp
LinkedList<int> list2(list1);
```

The new list should contain new nodes storing the same values.

### Responsibilities

- Initialize an empty list.
- Traverse the source list.
- Create a new node for every element.
- Preserve the order of elements.

### Why is it Required?

The compiler-generated copy constructor performs a shallow copy.

```
Compiler Copy

list1

10 <-> 20 <-> 30

list2

10 <-> 20 <-> 30
```

Both lists share the same nodes.

A proper copy constructor performs a deep copy.

```
Deep Copy

list1

10 <-> 20 <-> 30

list2

10 <-> 20 <-> 30
```

Although the values are identical, every node is newly allocated, making both lists completely independent.

---

# 3. Copy Assignment Operator

## Purpose

The copy assignment operator replaces the contents of one existing linked list with another.

Example:

```cpp
list2 = list1;
```

Unlike the copy constructor, both objects already exist before the assignment.

### Responsibilities

- Detect self-assignment.
- Destroy the existing list.
- Release previously allocated memory.
- Deep copy every node from the source list.
- Return the current object.

### Why is it Required?

If the compiler-generated assignment operator is used,

```
Before Assignment

list1

10 <-> 20 <-> 30

list2

1 <-> 2 <-> 3
```

After assignment,

```
list1

10 <-> 20 <-> 30

list2

10 <-> 20 <-> 30
```

Both lists point to the same nodes.

The original nodes of `list2` are leaked, and both objects now attempt to delete the same memory during destruction.

A custom assignment operator first destroys the existing list and then creates a deep copy of the source list.



## Section 3 : Complexity Estimates

## Time Complexity Analysis

### 1. `insertFront(T value)`

- **Best Case:** **O(1)**  
  When the list is empty, the new node becomes both the `head` and the `tail`. Only a few pointer updates are performed.

- **Average Case:** **O(1)**  
  Regardless of the number of nodes present, insertion at the front only requires creating a new node and updating a constant number of pointers.

- **Worst Case:** **O(1)**  
  Even for a very large linked list, no traversal is required. The operation always performs a fixed number of pointer assignments.

**Reason:**  
The operation directly inserts the new node before the current `head`. Since only the `head`, the new node, and at most one existing node are modified, the execution time remains constant.

---

### 2. `deleteFront()`

- **Best Case:** **O(1)**  
  When the list contains only one node, deleting it simply resets both `head` and `tail` to `NULL`.

- **Average Case:** **O(1)**  
  Deleting the first node only requires updating the `head` pointer and adjusting the `prev` pointer of the new first node.

- **Worst Case:** **O(1)**  
  Even in the largest linked list, the first node is removed without traversing the list.

**Reason:**  
Only a constant number of pointer updates and memory deallocation operations are performed.

---

### 3. `insert(int index, T value)`

- **Best Case:** **O(1)**  
  When `index == 0` or `index == size()`, the operation becomes either `insertFront()` or `insertBack()`, both of which execute in constant time.

- **Average Case:** **O(N)**  
  The insertion position must first be located by traversing the linked list. On average, approximately half of the nodes are visited before inserting the new node.

- **Worst Case:** **O(N)**  
  When the insertion index lies near the middle of the linked list, approximately half of the nodes must be traversed before the insertion can be performed.

**Reason:**  
Although the actual insertion only modifies a few pointers, locating the insertion position dominates the running time.

---

### 4. `search(T value)`

- **Best Case:** **O(1)**  
  The required value is found in the first node.

- **Average Case:** **O(N)**  
  we have to traverse all the nodes 

- **Worst Case:** **O(N)**  
  The required value is located in the last node or is not present in the list, requiring traversal of every node.

**Reason:**  
Since linked lists do not provide direct indexing, elements must be searched sequentially.

---

### 5. `size()`

- **Best Case:** **O(1)**  
  The stored `length` variable is returned directly.

- **Average Case:** **O(1)**  
  The number of nodes does not affect the execution time.

- **Worst Case:** **O(1)**  
  Even for a very large linked list, the function simply returns the stored size.

**Reason:**  
The linked list maintains the current number of nodes using the `length` member variable.

---

### 6. `printForward()`

- **Best Case:** **O(N)**  
  Every node must be visited and printed exactly once.

- **Average Case:** **O(N)**  
  The entire linked list is traversed from `head` to `tail`.

- **Worst Case:** **O(N)**  
  Regardless of the data stored, every node is printed exactly once.

**Reason:**  
Printing requires visiting every node of the linked list.

---

### 7. `printBackward()`

- **Best Case:** **O(N)**  
  Every node is visited once while traversing from `tail` to `head`.

- **Average Case:** **O(N)**  
  The operation traverses the entire linked list in reverse order.

- **Worst Case:** **O(N)**  
  All nodes are printed exactly once regardless of the list contents.

**Reason:**  
The `tail` pointer and each node's `prev` pointer allow reverse traversal, but every node must still be visited.

---

### 8. `insertBack(T value)`

- **Best Case:** **O(1)**  
  When the list is empty, the new node becomes both the `head` and `tail`.

- **Average Case:** **O(1)**  
  The `tail` pointer provides direct access to the last node, allowing insertion without traversal.

- **Worst Case:** **O(1)**  
  Even for a very large linked list, insertion only updates a constant number of pointers.

**Reason:**  
Maintaining a `tail` pointer eliminates the need to traverse the list before inserting at the end.

---

### 9. `deleteBack()`

- **Best Case:** **O(1)**  
  When only one node exists, deleting it simply resets `head` and `tail`.

- **Average Case:** **O(1)**  
  The `tail` pointer directly identifies the last node, allowing it to be removed immediately.

- **Worst Case:** **O(1)**  
  Regardless of the list size, deleting the last node only requires updating a constant number of pointers.

**Reason:**  
Since every node stores a `prev` pointer and the linked list maintains a `tail` pointer, the last node can be removed without traversing the list.

### 10. findNode(const T& value)

- Best Case: **O(1)** – The required node is the head node.
- Average Case: **O(N)** – Approximately half the list is traversed.
- Worst Case: **O(N)** – The value is at the end or does not exist.

Reason:
The function performs a linear search through the linked list until the desired node is found.

### 11. remove(const T& value)

- Best Case: **O(1)** – The element to be removed is the head node.
- Average Case: **O(N)** – Approximately half the nodes are traversed before the element is found.
- Worst Case: **O(N)** – The element is the last node or is not present.

Reason:
The dominant operation is locating the node. Once found, updating the surrounding pointers requires only constant time.

### 12. getHead()

- Best Case: **O(1)**
- Average Case: **O(1)**
- Worst Case: **O(1)**

Reason:
The function simply returns the stored `head` pointer.

### 13. getTail()

- Best Case: **O(1)**
- Average Case: **O(1)**
- Worst Case: **O(1)**

Reason:
The function simply returns the stored `tail` pointer.


## Section 4 : Design Decision

## 1. Choice of Doubly Linked List

The first design decision was selecting the type of linked list to implement. After comparing singly and doubly linked lists, a **Doubly Linked List** was chosen.

### Reasoning

A doubly linked list stores two pointers in every node:

- `next` – points to the next node.
- `prev` – points to the previous node.

Although this requires one additional pointer per node compared to a singly linked list, it offers greater flexibility and improves the efficiency of several operations.

### Why Doubly Linked List?

- Supports traversal in both forward and backward directions.
- Enables **O(1)** deletion of the last node using the `prev` pointer.
- Makes insertion and deletion easier when the target node is already known.
- Better suited for applications such as browser history, undo/redo systems, music playlists, and navigation systems.
- Eliminates the need to traverse from the beginning whenever backward movement is required.

The additional memory required for storing the `prev` pointer was considered an acceptable trade-off for the improved functionality and ease of implementation.

---

# 2. Maintaining Both `head` and `tail` Pointers

Instead of storing only a pointer to the first node, the implementation maintains pointers to both the first and last nodes.

```cpp
Node<T>* head;
Node<T>* tail;
```

### Reasoning

If only a `head` pointer were maintained, every insertion or deletion at the end of the list would require traversing all the nodes to locate the last node.

For example:

```
Head

10 <-> 20 <-> 30 <-> 40
```

To insert `50` at the end, the entire list would have to be traversed.

Time Complexity:

```
O(N)
```

By maintaining a `tail` pointer,

```
Head                    Tail

10 <-> 20 <-> 30 <-> 40
```

the last node is immediately accessible.

### Benefits

- `insertBack()` executes in **O(1)** time.
- `deleteBack()` executes in **O(1)** time.
- Efficient access to both ends of the linked list.
- Simplifies implementation of operations involving the last node.

The extra memory required for storing one additional pointer is very small compared to the performance improvement achieved.

---

# 3. Generic Implementation Using Templates

The linked list was implemented as a template class.

```cpp
template<typename T>
class LinkedList
```

### Reasoning

Using templates allows the same implementation to work with any data type without rewriting the linked list for each type.

Examples:

```cpp
LinkedList<int>

LinkedList<double>

LinkedList<char>

LinkedList<string>

LinkedList<Student>
```

### Benefits

- Code reusability.
- Compile-time type safety.
- Eliminates duplicate implementations for different data types.
- Supports both primitive and user-defined data types.
- Makes the linked list suitable for use as a generic data structure library.

This design follows the principles of generic programming by separating the data structure implementation from the type of data it stores.

---

# 4. Maintaining a Separate Size Variable

The implementation maintains the current number of nodes using a dedicated member variable.

```cpp
int length;
```

### Reasoning

An alternative approach would be to calculate the size by traversing the entire linked list whenever `size()` is called.

For example,

```
Head

10 <-> 20 <-> 30 <-> 40 <-> 50
```

To determine the size, every node would have to be visited.

Time Complexity:

```
O(N)
```

Instead, the `length` variable is updated after every insertion and deletion.

```
Insertion  → length++

Deletion   → length--
```

As a result,

```cpp
size()
```

simply returns the stored value.

### Benefits

- `size()` executes in **O(1)** time.
- Eliminates unnecessary traversal.
- Improves performance when the size is requested frequently.
- Keeps the implementation efficient even for very large linked lists.

The small amount of additional memory required for storing one integer is negligible compared to the significant improvement in retrieval time.

# 5. Returning Node Pointers for Internal Integration

The linked list exposes `getHead()`, `getTail()`, and `findNode()` so that other data structures can traverse or manipulate the list efficiently without duplicating traversal logic.

### Reasoning

The `LinkedList` serves as an internal building block for other data structures, most notably the `HashMap` implementation that uses separate chaining to resolve collisions. Returning pointers to nodes enables the `HashMap` to iterate through bucket lists, update values, and perform efficient searches while keeping traversal logic encapsulated within the linked list.

Although exposing node pointers slightly increases coupling, these methods are intended primarily for use by other data structures within the same library rather than by end users. This approach improves code reuse and avoids unnecessary duplication of traversal algorithms.