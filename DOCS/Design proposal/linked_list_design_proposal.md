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
 
 ## Constructors 
### 1. Default Constructor
```LinkedList();```<br>
**Definition:**  
The default constructor initializes an empty doubly linked list by setting both the `head` and `tail` pointers to `nullptr` and initializing the size of the list to `0`. It ensures that the list is in a valid empty state immediately after object creation.

---

### 2. Parameterized Constructor
```LinkedList(T arr[], int n);```<br>
**Definition:**  
The parameterized constructor initializes the doubly linked list with a given collection of elements or a specified initial value. It creates the required nodes, links them using both `next` and `prev` pointers, updates the `head` and `tail` pointers accordingly, and sets the size of the list.

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

The `Node` class only requires a **parameterized constructor** to initialize the node's data and set its `next` and `prev` pointers appropriately. A default constructor may also be provided if required by the implementation.

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

We have implemented the **Rule of Three** for the doubly linked list to ensure proper management of dynamically allocated memory. The **destructor** traverses the entire linked list and deallocates every node created during execution, preventing memory leaks. The **copy constructor** performs a **deep copy** by creating new nodes for each element of the original list and correctly establishing both the `next` and `prev` links. This ensures that the copied list owns its own memory and remains completely independent of the original list. Similarly, the **copy assignment operator** first releases the memory occupied by the existing list and then performs a deep copy of the source list, duplicating all nodes while preserving the list structure and updating the `head`, `tail`, and `size` members appropriately.

## Section 3 : Complexity Estimates

1. ```insertFront(T value)```<br>
   The operation only requires creating a new node, updating its `next` pointer to the current head, updating the current head's `prev` pointer, and finally moving the `head` pointer to the new node. If the list is initially empty, both `head` and `tail` are updated to the new node. Since no traversal is required, the operation takes **O(1)** time in the best, average, and worst cases.<br>

2. ```deleteFront()```<br>
   Deleting the first node only requires moving the `head` pointer to the next node and updating the new head's `prev` pointer to `nullptr`. If the list contains only one node, both `head` and `tail` become `nullptr`. As no traversal is involved, the operation takes **O(1)** time in the best, average, and worst cases.<br>

3. ```insertIndex(int index, T value)```<br>

   **Best Case:** The operation takes **O(1)** time when the insertion index is `0` (front) or `size()` (end), as both the `head` and `tail` pointers provide direct access to these positions.<br>

   **Average Case:** The operation takes **O(n)** time because the insertion position must first be located. Since the list has both `head` and `tail` pointers, traversal starts from whichever end is closer, requiring approximately **min(index, n - index)** node visits on average. Although this reduces the traversal distance, the asymptotic complexity remains **O(n)**.<br>

   **Worst Case:** The operation takes **O(n)** time when the insertion position lies near the middle of the linked list. Even with both `head` and `tail` pointers, approximately half of the nodes must be traversed before inserting the new node, making the worst-case complexity **O(n)**.<br>

4. ```deleteIndex(int index)```<br>

   **Best Case:** The operation takes **O(1)** time when deleting the first or the last node because the `head` and `tail` pointers provide direct access.<br>

   **Average Case:** The operation takes **O(n)** time because the node to be deleted must first be located. Traversal begins from the nearer end (`head` or `tail`), visiting approximately **min(index, n - index)** nodes on average.<br>

   **Worst Case:** The operation takes **O(n)** time when the node to be deleted is located near the middle of the linked list, requiring traversal of approximately half of the nodes before deletion.<br>

5. ```search(T value)```<br>

   **Best Case:** The operation takes **O(1)** time when the required value is present in the first or the last node, depending on the direction of traversal.<br>

   **Average Case:** The operation takes **O(n)** time because, on average, approximately half of the nodes must be traversed before finding the required value. Having both `head` and `tail` pointers only reduces the number of nodes visited but does not change the asymptotic complexity.<br>

   **Worst Case:** The operation takes **O(n)** time when the required value is located near the middle of the linked list or is not present at all.<br>

6. ```size()```<br>
   A separate variable is maintained to store the current number of nodes in the linked list. Therefore, the size is returned directly without any traversal, making the operation **O(1)** in all cases.<br>

7. ```printForward()```<br>
   Printing the linked list in the forward direction requires visiting every node exactly once starting from the `head`. Therefore, the running time is directly proportional to the number of nodes, resulting in **O(N)** time complexity in all cases.<br>

8. ```printBackward()```<br>
   Since the implementation maintains a `tail` pointer and each node stores a `prev` pointer, the list can be traversed backward without any additional computation. Every node is still visited exactly once, so the operation also takes **O(N)** time in the best, average, and worst cases.<br>

## Section 4 : Design Decision

__Maintaining a `length` Variable__

In our linked list implementation, we maintain a dedicated variable named `length` to store the current number of nodes in the list. This variable is updated after every insertion and deletion operation, allowing the program to determine the size of the linked list in **O(1)** time. Without this variable, every request to find the size of the list would require traversing all the nodes from the head to the end, resulting in **O(n)** time complexity. This becomes inefficient when the size is accessed frequently, especially for large linked lists or within loops. By maintaining the `length` variable, operations such as checking whether the list is empty, validating indices, and reporting the number of elements become significantly faster. The only drawback of this approach is that the `length` variable must always be updated correctly during every insertion and deletion. If an update is missed due to a programming error, the stored size will become inconsistent with the actual number of nodes. However, this drawback is minor compared to the substantial performance improvement gained by constant-time size retrieval.

__Why We Chose a Doubly Linked List__

Our implementation uses a **Doubly Linked List** because the project requires efficient insertion and deletion operations at both the **front** and the **end** of the list. By maintaining both **head** and **tail** pointers along with **next** and **prev** pointers in every node, the list supports bidirectional traversal, allowing movement in both forward and backward directions. This enables operations such as inserting or deleting the last node in **O(1)** time without traversing the entire list.

Unlike a singly linked list, where each node stores only a **next** pointer and backward traversal is impossible, a doubly linked list stores both **next** and **prev** pointers, making navigation from either end of the list efficient. During operations such as insertion or deletion at an arbitrary position, traversal can begin from whichever end (**head** or **tail**) is closer to the target index. Although the worst-case complexity remains **O(N)**, the average number of nodes traversed is significantly reduced.

Applications such as browser history navigation, undo/redo systems, music playlists, image viewers, and trees implementations benefit from the ability to move in both directions efficiently. Since our project maintains both **head** and **tail** pointers and can take advantage of bidirectional traversal, choosing a **Doubly Linked List** provides greater flexibility, improves the efficiency of end operations, simplifies backward traversal, and results in a more versatile and maintainable implementation despite the slight increase in memory usage per node.