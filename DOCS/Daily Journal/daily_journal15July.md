# Design Journal

### Date: 15/07/2026

## Section 1 — Specific Bugs

### Bug 1

**Issue:** While performing functional testing of the `HashMap`, retrieval operations for keys that were not present needed to be handled safely.

**Observation:** Attempting to access values for non-existent keys without proper validation could lead to incorrect program behavior. Appropriate existence checks were required before returning values.

---

### Bug 2

**Issue:** While integrating the custom `HashMap` into RedisLite, the command handlers had to be adapted to the interfaces exposed by the data structure.

**Observation:** The Redis commands (`SET`, `GET`, and `DEL`) required direct interaction with the `HashMap` APIs, making it necessary to align the command processing logic with the implemented methods.

---

### Bug 3

**Issue:** During command parsing, invalid user input such as empty keys or incomplete commands could result in unexpected behavior.

**Observation:** Input validation was necessary before executing Redis commands to ensure only valid operations were processed.

---

## Section 2 — Failed Attempts

### Attempt 1

Initially focused only on testing normal insertion and retrieval operations of the `HashMap`.

Further testing revealed the importance of validating edge cases such as duplicate keys, missing keys, and deletion of existing entries to ensure correctness.

---

### Attempt 2

Initially assumed the Redis command handlers could directly interact with the `HashMap` without modification.

During implementation, the command processing logic required adjustments so that each Redis command correctly invoked the corresponding `HashMap` method.

---

### Attempt 3

Initially relied on command execution without sufficient input validation.

After encountering invalid input scenarios, additional validation checks were introduced to prevent incorrect operations and improve the stability of the CLI.

---

## Section 3 — Design Update

Today's work focused on validating the `HashMap` implementation and integrating it into the RedisLite application.

The redesign included:

* Performing functional testing for all major `HashMap` operations.
* Verifying insertion, retrieval, update, and deletion of key-value pairs.
* Integrating the custom `HashMap` with RedisLite.
* Connecting the `SET`, `GET`, and `DEL` commands to the corresponding `HashMap` methods.
* Improving command validation and error handling for invalid user input.

---

## Section 4 — Code Reference

**Commit Hash:** `365ddc0304d80581b32f37fb96ed71cd4bff8ebe`
**Commit Hash:** `d26dff1217b1e9d42226f50b46af7a27f4073424`
**Commit Hash:** `d19d4dc49f46c6aca4bbc7c44eebf93beb967ea2`
**Commit Hash:** `c80d20e8f2fbb347a467023f3fe53f8eddc7e075`
**Commit Hash:** `6c2b468896710039cbb1cd5a8eff710ce62c4e92`
**Commit Hash:** `8dc73561bd4cde010f823d20b0d2cc2c52f11571`
**Commit Hash:** `d14ba407e149a2dbd41636d38bb77f05e135d806`
**Commit Hash:** `ce698f6e24a08dc81bd00f4b09127d10a7ad9ba4`
**Commit Hash:** `38c20b4a00178d8fefeea73c04a9d0daf5ac6b82`
**Commit Hash:** `53996e10d4aee61da66b0ca07c614c8c43ca0988`
**Commit Hash:** `6ed2233be0976b2fe4aa7fb69654ab98b8c4a4a7`


**Files Modified:**

* `src/HashMap.h`
* `src/HashNode.h`
* `src/redisLite.cpp`
* `src/redisLite.h`
* `tests/hashMapSetTest.cpp`
* `tests/hashMapGetTest.cpp`
* `tests/hashMapRemoveTest.cpp`
* `tests/hashMapExistsTest.cpp`
* `tests/hashMapSizeTest.cpp`
* `tests/hashMapUserDefinedTest.cpp`



**Major Sections Updated:**

* HashMap functional testing
* RedisLite command implementation
* HashMap integration
* Command validation
* Error handling

---

## Section 5 — Learning Reflection

Today's work reinforced the importance of validating a data structure independently before using it inside a larger application. Functional testing of the `HashMap` helped verify that insertion, retrieval, update, and deletion behaved correctly under both normal and edge-case scenarios.

Another key learning was understanding how a well-designed interface simplifies integration. Connecting the `HashMap` with RedisLite demonstrated that clean APIs make higher-level application development significantly easier while reducing implementation complexity.

I also gained practical experience in designing more reliable command-line applications. Adding input validation and handling invalid operations improved the robustness of the RedisLite CLI and highlighted the importance of defensive programming when processing user input.

Overall, today's work improved confidence in the correctness of the `HashMap` implementation while laying the foundation for building additional RedisLite functionality on top of the custom data structures library.
