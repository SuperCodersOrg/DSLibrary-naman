# Date: 13/07/2026

---

## Session 1

**Duration:** 2 Hours

### Goal:
Refactor the `HashMap` implementation to use the previously developed generic `LinkedList` as the bucket container instead of manually managing collision chains using `HashNode` pointers.

### Work Completed:
- Replaced the bucket representation from a raw array of `HashNode*` to a `DynamicArray<LinkedList<HashNode<K,V>>>`.
- Removed manual linked-list traversal logic from `HashMap` methods.
- Added `findNode()` to `LinkedList` for searching stored `HashNode` objects.
- Implemented `HashNode::operator==()` so that bucket searching is performed by comparing only keys.
- Updated `set()`, `get()`, `remove()`, `exists()`, `rehash()`, copy constructor, and assignment operator to work with the generic linked list.
- Added `getHead()` and `getTail()` methods to `LinkedList` to support bucket traversal during copying and rehashing.

### Problems Encountered:
- Initial implementation still contained pointer-based logic from the previous design, resulting in compilation errors after changing the bucket representation.
- While integrating `LinkedList`, object traversal had to be redesigned because the list now stores `HashNode` objects instead of directly linking `HashNode` pointers.
- Several constructor and const-correctness issues appeared after introducing temporary `HashNode` objects for searching.

### Resolution:
- Shifted all bucket operations to the `LinkedList` interface instead of manipulating node pointers directly.
- Added helper methods to `LinkedList` to expose traversal and searching functionality.
- Introduced a key-only constructor for `HashNode` to simplify lookup operations.
- Corrected constructor signatures to accept `const` references where appropriate.
---

## Session 2

**Duration:** 1.5 Hours

### Goal:
Integrate the previously developed generic `DynamicArray` into the `HashMap` implementation by replacing the manually managed bucket array.

### Work Completed:
- Replaced the raw bucket array with `DynamicArray<LinkedList<HashNode<K,V>>>`.
- Updated all constructors to initialize the bucket storage using the generic `DynamicArray`.
- Modified the copy constructor and assignment operator to work with the new bucket representation.
- Refactored the rehashing logic to create a new `DynamicArray` of buckets and redistribute all existing entries.
- Eliminated direct memory management of the bucket array from `HashMap`, delegating storage management to `DynamicArray`.

### Problems Encountered:
- Existing implementations of constructors, copy constructor, assignment operator, and rehashing relied on raw arrays and manual allocation.
- Integrating `DynamicArray` required adapting bucket initialization and object copying while preserving deep copy semantics.
- Encountered issues related to object lifetime because the bucket container now stored complex objects instead of raw pointers.

### Resolution:
- Updated all bucket-related operations to use the `DynamicArray` interface instead of directly accessing raw memory.
- Ensured that bucket initialization and copying followed the semantics of the generic `DynamicArray`.
- Refactored rehashing to work with dynamically managed bucket storage while maintaining correct redistribution of elements.

---

## Session 3

**Duration:** 1.5 Hours

### Goal:
Design a generic hashing mechanism capable of supporting both primitive data types and user-defined classes.

### Work Completed:
- Implemented hash functions for primitive types including `int`, `char`, `float`, and `std::string`.
- Explored compile-time detection of a user-defined `createHash()` member function using template metaprogramming.
- Designed the `HasCreateHash` trait using `std::void_t` and `decltype`.
- Planned the integration of user-defined hashing into the generic `Hash` functor.

### Problems Encountered:
- Attempted to overload `Hash::operator()` for primitive types alongside a generic `operator()(const K&)`, which caused duplicate function signatures after template instantiation.
- Learned that generic template overloads can conflict with primitive overloads when `K` matches one of the primitive types.

### Resolution:
- Investigated the cause of template instantiation conflicts.
- Compared multiple design approaches for implementing generic hashing and identified template specialization as the preferred long-term solution for a reusable hashing framework.

---

## Learning Reflection

### Key Learnings
- Reusing previously implemented data structures significantly improves modularity and reduces duplicate logic.
- Separating responsibilities between `HashMap` and `LinkedList` leads to a cleaner and more maintainable design.
- Generic programming often requires redesigning interfaces instead of simply replacing data types.
- Const correctness plays an important role when constructing temporary objects for searching.
- Template metaprogramming techniques such as SFINAE and `std::void_t` can be used to detect the existence of member functions at compile time.
- Designing a generic hashing framework requires careful consideration of template specialization and overload resolution to avoid ambiguous instantiations.