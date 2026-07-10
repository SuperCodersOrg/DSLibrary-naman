# Design Journal
### Date: 08/07/2026

## Section 1 — Specific Bug

### Bug 1
**Issue:** Initially believed that a generic `HashMap` should automatically generate hash values for user-defined classes by inspecting their data members.

**Observation:** After analyzing the implementation, it became clear that a generic `HashMap` has no knowledge of the internal structure of arbitrary user-defined classes. Therefore, the responsibility of generating hash values must be delegated to a separate `Hash` class implemented by the user.

---

### Bug 2
**Issue:** Confusion regarding whether the `Hash` class should expose multiple overloaded `operator()` functions or be implemented using template specialization.

**Observation:** After comparing both approaches, it was understood that template specialization provides a much more scalable solution. It allows users to define hashing logic for their own classes without requiring any modification to the `HashMap` library.

---

### Bug 3
**Issue:** Initially assumed that the `rehash()` function should receive the new bucket count as a parameter.

**Observation:** Since `rehash()` is an internal helper function, it already has access to the HashMap's data members such as `bucketCount`, `currentSize`, and `maxLoadFactor`. Therefore, it can determine the new bucket count internally, making the additional parameter unnecessary.

---

## Section 2 — Failed Attempt

### Attempt 1

Initially considered designing a constructor that would ask the user to specify which data members of a custom class should be used for hashing.

After exploring the implementation, it became clear that standard C++ cannot automatically inspect arbitrary class members at runtime. Since the `HashMap` is completely generic, this approach was not feasible. The design was replaced with a separate `Hash` class responsible for generating hash values.

---

### Attempt 2

Initially believed that the `Hash` class should contain overloaded hashing functions for every possible data type.

After comparing this design with template specialization, it became clear that overloading would require modifying the library every time a new user-defined class was introduced. Template specialization allows new data types to be supported without changing the existing implementation.

---

### Attempt 3

Initially considered passing the new bucket count as an argument to the `rehash()` function.

After reviewing the responsibilities of the function, it was determined that the bucket count should be computed internally by the HashMap itself. This keeps the implementation more encapsulated and simplifies the interface of the helper function.

---

## Section 3 — Design Decisions

Today's work focused on finalizing several important architectural decisions for the HashMap implementation.

The following design decisions were documented:

- Selection of the initial bucket size.
- Choosing **0.75** as the maximum load factor.
- Using **Separate Chaining** as the collision resolution technique.
- Designing a separate **Hash** class to compute hash values.
- Requiring users of custom classes to implement their own hashing logic and overload the equality (`==`) operator.
- Designing the internal representation, helper functions, constructors, Rule of Three, and public API of the HashMap.

These decisions ensure that the implementation remains generic, modular, extensible, and easy to maintain.

---

## Section 4 — Code Reference

**First Commit Hash:**  ```26bac7e25e2d2ba0101ce2d8429090789e7d691e```
**Second Commit Hash:** ```480086ee1351d09d20e2cf754b33fb520be3ba42```
**Third Commit Hash:** ```286a5e0849f0834ede708c9c50f91988bd6453c6```
**Fourth Commit Hash:** ```29493aaa2425914ccf1b18413cd4e7b06408b014```
**Fifth Commit Hash:** ```a801d5df3d92aa50c15aff6d80b52eaa78c1fc1c```
**sixth Commit Hash:** ```9cbc2b20c43174664136609ba7b04dc18815725f```

**Files Modified:**

- `DOCS/design proposal/hashmap_design_proposal.md`

**Major Sections Updated:**

- HashMap Public API
- Internal Representation
- Data Members
- Helper Functions
- Constructors
- Rule of Three
- Hash Class Documentation
- Rehashing
- Time Complexity Analysis
- Amortized Analysis
- Design Decisions
- Applications
- Markdown Documentation

---

## Section 5 — Learning Reflection

Today's work significantly improved my understanding of the internal design of hash-based data structures.

Initially, I believed that a generic HashMap could automatically determine how to hash user-defined objects. After studying the limitations of generic programming in C++, I realized that the HashMap has no knowledge of the internal structure of arbitrary classes. Therefore, hashing responsibility must remain with the user through a separate `Hash` class.

Another important realization was understanding the separation of responsibilities within the implementation. The `HashMap` is responsible only for storing key-value pairs, resolving collisions, managing buckets, and performing rehashing, while the `Hash` class is solely responsible for generating hash values. Similarly, the equality operator remains the responsibility of the user so that objects can be compared correctly after collisions occur.

I also developed a much deeper understanding of load factor, collision resolution, and amortized analysis. By deriving the cost of rehashing using a geometric progression, I understood why insertion remains **O(1)** on an amortized basis even though individual rehash operations require **O(n)** time.

Finally, I completed the overall architectural design of the HashMap by documenting its public API, helper functions, Rule of Three, design decisions, complexity analysis, and implementation details. This greatly improved both the quality of the documentation and my understanding of designing reusable generic data structures in C++.