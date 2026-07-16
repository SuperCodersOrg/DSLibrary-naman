# Design Build Log

### Date: 15/07/2026

## Session 1 — HashMap Integration with RedisLite

### Objective

Integrate the custom `HashMap` into the RedisLite project and replace the temporary key-value storage.

### Work Completed

* Added the custom `HashMap` as the primary storage backend for RedisLite.
* Connected the `SET` command to `HashMap::set()`.
* Connected the `GET` command to `HashMap::get()`.
* Connected the `DEL` command to `HashMap::remove()`.
* Updated the RedisCLI implementation to communicate directly with the custom data structure.

### Challenges

* Adapting the command handlers to the `HashMap` interface.
* Handling missing keys without causing runtime errors.

### Outcome

* Successfully integrated the custom `HashMap` with RedisLite.
* Basic Redis commands were able to interact with the custom implementation.

---

## Session 2 — Functional Testing of HashMap

### Objective

Validate the correctness and reliability of the implemented `HashMap` before completing its integration.

### Work Completed

* Performed functional testing of the `HashMap` by executing all major operations.
* Verified insertion of new key-value pairs.
* Tested retrieval of existing and non-existing keys.
* Confirmed that updating an existing key correctly replaced the previous value.
* Verified deletion of keys and ensured removed entries were no longer accessible.
* Checked the behavior of the map under multiple consecutive operations to ensure consistency.

### Challenges

* Ensuring each operation maintained the correct internal state of the `HashMap`.
* Verifying edge cases such as duplicate keys and lookups for absent keys.

### Outcome

* All implemented `HashMap` operations behaved as expected.
* Functional testing increased confidence in the correctness of the data structure before integrating it into RedisLite.

---

## Session 3 — Command Validation and Debugging

### Objective

Improve the reliability of RedisLite by validating user input and debugging command execution.

### Work Completed

* Added validation for empty keys before executing commands.
* Improved error messages for invalid inputs.
* Refined command parsing to correctly process commands, keys, and values.
* Debugged issues related to `SET`, `GET`, and `DEL` command execution.
* Resolved build and runtime issues encountered during development.

### Challenges

* Handling invalid or incomplete user commands gracefully.
* Ensuring command handlers behaved correctly for missing keys and invalid input.

### Outcome

* RedisLite became more robust with improved input validation and error handling.
* Command execution became more stable after resolving parsing and runtime issues.
