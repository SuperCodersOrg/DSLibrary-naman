### Date: 06/07/2026

---

## Session 1

**Duration:** 1.5 Hours

### Goal
Learn how to create well-structured documentation using Markdown (`.md`) files for the Data Structures Library project.

### What I Learned
I explored the basic syntax of Markdown and understood how it can be used to create clean and readable documentation.

During this session, I learned how to:

- Create different levels of headings using `#`, `##`, and `###`.
- Format text using **bold**, *italic*, and ~~strikethrough~~ styles.
- Create ordered and unordered lists.
- Insert hyperlinks and images.
- Write inline code and multi-line code blocks with syntax highlighting.
- Create tables for organizing information.
- Add horizontal separators to improve document readability.

### Observation
Initially, Markdown appeared very limited because it is a plain text format. However, after experimenting with its syntax, I realized it provides everything required to create professional documentation while remaining simple and easy to maintain.

### Key Learning
Good documentation is as important as good code. Using Markdown makes project documentation clean, organized, and easy for others to understand without requiring any specialized tools.

---

## Session 2

**Duration:** 2 Hours

### Goal
Research different resizing strategies for implementing a custom Dynamic Array and decide which approach provides the best balance between performance and memory efficiency.

### Problem Encountered
While studying dynamic arrays, I found that there is no single resizing strategy that works optimally for every situation. Different libraries and programming languages use different approaches depending on their design goals.

### Analysis Performed
I compared multiple resizing techniques, including:

- Increasing the capacity by one element each time.
- Increasing by a fixed number of elements.
- Doubling the capacity.
- Increasing by a fixed growth factor.
- Adaptive growth based on memory usage.

I also studied how the choice of initial capacity affects the number of reallocations, memory consumption, and overall insertion performance.

### Observation
Growing the array by one element leads to frequent reallocations, making insertion inefficient. On the other hand, always doubling the capacity performs well for smaller arrays but may waste a significant amount of memory for very large datasets.

This led me to explore adaptive growth strategies that adjust the growth factor according to the current memory usage.

### Design Decisions Made
After evaluating different approaches, I decided to:

- Use an initial capacity of **4**, as it provides a good balance between minimizing early reallocations and avoiding unnecessary memory allocation.
- Use **capacity doubling** for smaller arrays to achieve efficient amortized insertion performance.
- Gradually reduce the growth factor for larger arrays to improve memory utilization.
- Round the computed capacity to the **next power of two** for predictable capacity growth and efficient memory allocation.

### Key Learning
Designing a dynamic array involves more than simply storing elements. Every decision, such as the initial capacity, growth strategy, and resizing logic, directly affects the time complexity, memory consumption, and scalability of the data structure. Careful analysis of these trade-offs is essential to build an efficient implementation.

---

## Reflection

Today's work focused more on **design and analysis** than coding. Instead of immediately implementing the dynamic array, I spent time understanding why different resizing strategies exist and how each impacts performance. This helped me make informed design decisions rather than relying on commonly used approaches without understanding their trade-offs. I also learned that clear documentation using Markdown is an important part of software development, making projects easier to understand and maintain.