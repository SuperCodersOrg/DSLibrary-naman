__Section 1: Public API__
method 1 : append(int value) , it will take input as an integer and add it to the end of the array here we are not returning anything as it is already understood by the user that at which index the new element is added so there is no need to return the index hence we return void.
method 2 : remove(int index), here we will provide the index of the element that we want to be removed from our dynamic array, according to me we should also return the element value that is deleted so, I choose integer as the return type.
method 3 : get(int index) it will take an index as the input and return the value associated with that index so the returned value is integer in here for my implementation 
method 4 : size() it will not take any parameter and will only return the current size of the dynamic array hence the return type is int 
method 5 : capacity() it will not take any parameter and will only return the current capacity of the dynamic array hence the return type is int
method 6 : insert(int index, int value) it will input the value on the index by shifting elements to next by one and the return type here also is void

__Section 2 : Internal Representation__
We have to define the rule of three here in which in destructor we will deallocate the space allocated using free keyword the memory allocated, in copy constructor we will allocate more memory same as the current capacity of previous object and afterward copy all elements in it, hence it is a deep copy that is created. Similarly, for the assignment operator we will perform assigning of memory same as the capacity of the original array.

__Section 3 : Complexity Estimates__
1. append(int value)
Best Case: The append operation takes O(1) time when there is enough capacity in the array, as the new element is simply placed at the end.
Average Case: The append operation takes O(1) amortized time because although resizing occasionally occurs, most insertions do not require it.
Worst Case: The append operation takes O(n) time when the array is full and all existing elements must be copied to a newly allocated larger array.
2. remove(int index)
Best Case: The remove operation takes O(1) time when the last element is removed, as no shifting of elements is required.
Average Case: The remove operation takes O(n) time because elements after the removed index usually need to be shifted one position to the left.
Worst Case: The remove operation takes O(n) time when the first element is removed, requiring all remaining elements to be shifted.
3. get(int index)
The get operation takes O(1) time because the element can be accessed directly using its index, hence its average, best and worst case is same that is O(1)
4. size()
The size operation takes O(1) time because it simply returns the stored size variable, hence its average, best and worst case is same that is O(1)
5. capacity()
Same as in size() it just return the value of stored variable hence it is same in all cases best, worst and average that is O(1).
6. insert(int index, int value)
Best Case: The insert operation takes O(1) time when the element is inserted at the end of the array and sufficient capacity is available.
Average Case: The insert operation takes O(n) time because elements usually need to be shifted to make space for the new element.
Worst Case: The insert operation takes O(n) time when the element is inserted at the beginning or when resizing and shifting of all elements are required.

__Section 4: Design Decisions__
The initial size of array, I choosed it to be 4 as it is not that large if the user enters only 2 to 3 inputs and not that small hence it can accommodate data in an efficient manner.
Doubling the size, I choosed to double the size as it gives the best results for smaller inputs but if the input grows like we assume that if the capacity is in thousands then we could decrease so i will choose the approach of using memory instead of capacity number itself.

