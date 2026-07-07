# Linked List
A linked list is a dynamic linear data structure consisting of nodes, where each node stores data and a pointer to the next node, allowing efficient insertion and deletion without shifting elements.
## Section 1 : Public Api
<pre>
  1.insertFront(T value) : It takes the value as input and insert it to the front of linked list as the user knows the location there is no need to
  return anything i.e. void 
  2. deleteFront() : it will delete the node from the start and in my implementation I have decided to return the element that is deleted so i will 
  return integer as return type
  3. insertIndex(int index , T value) : Here the user will enter the index at which they want to insert the value and the return type is also void
  here too
  4. search(T value) : it will return whether the value is present in linked list or not so the return type is bool in here 
  5. size() : it will return the number of elements present in the linked list so the return type here is integer 
  6. print() : it will just traverse the array and print the values so the return type is void here 
</pre>

## Section 2 : Internal Representation
The LinkedList object itself is created in memory and contains three data members: head, tail, and length. 
The head pointer stores the address of the first node, the tail pointer stores the address of the last node, and length stores the total number 
of nodes in the list. The actual nodes are not stored inside the LinkedList object; instead, they are dynamically allocated on the heap. 
Each node contains a data field (value) and a pointer (next) that stores the address of the next node. Starting from the head, we can traverse 
the entire list by repeatedly following the next pointers until we reach a node whose next is NULL, which is the tail node. 
During insertion and deletion, only these pointers are updated while the nodes themselves remain dynamically allocated or are freed using 
free when no longer needed.

## Section 3 : Complexity Estimates
1. insertFront(T value)
   It only required to just shuffle pointers to nodes in a sequential way and is independent of the size of the array hence it is O(1) for
   best, worst and average case.
2. deleteFront()
   Similarly, delete front is also of constant time complexity as we donot need to traverse the linked list hence it is also of constant time
   complexity i.e. O(1)
3. insertIndex(int index, T value)
Best Case: The insertIndex() operation takes O(1) time when the insertion index is at the beginning of the linked list.
Average Case: The insertIndex() operation takes O(n) time because, on average, about half of the nodes must be traversed to reach the desired index.
Worst Case: The insertIndex() operation takes O(n) time when the insertion index is near the end of the linked list, requiring traversal of almost all nodes.
6. search(T value)
Best Case: The search() operation takes O(1) time when the required value is present in the first node.
Average Case: The search() operation takes O(n) time because the value is expected to be found after traversing approximately half of the linked list.
Worst Case: The search() operation takes O(n) time when the value is in the last node or is not present in the linked list.
7. size()
In our implementation we have kept a variable stored and it will just be returned nothing else is needed hence it is of O(1) time complexity.
8. print()
Here, it is strongly dependent upon the number of inputs hence it is always dependent on size N hence time complexity is O(N) in all the cases
for print

## Section 4 : Design Decision
In our implementation we have declared a variable lenght to store the number of variables in the linked list and our implementation is not focused 
the backward traversal or back movement of pointer so there is no need of doubly linked list as it will only increase the memory usage 
