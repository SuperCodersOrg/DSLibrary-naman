# Design Journal
### Date: 14/07/2026

## Section 1 — Specific Bugs

### Bug 1
**Issue:** While integrating Google Test into the project, newly created test files were not automatically included in the build process.

**Observation:** Every time a new test file was created, the corresponding source file had to be manually added to `CMakeLists.txt`, making the testing workflow difficult to maintain.

---

### Bug 2
**Issue:** While configuring the testing environment, the project continued using the older MinGW compiler instead of the MSYS2 UCRT64 toolchain.

**Observation:** The incorrect compiler selection resulted in build configuration issues and inconsistent IntelliSense behavior, requiring investigation of the system environment variables, compiler paths, and CMake configuration.

---

### Bug 3
**Issue:** While designing unit tests for pointer-returning methods such as `getHead()`, `getTail()`, and `findNode()`, dereferencing returned pointers without validation could lead to undefined behavior during testing.

**Observation:** Pointer-returning methods should first be validated before checking the values stored inside the returned nodes.

---

## Section 2 — Failed Attempts

### Attempt 1

Initially maintained a single test source file containing all unit tests for an entire data structure.

As the number of methods increased, the file became difficult to navigate and maintain. The testing framework was later reorganized into separate test files for individual public methods.

---

### Attempt 2

Initially continued manually updating `CMakeLists.txt` whenever a new Google Test source file was added.

This approach quickly became repetitive and error-prone. The build system was later redesigned to automatically discover test files using CMake's file globbing mechanism.

---

### Attempt 3

Initially attempted to resolve the Google Test configuration issues by repeatedly modifying compiler settings.

Further investigation revealed that the root cause was the compiler toolchain selection rather than the testing framework itself. After configuring the project to use the MSYS2 UCRT64 compiler, the build environment became stable.

---

## Section 3 — Design Update

Today's work focused on establishing a scalable automated testing infrastructure for the project.

The redesign included:

- Integrating Google Test with the existing CMake build system.
- Organizing unit tests into separate files for each public method.
- Designing comprehensive test cases for both `DynamicArray` and `LinkedList`.
- Updating the build system to automatically discover test files.
- Improving the development environment by configuring the project to use the MSYS2 UCRT64 compiler.

---

## Section 4 — Code Reference

**Commit Hash** : ```26b901dc1c58b1635621a9b5d3dc7e57d7c802dc```<br>
**Commit Hash** : ```32d2b270743e1a5b4ec3e00bb2126cad86db666e```<br>
**Commit Hash** : ```26b901dc1c58b1635621a9b5d3dc7e57d7c802dc```<br>
**Commit Hash** : ```32d2b270743e1a5b4ec3e00bb2126cad86db666e```<br>
**Commit Hash** : ```26b901dc1c58b1635621a9b5d3dc7e57d7c802dc```<br>
**Commit Hash** : ```32d2b270743e1a5b4ec3e00bb2126cad86db666e```<br>
**Commit Hash** : ```fd7f78277db6f07174e8f178fa78d85d9ee16cdd```<br>
**Commit Hash** : ```365ddc0304d80581b32f37fb96ed71cd4bff8ebe```<br>
**Commit Hash** : ```d26dff1217b1e9d42226f50b46af7a27f4073424```<br>

**Files Modified:**

- `CMakeLists.txt`
- `tests/dynamicArrayAppendTest.cpp`
- `tests/dynamicArrayGetCapacity.cpp`
- `tests/dynamicArrayGetSizeTest.cpp`
- `tests/dynamicArrayGetTest.cpp`
- `tests/dynamicArrayInsertTest.cpp`
- `tests/dynamicArrayRemoveTest.cpp`
- `tests/linkedListDeleteBack.cpp`
- `tests/linkedListDeleteFront.cpp`
- `tests/linkedListFindNodeTest.cpp`
- `tests/linkedListGetHeadTest.cpp`
- `tests/linkedListGetTailTest.cpp`
- `tests/linkedListInsertBackTest.cpp`
- `tests/linkedListInsertFrontTest.cpp`
- `tests/linkedListInsertTest.cpp`
- `tests/linkedListPrintTest.cpp`
- `tests/linkedListRemoveTest.cpp`
- `tests/linkedListSearchTest.cpp`
- `tests/linkedListSizeTest.cpp`

**Major Sections Updated:**

- Google Test integration
- CMake build configuration
- DynamicArray unit tests
- LinkedList unit tests
- Automated test discovery
- Testing project organization

---

## Section 5 — Learning Reflection

Today's work shifted the project from manual testing to an automated testing workflow. Writing independent unit tests for every public method reinforced the importance of validating not only expected functionality but also boundary conditions, invalid inputs, and edge cases.

Another important learning was understanding how project organization affects long-term maintainability. Separating test cases into individual source files significantly improved readability and simplified debugging. Automating test discovery through CMake further reduced repetitive configuration work and made the testing framework scalable as additional data structures are implemented.

I also gained practical experience configuring a modern C++ development environment. Investigating compiler selection, CMake configuration, and Google Test integration provided a better understanding of how build systems interact with toolchains. This knowledge will simplify the addition of future testing modules, particularly for the `HashMap` implementation.

Overall, today's work established a robust testing infrastructure that improves code reliability, simplifies debugging, and provides a strong foundation for the continued development of the data structures library.

In addition , I also learned how to work with system path variables and updates my compiler to work with latest version of g++ compiler in my windows operating system.