# Binary Search

Binary search is a searching algorithm that works on **sorted arrays**. It repeatedly divides the search interval in half until it finds the target element.

**How Binary Search Works**

1. **Initialization:**

   - Set `low` and `high` pointers to the beginning and end of the sorted array, respectively.

2. **Iteration:**

   - While `low` is less than or equal to `high`:
     - Calculate the `mid` index: `mid = (low + high) / 2` (integer division)
     - **Comparison:**
       - If the element at `mid` is equal to the target, you've found it! Return the index `mid`.
       - If the element at `mid` is greater than the target, the target (if it exists) must lie in the left half. Set `high = mid - 1` to narrow the search space.
       - If the element at `mid` is smaller than the target, the target (if it exists) must lie in the right half. Set `low = mid + 1` to narrow the search space.

3. **Not Found:**
   - If the loop completes and `low` becomes greater than `high`, the target value is not in the array.

**Time Complexity**

- Best case: O(1) (target is in the middle)
- Average and Worst case: O(log n), where 'n' is the number of elements in the array. This is significantly faster than a linear search which has a time complexity of O(n).

**Space Complexity**

- O(1) for iterative versions; O(log n) for recursive versions due to the call stack.
