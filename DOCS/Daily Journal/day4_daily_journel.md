# Daily Design Journal
### Date: 09/07/2026

---

## Section 1 — Specific Bug

### Bug 1

**Compiler Error:**

```text
warning: friend declaration 'std::ostream& operator<<(std::ostream&, const DynamicArray<T>&)'
declares a non-template function

error: template-id 'operator<< <>' in declaration of primary template

undefined reference to `operator<<(std::ostream&, DynamicArray<int> const&)'
```

### Cause

While implementing the overloaded stream insertion operator (`operator<<`) for the generic `DynamicArray<T>`, I initially declared the friend function incorrectly inside the template class. The compiler interpreted it as a normal friend function instead of a function template, resulting in template instantiation and linker errors.

### Resolution

I studied how template friend functions are declared and implemented. After correcting the declaration and matching it with the implementation outside the class, the operator was successfully overloaded, But then I realized that overloading << operator is not neccesary for our implementation so I removed it from consideration.

---

## Section 2 — Failed Attempt

While implementing the generic `DynamicArray`, I initially copied elements into the newly allocated memory using direct assignment.

```cpp
newPtr[i] = ptr[i];
```

This approach appeared to work for primitive data types but failed conceptually for generic objects because the destination memory allocated using `malloc()` did not contain constructed objects.

After studying object lifetime management, I understood that `malloc()` only allocates raw memory and does not invoke constructors. I modified the implementation to construct every object explicitly using placement new.

```cpp
new (&newPtr[i]) T(ptr[i]);
```

Similarly, before releasing memory, every constructed object was explicitly destroyed using its destructor before calling `free()`.

This corrected the implementation and made the dynamic array capable of handling user-defined types safely.

---

## Section 3 — Memory Diagram

### Topic: Dynamic Array Resize using Placement New

```
Before Resize

Capacity = 4

+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
        ptr

                │
                ▼

Allocate larger raw memory

+----+----+----+----+----+----+----+----+
|    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+
                    newPtr

                │
                ▼

Construct objects using Placement New

+----+----+----+----+----+----+----+----+
| 10 | 20 | 30 | 40 |    |    |    |    |
+----+----+----+----+----+----+----+----+

                │
                ▼

Destroy old objects

ptr[i].~T()

                │
                ▼

free(ptr)

                │
                ▼

ptr = newPtr
capacity = newCapacity
```
---

## Section 4 — Code Reference

**Commit Hash:**  `44e1177c09e01d5421980a9e85bf1285124d3233`
**Commit Hash:**  `eeb246c7c132e5f96d6160166b0991e4b4f3e29b`

**Files Modified:**

- `DynamicArray.h`
- `DynamicArray.tpp`
- `LinkedList.h`
- `LinkedList.tpp`

**Major Functions Implemented**

### Dynamic Array

- `nextPowerOf2()`
- `growthFactor()`
- `resize()`
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Copy Assignment Operator
- `append()`
- `insert()`
- `remove()`
- `get()`
- `operator[]`
- `getSize()`
- `getCapacity()`

### Linked List

- `insertBack()`
- `deleteFront()`
- `deleteBack()`
- `search()`
- `printForward()`
- `printBackward()`

---

## Section 5 — Learning Reflection

Today's implementation changed my understanding of how generic containers actually manage memory internally.

Before today, I believed that allocating memory using `malloc()` was sufficient to store objects. During the implementation of the generic `DynamicArray<T>`, I learned that memory allocation and object construction are completely different operations. `malloc()` only reserves raw memory, whereas placement new constructs an object in that memory. Likewise, before releasing the allocated memory, each constructed object must be explicitly destroyed by invoking its destructor.

Another important realization was the difference between returning an object by value and returning it by reference. While implementing deletion operations for the linked list, I initially considered returning a reference to the deleted element. After tracing the object's lifetime, I understood that deleting the node destroys the stored object, making any reference to it invalid. Returning the value instead safely copies the data before the object is destroyed.

I also developed a much better understanding of C++ template compilation. Initially, I tried implementing template functions similarly to normal classes using a `.cpp` file. After encountering compilation and linker errors, I learned why template implementations must remain visible to the compiler and why `.tpp` files are commonly used to separate implementations while still allowing template instantiation.

Overall, today's work helped me move beyond simply using C++ containers and gave me practical insight into how containers such as `std::vector` and `std::list` internally manage memory, object lifetimes, copying, and template instantiation.