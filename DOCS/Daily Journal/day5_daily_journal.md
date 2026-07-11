# Daily Design Journal

### Date: 10/07/2026

---

## Section 1 — Specific Bug

### Compiler Error
```text
error: no matching function for call to 'Hash<char>::operator()(const char&)'
```

### Cause
While integrating the generic `HashMap`, the compiler could not locate a valid hash function for `char` keys because a specialization for `Hash<char>` had not yet been implemented, but under my logic I have overloaded the operator () on the basis of paramter data type and not designed seperate classes for seperate datatypes unlike actual cpp implementation.

---

## Section 2 — Failed Attempt

Initially, I attempted to use a single generic hash function for all primitive data types. Although this approach reduced code duplication, it did not account for the differences in the internal representation of each data type. This would have resulted in poor hash distribution and reduced flexibility.

To solve this, I redesigned the hashing mechanism using **template specialization**, allowing each supported primitive type to implement its own optimized hashing logic while maintaining a common interface.

---

## Section 3 — Memory Diagram
 ![HashMap Implementation](../images/HashMap%20Updated%20Memory%20Diagram.jpeg)

## Section 4 — Code Reference

**Commit Hash** : ```2f4924103052cd39fb0c4767afa4c0f064bfabd5```
**Commit Hash** : ```5556a552295cc3c77bacc3afcc3b08d762c39b72```
**Commit Hash** : ```44305bbe9e3d59b921638b4bb17e90e0dac4bd9f```
**Commit Hash** : ```fa4fd485805dbdfa6046f011ea0ca0c47b560473```
**Commit Hash** : ```62e275150ebecbd4327e3ac299692db0ac8089c9```
**Commit Hash** : ```36e70bc1f9f01db1d885e3b40267da10617cdce2```
**Commit Hash** : ```6b0ceaa9a07be0429388a5bce3bba761a66f4180```
**Commit Hash** : ```02fdd98c37aee74330e9cccf4c8b2d60a3df1893```
**Commit Hash** : ```83a95768807aa13732f5080138c790f3ef099184```
**Commit Hash** : ```cd108c5dbbd8e357be2a5d3ba665d5a18df516f0```
**Commit Hash** : ```632f26e0d888ce6199050773f66e440e9f793dfb```
**Commit Hash** : ```99cb33d03380a5a38858be00bcd672de6f9c879a```
**Commit Hash** : ```faf7296cb9ef9f77d60c52e80dc3be4fd2bda867```

**Files Modified**

- `dynamicArray.tpp`
- `linkedList.h`
- `linkedList.tpp`
- `hashMap.h`
- `hashMap.tpp`

---

## Section 5 — Learning Reflection

Today's work deepened my understanding of designing a generic `HashMap` rather than simply implementing one.

The first important learning was that **different data types require different hashing strategies**. Initially, I considered using a single generic hash function for all primitive types, but I realized that the internal representation of `int`, `char`, and `float` differs significantly. This led me to understand why **template specialization** is a better design choice—it provides a common interface while allowing each data type to use a hashing algorithm suited to its characteristics.

Another key learning was the importance of **maintaining a clear separation of responsibilities** between classes. While designing `HashNode`, I understood that it should only represent a single element of the hash table by storing the key, value, and the pointer required for separate chaining. The `HashMap` class, on the other hand, should be responsible for bucket management, hashing, and high-level operations. This separation makes the implementation modular, easier to maintain, and simpler to extend.

I also learned that **choosing an initial bucket capacity is a design decision rather than an arbitrary value**. Unlike dynamic arrays, where a small initial capacity minimizes wasted memory, hash maps benefit from a slightly larger starting bucket count because it reduces the likelihood of collisions during the initial insertions. Understanding this trade-off helped me justify selecting an initial capacity of **8**.

When I was implementing HashMap I also encountered that a helper function is much needed for the task of exists so I created one and also learned about double pointers while working with buckets that I have never done before and helped me to refine my programming skills 