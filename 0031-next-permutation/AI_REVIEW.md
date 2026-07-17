# AI Code Review

## FAANG-Style Review

**1. Pattern Recognition:**
You are utilizing the C++ Standard Template Library (STL) built-in function `std::next_permutation`. While technically correct and often the best practice in production code, this skips the fundamental algorithmic pattern the question is designed to test: **Array scanning and Two Pointers** to find the next lexicographical permutation.

**2. Time Complexity:**
- **$O(N)$**: where $N$ is the number of elements in the `nums` array. 
- The `std::next_permutation` algorithm takes linear time in the worst case by scanning the array from right to left, finding the pivot, swapping, and reversing the suffix.

**3. Space Complexity:**
- **$O(1)$**: The permutation is done entirely in-place without any auxiliary memory.

**4. Edge Cases Handled:**
- All edge cases (e.g., array is already in descending order, duplicate elements, empty array) are perfectly handled by the STL implementation. If the array is at the last permutation, it automatically loops back to the lowest possible order (ascending).

**5. Improvements & Suggestions:**
- **Interview Setting:** In a FAANG interview, using a library function that directly solves the core problem is generally not acceptable. The interviewer will almost certainly ask you to implement it from scratch.
- **Implementation Strategy to Practice:**
  1. Iterate from right to left to find the first element that is smaller than the element to its right. Call this index `i`.
  2. If such an `i` exists, iterate from right to left again to find the first element strictly greater than `nums[i]`. Call this index `j`.
  3. Swap `nums[i]` and `nums[j]`.
  4. Reverse the sub-array starting from `i + 1` to the end.
  You should implement this logic manually to ensure you fully understand the mechanics.
