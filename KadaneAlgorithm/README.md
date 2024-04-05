# Kadane's Algorithm

* **Dynamic Programming Approach:** Kadane's Algorithm is a classic dynamic programming algorithm used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers.
* **Efficiency:** It offers an efficient linear time complexity solution (O(n)), significantly improving over brute force methods that examine every possible subarray.

**How Does It Work?**

The core idea of Kadane's Algorithm is this:

1. **Track Two Sums:**
   * `max_ending_here`: The maximum sum of a subarray ending at the current position.
   * `max_so_far`: The overall maximum sum of a subarray found so far. 

2. **Iteration and Update:**
   * Iterate through the array.
   * At each position, update `max_ending_here` as the maximum between:
      * The current element itself (starting a new subarray)
      * The current element + `max_ending_here` from the previous position (extending the existing subarray)
   * After updating `max_ending_here`, check if it's greater than `max_so_far` and update `max_so_far` if necessary.

3. **Result:** After the entire array is processed, `max_so_far`  holds the maximum contiguous subarray sum.

**Applications**

* **Finance:** Finding periods of maximum profit in stock price data.
* **Image Processing:** Detecting regions with maximum brightness.
* **Bioinformatics:** Identifying gene sequences with the highest scores.
* **General Problem Solving:**  Numerous scenarios where finding the maximum sum of a contiguous segment is beneficial.

**Key Points**

* Kadane's Algorithm works effectively even if the array contains all negative numbers.
* It focuses on finding contiguous subarrays, not any combination of elements.

