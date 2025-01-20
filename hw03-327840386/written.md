Question 1: Python Quicksort space usage

a. In terms of n, how many items does this quicksort code above iterate in order to find the items less than the pivot in one call to quicksort? And in terms of n, how many items does this code iterate in order to find the items greater than the pivot? 
The number of items iterated to find elements less than the pivot is n−1.
The number of items iterated to find elements greater than the pivot is also n−1.

b. how much extra space does one call to quicksort use, in terms of n? How many new lists are created in one call to quicksort, and where are each of these lists created in the code? 
The extra space complexity is O(n). Two new lists (less and greater) are created based on the elements of the input array. New lists 'less' and 'greater' are created inside the quicksort function, specifically in the else block, where the partitioning of the array occurs.                                                                                                                                                            
c. in the full quicksort implementation, from its start to completion with a sorted array, including all the recursive calls, how much additional space for these lists would be used, in terms of n? (For example, does it use n space, constant space, n2 space, etc.) Show your work or explain how you determined the total amount of space this version of quicksort would use. 
The total additional space used by the full quicksort implementation, from start to completion with a sorted array, would be O(n). This space is primarily due to the creation of new lists 'less' and 'greater' at each level of recursion and the space used on the call stack for function calls.


Question 2: Mergesort worst case
Write a sample array of size 12 with numbers that would trigger the worst case for your mergesort; for example, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}. In other words, fill in an array of size 12 with numbers that will ensure that your mergesort makes the maximum number of operations (comparing and copying) possible while sorting the array. Include an explanation of why this example array will require the maximum number of operations. Hint: you may want to work backwards through your mergesort. 

In mergesort, the worst-case scenario occurs when the array is initially sorted in reverse order, and the merge operation is performed at the maximum depth of the recursion tree.
In this reverse order array:
When merging two subarrays, each element from the left subarray needs to be compared with each element from the right subarray. Since both subarrays are sorted in descending order, the maximum number of comparisons is required.
Additionally, each element from the left subarray needs to be copied to the temporary array during the merge operation.
how mergesort proceeds with this array:
In the first merge step, the array is split into two subarrays of size 6 each. Each merge operation at this level requires comparing and copying all 6 elements.In the second merge step, the subarrays of size 6 are split into subarrays of size 3 each. Again, each merge operation requires comparing and copying all 3 elements.This process continues until individual elements are treated as subarrays of size 1, which require no further merging.