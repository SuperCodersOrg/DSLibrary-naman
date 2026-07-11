### Date: 10/07/2026

---

## Session 1

**Duration:** 2 Hours

### Goal

Design and implement hash functions for primitive key types in the generic `HashMap`.

### Work Completed

* Implemented a specialized hash function for `char` keys using multiplicative hashing.
* Explored and compared hashing techniques for `int`, `char`, and `float` data types.
* Studied how floating-point values should be converted into their binary representation before hashing.
* Finalized the structure of the `Hash<T>` functor so that different data types can provide their own hashing logic through template specialization.

### Problem Encountered

It was initially unclear whether all primitive data types should share a single hash function or whether each type required its own implementation for better distribution.

### Solution

Decided to use template specialization for the `Hash<T>` functor, allowing every supported data type to implement an independent hashing strategy while preserving a common interface.

### Key Learning

A well-designed generic library should expose a common interface while allowing specialized implementations internally. This improves both flexibility and hashing quality.

---

## Session 2

**Duration:** 1.5 Hours

### Goal

Finalize the initial design decisions for the `HashMap`.

### Work Completed

* Chose an initial bucket capacity of **8**.
* Compared the memory allocation strategy of dynamic arrays with that of hash maps.
* Studied why hash maps generally benefit from a larger initial capacity than dynamic arrays.
* Reviewed when additional hash function specializations would be required for future key types.

### Problem Encountered

There was uncertainty regarding the choice of the initial bucket capacity and how it would affect memory usage and collision frequency.

### Solution

Selected an initial capacity of **8** as a balanced starting point, providing reasonable memory usage while helping reduce collisions during the early stages of insertion.

### Key Learning

The initial bucket count is an important design decision because it influences both memory consumption and the likelihood of collisions before future resizing operations.

---

## Overall Progress

Today's work focused on strengthening the foundation of the generic `HashMap`. Primitive hash functions were designed using template specialization, and important architectural decisions regarding bucket initialization and hashing strategy were finalized before moving on to the remaining implementation.

---

## Session 3

**Duration:** 2 Hours

### Goal

Design the internal node structure of the `HashMap` and implement the core class methods.

### Work Completed

* Designed the `HashNode<K, V>` class to represent each key-value pair stored in the hash table.
* Defined the data members required by `HashNode`, including the key, value, and pointer used for separate chaining.
* Implemented the constructors for `HashNode`.
* Implemented the initial `HashMap` methods, including constructors and other foundational member functions required before insertion and deletion logic.
* Organized the implementation to keep the public interface independent of the internal storage details.

### Problem Encountered

While designing the internal structure, it was necessary to determine which responsibilities should belong to `HashNode` and which should remain within the `HashMap` class to maintain a clean and modular design.

### Solution

Assigned only the storage-related responsibilities to `HashNode`, while keeping operations such as bucket management and overall map behavior inside the `HashMap` class. This separation of responsibilities resulted in a cleaner and more maintainable architecture.

### Key Learning

A well-designed data structure separates data representation from operational logic. Keeping `HashNode` lightweight and allowing `HashMap` to manage higher-level operations improves readability, maintainability, and future extensibility.
