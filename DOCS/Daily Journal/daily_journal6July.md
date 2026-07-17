# Daily Design Journal
### Date: 06/07/2026

---

## Section 1 — Specific Bug

### Bug 1
**Issue:** Initially selected an arbitrary initial capacity and resizing strategy for the Dynamic Array without analyzing their effect on performance and memory utilization.

**Observation:** It became clear that choosing a poor initial capacity or an inefficient growth factor can lead to frequent reallocations, unnecessary memory allocation, increased copying cost, and degraded overall performance.

---

## Section 2 — Failed Attempt

At first, I considered using a fixed-size increment (for example, increasing the capacity by a constant number of elements whenever the array became full). Although this approach was simple to implement, it caused frequent reallocations as the array grew, resulting in a linear number of resize operations.

I then compared this approach with exponential resizing strategies such as doubling the capacity and adaptive growth factors. After evaluating the time complexity and memory trade-offs, I concluded that exponential growth provides amortized **O(1)** insertion while significantly reducing the number of reallocations.

---

## Section 3 — Memory Diagram

**Hand-drawn memory diagram attached separately.**

The diagram should illustrate:

- Initial Dynamic Array allocation.
- Array becoming full.
- Allocation of a larger memory block.
- Copying existing elements into the new block.
- Releasing the old memory block.
- Updating the internal pointer to the new allocation.

---

## Section 4 — Code Reference

**Commit Hash:** `1bb92840ccaf90c529cf7eeca724c3afca4ea461`<br>
**Commit Hash:** `2e93767db8a756f354a055cf3cd68a77da8c3937`<br>
**Commit Hash:** `9729440197589fb721d09c05a4f78e5d60482456`<br>
**Commit Hash:** `fbdf79541a859e4c7f95da7d959755c98ad0e4de`<br>
**Commit Hash:** `8f3ff9995744665aa3960e8810b1e659341872ff`<br>

**Files Referenced:**
- `dynamic_array_design_proposal.md`
-`linked_list_design_proposal.md`
- Design notes for Dynamic Array resizing strategy

**Relevant Lines:**
- Documentation explaining Dynamic Array growth strategy.
- Initial capacity selection.
- Resizing algorithm comparison.
- Complexity analysis.

---

## Section 5 — Learning Reflection

Today's biggest learning was that the efficiency of a Dynamic Array depends not only on its implementation but also on the strategy used for memory growth. Earlier, I assumed that increasing the capacity by any amount whenever the array became full would be sufficient. After studying different resizing techniques, I understood that the choice of growth factor directly affects both runtime performance and memory consumption.

I learned why exponential resizing achieves amortized **O(1)** insertion by reducing the frequency of reallocations, while fixed-size increments lead to frequent copying operations and poorer scalability. I also understood that selecting an appropriate initial capacity helps avoid unnecessary early reallocations without wasting excessive memory. This changed my understanding from viewing resizing as a simple implementation detail to recognizing it as a key design decision that influences the overall efficiency and scalability of the data structure.

I also learned about how to work with md files and how to format them to create a structured document 