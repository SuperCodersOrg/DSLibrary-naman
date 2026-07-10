# Design Journal
### Date: 07/07/2026

## Section 1 — Specific Bug

### Bug 1
**Issue:** Initially assumed that maintaining both `head` and `tail` pointers in a Doubly Linked List would reduce insertion at an arbitrary index to **O(1)**.

**Observation:** After analyzing the traversal process, it was found that although traversal can begin from the nearer end (`head` or `tail`), the target position must still be located before insertion. Therefore, insertion at a random position remains **O(N)** in the worst case.

---

### Bug 2
**Issue:** Confusion regarding the syntax of template classes while defining the copy constructor.

Initially considered:

```cpp
LinkedList(const LinkedList<T>& other);
```

After studying template class syntax, it was understood that inside the class declaration,

```cpp
LinkedList(const LinkedList& other);
```

is equivalent because the compiler already knows the current template parameter `T`.

---

### Bug 3
**Git Error**

```text
git push origin main
! [rejected] main -> main (non-fast-forward)
error: failed to push some refs to 'github.com:namanagg2005-codequotient/DSLibrary.git'
```

The local branch was behind the remote branch, preventing the push operation.

---

## Section 2 — Failed Attempt

### Attempt 1

Initially believed that because a Doubly Linked List stores both `head` and `tail` pointers, insertion near the end of the list could always be completed in **O(1)** time.

After deriving the average and worst-case traversal mathematically, it became clear that only insertion at the **front** and **back** is **O(1)**. Insertion at an arbitrary position still requires locating the insertion point, giving an overall complexity of **O(N)**.

---

### Attempt 2

While documenting the constructors, I initially used

```cpp
LinkedList(const LinkedList<T>& other);
```

inside the class declaration.

After reviewing template syntax, I learned that `<T>` is optional inside the class declaration and is only required while defining member functions outside the class.

---

### Attempt 3

Initially considered implementing a copy constructor for the `Node` class.

After analyzing the design, it was determined that the `Node` class is completely internal to the linked list implementation. Users never create or copy nodes directly, so all deep-copy operations are handled by the `LinkedList` class itself. Therefore, implementing the Rule of Three for the `Node` class would be unnecessary.

---

## Section 3 — Memory Diagram

Today's work included preparing and documenting the memory diagrams for the Doubly Linked List implementation.

The diagrams illustrate:

- Empty Linked List (`head = tail = nullptr`)
- Forward and backward links using `next` and `prev`
- Insertion at the front
- Insertion at the back
- Pointer updates during insertion
- Relationship between `head`, `tail`, and intermediate nodes

![Memory Diagram](./images/LinkedListMemoryDiagram.jpeg)

---

## Section 4 — Code Reference

**First Commit Hash:** ```26bac7e25e2d2ba0101ce2d8429090789e7d691e```
**Second Commit Hash** ```480086ee1351d09d20e2cf754b33fb520be3ba42```

**Files Modified:**

- `README.md`
- `DOCS/LinkedList.md`

**Major Sections Updated:**

- Constructors
- Rule of Three
- Complexity Analysis
- Node Class Documentation
- Average Case Complexity Derivation
- Why Doubly Linked List
- Applications
- Markdown Documentation

---

## Section 5 — Learning Reflection

Today's work changed my understanding of several important implementation details.

Initially, I believed that maintaining both `head` and `tail` pointers would reduce insertion at any position to constant time. After deriving the traversal mathematically, I understood that these pointers only optimize operations performed at the ends of the list. Any insertion or deletion at an arbitrary position still requires locating the correct node, making the overall complexity **O(N)**.

Another important realization was understanding how template classes work in C++. I learned that inside a template class declaration, writing `LinkedList` automatically refers to `LinkedList<T>`, while `<T>` becomes mandatory only when defining member functions outside the class.

I also developed a better understanding of object ownership in data structures. Initially, I considered implementing the Rule of Three for the `Node` class. After analyzing the implementation, I realized that `Node` objects are private implementation details and are never managed directly by the user. Therefore, all memory allocation, deep copying, and deallocation responsibilities belong to the `LinkedList` class, resulting in a cleaner and more maintainable design.

Finally, I improved the project's technical documentation by writing detailed Markdown files, documenting constructors, complexity analysis, Rule of Three, applications of Doubly Linked Lists, and generating proper relative image paths for GitHub documentation.