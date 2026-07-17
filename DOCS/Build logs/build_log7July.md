### Date: 07/07/2026

---

## Session 1

**Duration:** 2 Hours

### Goal
Begin the design and documentation of the `LinkedList` class and decide whether a singly or doubly linked list would be the most suitable implementation for the project.

### Problem Encountered
Initially, I assumed that maintaining both **head** and **tail** pointers in a doubly linked list could reduce insertion at any position to **O(1)**. Since traversal can start from either end, I expected arbitrary insertion to become a constant-time operation.

### Analysis Performed
To verify this assumption, I analyzed how insertion actually works. Although traversal can begin from the nearer end of the list, the desired position still has to be located before insertion can occur. I also derived the average traversal distance mathematically to understand how much benefit starting from the closer end provides.

### Observation
The analysis showed that using both `head` and `tail` reduces the average number of nodes visited during traversal, but the asymptotic complexity remains unchanged. In the worst case, traversal is still proportional to the number of nodes, making insertion at an arbitrary position an **O(N)** operation.

### Design Decisions Made
After comparing singly and doubly linked lists, I decided to implement a **Doubly Linked List** because:

- It allows bidirectional traversal.
- Insertion and deletion become easier when a node is already known.
- Maintaining both `head` and `tail` enables efficient operations at both ends of the list.
- It is suitable for real-world applications such as browser history, undo/redo functionality, playlists, and navigation systems.

### Key Learning
Time complexity depends not only on the insertion itself but also on the cost of locating the insertion position. Even though traversal becomes shorter on average, the overall complexity remains **O(N)** because the traversal step still grows linearly with the size of the list.

---

## Session 2

**Duration:** 2 Hours

### Goal
Design the object-oriented architecture of the `LinkedList` class and determine the constructors and memory management mechanisms required for a safe implementation.

### Problem Encountered
While designing the class, I was initially confused about where the template parameter (`<T>`) should be written. I also wanted to determine which special member functions were necessary for proper memory management.

### Analysis Performed
I studied how template classes are declared and implemented in C++. This helped me understand that inside a template class definition, writing `LinkedList` is equivalent to writing `LinkedList<T>`. However, when defining member functions outside the class, the template parameter must be specified explicitly.

I also analyzed how dynamically allocated nodes should be managed and concluded that the class requires proper deep-copy semantics.

### Design Decisions Made
I designed and documented the following members for the `LinkedList` class:

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Copy Assignment Operator (Rule of Three)

Each function was included to ensure proper ownership of dynamically allocated nodes and prevent shallow-copy related issues.

### Observation
Since the linked list owns dynamically allocated memory, relying on compiler-generated copy operations would lead to multiple objects sharing the same nodes. This would eventually result in dangling pointers and double deletion.

### Key Learning
Any class that manually manages dynamic memory should implement the **Rule of Three** to ensure safe copying and proper resource management.

---

## Session 3

**Duration:** 2 Hours

### Goal
Complete the internal documentation of the linked list implementation and finalize the design decisions for the `Node` class.

### Problem Encountered
While documenting the implementation, I questioned whether the internal `Node` class should also implement the Rule of Three, similar to the `LinkedList` class.

### Analysis Performed
I examined the responsibilities of both classes and observed that users never create or copy `Node` objects directly. Every node is created, linked, copied, and destroyed exclusively by the `LinkedList` class.

### Design Decision Made
Based on this analysis, I decided that the `Node` class should remain a lightweight internal implementation detail and therefore does **not** require its own Rule of Three or copy constructor.

Instead, all memory allocation, deep copying, linking, and destruction are handled by the `LinkedList` class itself.

### Additional Work Completed
Along with the implementation documentation, I also:

- Documented the purpose and design of the `Node` class.
- Added explanations of the Rule of Three for the linked list.
- Improved the documentation structure using Markdown.
- Corrected relative image paths used inside Markdown files.
- Added practical applications such as browser history, undo/redo systems, and playlists.
- Resolved Git repository synchronization issues, including non-fast-forward push errors.

### Key Learning
Separating responsibilities between classes results in a cleaner design. The `Node` class should only represent a single element of the list, while all ownership and memory management responsibilities should remain within the `LinkedList` class. This separation improves maintainability and keeps the implementation easier to understand.

---

## Reflection

Today's work focused primarily on **design decisions rather than implementation**. Instead of immediately writing code, I spent time validating assumptions about time complexity, understanding template behavior, and carefully planning memory management. This process reinforced the importance of designing data structures thoughtfully before implementation. I also realized that well-structured documentation is valuable because it clearly explains not only *how* the data structure works, but also *why* specific design decisions were made.