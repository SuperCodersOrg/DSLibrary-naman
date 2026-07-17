### Date: 08/07/2026


### Session 1

**Duration:** 2 Hours

### Goal:
Design the overall architecture of the generic `HashMap` class, including its public API, internal representation, data members, constructors, and Rule of Three.

### Problem Encountered:
Initially, it was unclear how a generic `HashMap` should support user-defined key types while remaining independent of the structure of those classes.

### What I Tried:
- Designed the complete public API for the `HashMap`.
- Identified the required private data members.
- Explored different approaches for supporting custom key types.
- Studied how `std::unordered_map` handles hashing for user-defined classes.

### Outcome:
Successfully finalized the overall class design. The `HashMap` now used a class ```Hash``` that has the function which returns the hash value for the key.

---

### Session 2

**Duration:** 2 Hours

### Goal:
Understand the internal working of hashing, collision handling, load factor, and the rehashing process, along with their corresponding time complexities.

### Problem Encountered:
Understanding why the average-case complexity of insertion, searching, and deletion remains **O(1)** despite collisions and why rehashing does not increase insertion complexity to **O(n)**.

### What I Tried:
- Studied the concept of load factor and hashing.
- Analyzed how separate chaining handles collisions.
- Explored the complete rehashing algorithm step by step.
- Derived the best, average, worst, and complexities for all HashMap operations.
- Documented detailed complexity analysis for every public function.

### Outcome:
Developed a complete understanding of HashMap complexity analysis. Successfully documented the reasoning behind average-case **O(1)** performance, **O(n)** rehashing.

---

### Session 3

**Duration:** 1 Hour 30 Minutes

### Goal:
Complete the documentation for the HashMap implementation and strengthen the understanding of supporting concepts.

### Problem Encountered:
Understanding how custom hash functions are provided for user-defined classes and whether allowing users to define their own hash functions is a good design choice.

### What I Tried:
- Studied why the library cannot automatically determine which data members should participate in hashing.
- Compared the design with `std::unordered_map`.
- Documented the internal representation, data members, Rule of Three, helper functions, and public APIs of the HashMap.

### Outcome:
Completed the design documentation for the HashMap. Gained a clear understanding of the role of custom hash functors, the responsibilities of the user, and the overall design philosophy behind generic hash-based containers in C++.