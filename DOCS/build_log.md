### Date : 06/07/2026
## Session 1
Learned how to work with md files 
Markdown (`.md`) files use simple symbols to format text. A `#` at the beginning of a line creates a heading, with more `#` symbols representing smaller heading levels (e.g., `#` for Heading 1, `##` for Heading 2, and `###` for Heading 3). Use `**text**` to make text **bold**, `*text*` or `_text_` for *italic* text, and `~~text~~` for ~~strikethrough~~. Create unordered lists using `-`, `*`, or `+`, and ordered lists using numbers followed by a period (e.g., `1.` or `2.`). Hyperlinks are added using `[Link Text](URL)`, while images are inserted using `![Alt Text](Image_URL)`. Inline code is enclosed within single backticks (`` `code` ``), and multi-line code blocks are created using three backticks (```), optionally followed by the programming language name for syntax highlighting. Tables are created using the `|` symbol to separate columns and `---` to define the header row. Horizontal lines can be added using three or more hyphens (`---`), asterisks (`***`), or underscores (`___`). These simple formatting symbols make Markdown files easy to write, read, and maintain while producing clean and well-structured documentation.

## Session 2
Collected detailed information about the optimal resizing strategies and initial capacity selection for dynamic arrays, and developed a comprehensive design proposal based on this analysis. This involved studying how dynamic arrays grow when they reach their capacity, comparing different resizing approaches such as doubling the size, increasing by a fixed factor, or using incremental growth, and evaluating their impact on performance, memory usage, and time complexity. Special attention was given to balancing efficient memory utilization with minimizing the cost of resizing operations, which can be expensive due to element copying. Additionally, considerations were made for choosing an appropriate initial capacity to reduce the frequency of resizing during early usage while avoiding __unnecessary memory allocation__. Based on these insights, a well-structured design proposal was created that outlines the recommended resizing strategy, justifies the chosen growth factor, and explains how it improves overall efficiency and scalability of the dynamic array implementation.

### Date : 07/07/2026

## Session 1
Started the design and documentation of the **Linked List** implementation. Studied the differences between singly and doubly linked lists to determine the most suitable data structure for the project. Initially, there was confusion regarding whether maintaining both **head** and **tail** pointers could reduce the time complexity of insertion at an arbitrary position to **O(1)**. After analyzing the traversal process, it was concluded that although traversal can begin from the closer end of the list, locating the desired position still requires linear traversal in the worst case. Based on this understanding, the complexity analysis for insertion, deletion, searching, and traversal operations was revised. A mathematical derivation of the average-case insertion complexity was also prepared, showing that the average traversal distance is reduced but the asymptotic complexity remains **O(N)**. Detailed documentation describing the advantages of using a doubly linked list, its applications, and the reasoning behind selecting it over a singly linked list was completed.

---

## Session 2
Focused on the object-oriented design of the linked list implementation by identifying the constructors and memory management techniques required for the project. Designed the **default constructor**, **parameterized constructor**, **copy constructor**, and **destructor** for the `LinkedList` class and documented their purpose. While defining the constructors, an important clarification was made regarding the use of the template parameter (`<T>`). It was studied that inside a template class declaration, writing `LinkedList` is equivalent to `LinkedList<T>`, making the explicit `<T>` unnecessary within the class definition, whereas it must be specified while defining member functions outside the class. Additionally, the **Rule of Three** was implemented for the `LinkedList` class to ensure proper deep copying and memory management. During the design process, the necessity of implementing the Rule of Three for the **Node** class was also analyzed.

---

## Session 3
Completed the technical documentation for the internal implementation of the linked list. A detailed explanation of the **Node** class was prepared, describing its role as an internal building block of the data structure. It was concluded that the **Node** class does **not** require a copy constructor or Rule of Three implementation because node objects are never created, copied, or managed directly by the user. Instead, all node allocation, deep copying, linking, and deallocation are handled exclusively by the `LinkedList` class, making the `Node` class a lightweight implementation detail. Additional documentation was prepared explaining this design decision along with the Rule of Three implementation for the linked list. Practical development issues encountered during documentation were also resolved, including generating correct relative image paths for Markdown files, organizing documentation into structured sections, improving explanations of real-world applications such as browser history, undo/redo systems, playlists, and LRU cache implementation, and resolving Git version control issues related to repository synchronization and non-fast-forward push errors. The final outcome was a comprehensive and well-structured documentation module for the Doubly Linked List implementation suitable for integration into the project repository.

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