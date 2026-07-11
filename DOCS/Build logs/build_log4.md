### Date: 09/07/2026

---

## Session 1

**Duration:** 4 Hours

### Goal:
Complete the implementation of the generic `DynamicArray<T>` by incorporating proper memory management, copy semantics, exception handling, and documentation. Begin the implementation of the generic `LinkedList<T>` by designing and implementing its core operations.

---

### Work Completed

#### DynamicArray<T>

Successfully completed the implementation of the generic `DynamicArray<T>` class.

The following utility functions were implemented:

- `nextPowerOf2(int n)`
- `growthFactor(int currentCapacity)`
- `resize()`

These functions ensure that the array dynamically grows according to the current memory footprint instead of always doubling in size.

Implemented all core constructors and special member functions:

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Copy Assignment Operator (Rule of Three)

Implemented the following public operations:

- `append(T value)`
- `insert(int index, T value)`
- `remove(int index)`
- `get(int index)`
- `operator[]`
- `getSize()`
- `getCapacity()`

Added exception handling using:

- `std::bad_alloc`
- `std::out_of_range`

to make the implementation safer and closer to STL behaviour.

---

### Memory Management Learning

A significant portion of today's work focused on understanding manual object lifetime management.

Since the project restricts the use of `new` for memory allocation, memory was allocated using `malloc()`. During implementation it became clear that `malloc()` only reserves raw memory and does not construct objects.

To correctly support generic data types (`T`), placement new was introduced to explicitly construct objects inside the allocated memory.

Similarly, before releasing memory using `free()`, destructors are explicitly invoked to correctly destroy every constructed object.

This helped in understanding the complete lifecycle of an object:

- Raw memory allocation
- Object construction
- Object destruction
- Memory deallocation

which is one of the fundamental implementation techniques used by containers such as `std::vector`.

---

### Rule of Three

Implemented deep copy semantics for `DynamicArray<T>`.

While implementing the copy assignment operator, it became clear why previously allocated memory must first be released before assigning new memory to the object.

Also learned the importance of returning `*this` from the assignment operator to support chained assignments.

---

### Operator Overloading

Implemented:

- `operator[]`

Studied the implementation requirements for overloading the stream insertion operator (`<<`) and understood why it is implemented as a non-member friend function rather than a member function.

Also explored the difference between returning:

- `T`
- `T&`

and identified situations where returning a reference is safe and where it leads to dangling references.

---

### Template Implementation

Studied the reason template implementations cannot be placed inside a normal `.cpp` file.

Learned how template implementation files (`.tpp`) work and why they are included from the header instead of being compiled separately.

Also organized the project into:

- Header (`.h`)
- Template implementation (`.tpp`)

to improve readability while keeping template definitions visible to the compiler.

---

## Session 2

**Duration:** 3 Hours

### Goal:
Begin implementation of the generic `LinkedList<T>`.

---

### Work Completed

Designed and implemented the following operations:

- `insertBack()`
- `deleteFront()`
- `deleteBack()`
- `search()`
- `printForward()`
- `printBackward()`

Each method was documented with:

- Definition
- Working
- Time Complexity
- Space Complexity

---

### Memory Management in Linked List

The linked list follows the same allocation strategy as the dynamic array.

Each node is allocated using:

```cpp
Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
new (node) Node<T>(value);
```

and deallocated using:

```cpp
node->~Node<T>();
free(node);
```

This maintained consistency throughout the entire library.

---

### Major Learnings

During implementation several important C++ concepts became much clearer:

- Difference between raw memory allocation and object construction.
- Purpose of placement new.
- Explicit destructor invocation.
- Difference between `free()` and `delete`.
- Why `operator[]` returns `T&`.
- Why deletion functions must return `T` instead of `T&`.
- Importance of avoiding dangling references.
- Correct implementation of the Rule of Three.
- Template compilation model.
- Purpose of `.tpp` files.
- Function of include guards (`#ifndef`, `#define`, `#endif`).
- Use of `std::bad_alloc` and `std::out_of_range`.

---

### Challenges Faced

Initially attempted to use normal assignment while copying objects into memory allocated using `malloc()`. After studying object lifetime management, realized that objects must first be explicitly constructed using placement new.

Another challenge was understanding why functions such as `deleteFront()` and `remove()` cannot return references. Through memory diagrams and pointer analysis, it became clear that references to destroyed objects result in dangling references and undefined behaviour.

Also encountered several issues while overloading the stream insertion operator (`<<`) for templates, leading to a deeper understanding of friend function templates and template compilation.

---

### Reflection

Today's implementation significantly improved my understanding of low-level memory management in C++. Rather than relying on the language's automatic facilities, I manually managed object construction, destruction, copying, and memory allocation.

Implementing these data structures from scratch provided insight into many of the mechanisms hidden behind STL containers. It also reinforced the importance of resource management, deep copying, and template design while building reusable generic libraries.