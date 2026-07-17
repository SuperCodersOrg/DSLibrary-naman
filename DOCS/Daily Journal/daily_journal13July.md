# Design Journal
### Date: 13/07/2026

## Section 1 — Specific Bug

### Bug 1
**Issue:** While replacing the manually managed bucket array with `DynamicArray<LinkedList<HashNode<K,V>>>`, several `HashMap` methods still assumed that each bucket stored a raw `HashNode*`.

**Observation:** After refactoring, it became clear that bucket operations should be delegated entirely to the `LinkedList` interface. Methods such as `set()`, `get()`, `remove()`, and `exists()` had to operate using `findNode()`, `insertFront()`, and `remove()` instead of manually traversing pointer chains.

---

### Bug 2
**Issue:** While implementing lookups in the new bucket representation, there was no mechanism to compare two `HashNode` objects based only on their keys.

**Observation:** Introducing `HashNode::operator==()` simplified bucket searches considerably. Since key uniqueness is guaranteed in a `HashMap`, comparing only the keys was sufficient for all lookup operations.

---

### Bug 3
**Issue:** Attempted to implement a generic hash function by overloading `Hash::operator()` for primitive types along with a generic `operator()(const K&)`.

**Observation:** During template instantiation, duplicate function signatures were generated for primitive types (for example, `Hash<int>` contained two identical `operator()(const int&)` functions), leading to compilation errors. This highlighted the limitations of combining generic overloads with primitive overloads inside the same template.

---

## Section 2 — Failed Attempt

### Attempt 1

Initially continued using the old collision-handling approach by manually traversing linked `HashNode` pointers inside the `HashMap`.

After integrating the reusable `LinkedList`, it became clear that all traversal logic should remain inside the linked list implementation, allowing `HashMap` to interact only through its public interface.

---

### Attempt 2

Initially recreated bucket storage using manually allocated arrays during rehashing.

After integrating the generic `DynamicArray`, bucket storage was redesigned to use reusable containers, allowing memory management responsibilities to remain inside the `DynamicArray` implementation instead of the `HashMap`.

---

### Attempt 3

Initially attempted to support primitive and user-defined hashing by simply overloading multiple versions of `Hash::operator()`.

During compilation, template instantiation produced conflicting overloads for primitive types. This demonstrated that generic hashing requires a different design approach, such as template specialization or compile-time type selection.

---

## Section 3 — Design Update

Today's work focused on refactoring the internal architecture of the `HashMap`.

The redesign included:

- Replacing raw bucket arrays with `DynamicArray<LinkedList<HashNode<K,V>>>`
- Eliminating manual collision-chain management
- Delegating bucket operations to reusable `LinkedList` methods
- Updating copy constructor, assignment operator, and rehashing to work with reusable containers
- Designing a framework for supporting user-defined hashing through `createHash()`

---

## Section 4 — Code Reference

**Commit Hash** : ```0ced30234be4e587843112bcf638871ed66141b3```<br>
**Commit Hash** : ```5c2353b3ce441160af192f0ba711c8889332356c```<br>
**Commit Hash** : ```989c991fce755c3882e10a3e8812f0d3b899b69d```<br>
**Commit Hash** : ```de4009420b2407901453c39f37ae875b2089c136```<br>
**Commit Hash** : ```46f8b6f7de4c32d929a1e7809d0be99f5dbfa879```<br>
**Commit Hash** : ```a6a430b21a24ff1d11a94bf85376727615ae0e4f```<br>


**Files Modified:**

- `include/hashMap.h`
- `src/hashMap.tpp`
- `include/linkedList.h`
- `src/LinkedList.tpp`
- `include/dynamicArray.h`
- `src/dynamicArray.tpp`

**Major Sections Updated:**

- HashMap bucket representation
- Collision handling
- Rehash implementation
- Copy constructor
- Assignment operator
- LinkedList search and removal utilities
- Generic hashing framework

---

## Section 5 — Learning Reflection

Today's work significantly improved the modularity of the `HashMap` implementation. Instead of managing collision chains directly, I redesigned the implementation to reuse the generic `LinkedList` and `DynamicArray` developed earlier. This separation of responsibilities resulted in cleaner and more maintainable code while reducing duplicate logic.

Another important learning was understanding how reusable data structures influence higher-level design. Once the bucket representation changed, almost every `HashMap` operation required redesign rather than simple code modification. This reinforced the importance of designing generic interfaces that hide implementation details from dependent classes.

I also explored compile-time techniques for supporting user-defined hashing. While attempting to combine primitive hash overloads with a generic hash function, I encountered template instantiation conflicts. This helped me understand the challenges involved in designing extensible generic libraries and highlighted why template specialization is commonly used in standard library implementations.

Overall, today's work shifted the `HashMap` from a manually managed implementation to one that fully leverages reusable generic data structures, making the overall library more modular, extensible, and maintainable.