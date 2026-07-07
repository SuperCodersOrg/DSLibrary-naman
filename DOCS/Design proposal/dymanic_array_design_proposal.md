# Dynamic Array
A dynamic array is a linear data structure that stores elements in contiguous memory locations, just like a normal array. Unlike a static array, however, its size is not fixed. When the array becomes full, it automatically allocates a larger block of memory, copies the existing elements into it, and releases the old memory. This allows the array to grow during program execution.
## Section 1: Public API

**method 1** : ```append(T value)``` , it will take input as an integer and add it to the end of the array here we are not returning anything as it is already understood by the user that at which index the new element is added so there is no need to return the index hence we return void.

**method 2** : ```remove(T index)```, here we will provide the index of the element that we want to be removed from our dynamic array, according to me we should also return the element value that is deleted so, I choose integer as the return type.

**method 3** : ```get(T index)``` it will take an index as the input and return the value associated with that index so the returned value is integer in here for my implementation

**method 4** : ```size()``` it will not take any parameter and will only return the current size of the dynamic array hence the return type is int 

**method 5** : ```capacity()``` it will not take any parameter and will only return the current capacity of the dynamic array hence the return type is int

**method 6**` : ```insert(int index, T value)``` it will input the value on the index by shifting elements to next by one and the return type here also is void

## Section 2 : Internal Representation
![Dynamic Array](../images/WhatsApp%20Image%202026-07-07%20at%209.27.53%20AM.jpeg)
We have to define the rule of three here in which in destructor we will deallocate the space allocated using free keyword the memory allocated, in copy constructor we will allocate more memory same as the current capacity of previous object and afterward copy all elements in it, hence it is a deep copy that is created. Similarly, for the assignment operator we will perform assigning of memory same as the capacity of the original array.

## Section 3 : Complexity Estimates
1. ```append(int value)```
**Best Case:** The append operation takes O(1) time when there is enough capacity in the array, as the new element is simply placed at the end. <br>
**Average Case:** The append operation takes O(1) amortized time because although resizing occasionally occurs, most insertions do not require it.<br>
**Worst Case:** The append operation takes O(n) time when the array is full and all existing elements must be copied to a newly allocated larger array.<br>
2. ```remove(int index)```

**Best Case:** The remove operation takes O(1) time when the last element is removed, as no shifting of elements is required.<br>
**Average Case:** The remove operation takes O(n) time because elements after the removed index usually need to be shifted one position to the left.<br>
**Worst Case:** The remove operation takes O(n) time when the first element is removed, requiring all remaining elements to be shifted.<br>
3.``` get(int index) ```

The get operation takes O(1) time because the element can be accessed directly using its index, hence its average, best and worst case is same that is O(1)<br>
4. ```size()```

The size operation takes O(1) time because it simply returns the stored size variable, hence its average, best and worst case is same that is O(1)<br>
5. ```capacity()```

Same as in size() it just return the value of stored variable hence it is same in all cases best, worst and average that is O(1).<br>
6. ```insert(int index, int value)```

**Best Case:** The insert operation takes O(1) time when the element is inserted at the end of the array and sufficient capacity is available.<br>
**Average Case:** The insert operation takes O(n) time because elements usually need to be shifted to make space for the new element.<br>
**Worst Case:** The insert operation takes O(n) time when the element is inserted at the beginning or when resizing and shifting of all elements are required.

## Section 4: Design Decisions
__Initial size of array :__ I have decided to keep the initial size of array as 4 because it is not even small as increasing the size by one in every insertion, I also looked into to set the initial size as 8 but then if someone just inserted only one value it would waste memory so, here initial size is neither too small nor too large so I choosed it as my choice for this implementation.
<br><br>
__Doubling the size :__
I choosed to double the size as it gives the best results for smaller inputs and maintains the balance between performance and memory usage but as we the capacity increase and it comes to be in thousands it would cause issue so to resolve it, I have though of to consider space usage as the parameter to know by which factor should we multiply the capacity as the size increase the resizing factor less then usual. Example if space usage is about 1MB then we can go with 2x and as it increase we can choose 1.5x and more accordingly

