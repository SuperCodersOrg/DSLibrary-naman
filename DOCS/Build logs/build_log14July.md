### Date: 14/07/2026

---

# Session 1 (2 Hours)

## Objectives
- Complete the remaining `HashMap` implementation.
- Validate functionality with different key types.

## Work Completed
- Completed the implementation of the remaining `HashMap` member functions.
- Implemented and verified:
  - `set()`
  - `get()`
  - `remove()`
  - `exists()`
  - Copy constructor
  - Assignment operator
- Added support for hashing multiple built-in data types:
  - `int`
  - `char`
  - `float`
  - `std::string`
- Designed a generic hashing mechanism for user-defined types using template specialization and compile-time type traits.
- Performed collision testing by inserting a large number of keys into the same bucket to verify correct separate chaining behavior.
- Tested the `HashMap` with primitive data types and custom user-defined objects.

## Challenges
- Encountered template specialization and compiler errors while implementing generic hash functors.
- Investigated issues related to compile-time detection of the `createHash()` member function for user-defined types.

## Outcome
- Successfully completed the functional implementation of the custom `HashMap`.
- Verified correctness across multiple key types and collision scenarios.

---

# Session 2 (2 Hours)

## Objectives
- Set up the Google Test framework.
- Begin writing unit tests for project components.

## Work Completed
- Installed and configured Google Test using CMake's `FetchContent`.
- Resolved compiler and environment issues by migrating from the old MinGW toolchain to the MSYS2 UCRT64 GCC toolchain.
- Updated CMake configuration for Google Test integration.
- Created the initial testing framework.
- Implemented comprehensive unit tests for the `DynamicArray` class, covering:
  - Constructors
  - `append()`
  - `insert()`
  - `remove()`
  - `get()`
  - `getSize()`
  - `getCapacity()`
- Verified behavior for normal operations, edge cases, and exception handling.

## Challenges
- Resolved multiple configuration issues involving CMake, compiler selection, and IntelliSense.
- Learned the Google Test workflow, including assertions and test discovery through CMake.

## Outcome
- Successfully integrated automated unit testing into the project.
- Completed the first full testing suite for the `DynamicArray` implementation.

---

# Session 3 (2 Hours)

## Objectives
- Develop comprehensive unit tests for the `LinkedList` implementation.
- Organize the testing framework for future scalability.

## Work Completed
- Created dedicated Google Test files for every public `LinkedList` method.
- Implemented tests for:
  - `getHead()`
  - `getTail()`
  - `insertFront()`
  - `insertBack()`
  - `insert()`
  - `deleteFront()`
  - `deleteBack()`
  - `search()`
  - `findNode()`
  - `remove()`
  - `printForeward()`
  - `printBackward()`
  - `size()`
- Designed test cases covering:
  - Empty list behavior.
  - Single-node and multi-node lists.
  - Boundary conditions.
  - Pointer integrity.
  - Exception handling.
- Used Google Test's output capture utilities to verify console output for print functions.
- Reorganized the testing suite into separate files for each public method.
- Updated the CMake configuration to automatically discover all test files using file globbing, making the testing workflow easier to maintain.

## Challenges
- Designed tests that verified both returned values and the internal structure of the linked list after each operation.
- Configured CMake to automatically include newly created test files without requiring manual updates.

## Outcome
- Completed a comprehensive testing suite for the `LinkedList` implementation.
- Established a scalable testing infrastructure that can be reused for upcoming `HashMap` tests.

---

# Overall Progress

## Features Completed
- Completed the custom `HashMap` implementation with support for built-in and user-defined key types.
- Implemented compile-time hashing support for custom objects.
- Completed the complete Google Test suite for the `DynamicArray`.
- Completed the complete Google Test suite for the `LinkedList`.
- Integrated Google Test into the build system using CMake.
- Automated test discovery through CMake for easier project maintenance.

## Learning Reflection
- Gained a deeper understanding of template specialization, compile-time type traits, and generic programming in C++.
- Learned how to design reusable hash functions for primitive and user-defined types.
- Improved debugging skills by resolving compiler, CMake, and toolchain configuration issues.
- Developed practical experience with Google Test, including assertions, exception testing, and output capture.
- Strengthened understanding of testing pointer-based data structures by validating both functionality and internal node relationships.
- Improved project organization by modularizing test files and automating test discovery through the build system.