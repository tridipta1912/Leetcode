# AI Code Review

## FAANG-Style Review

**1. Pattern Recognition:**
This solution uses the **Two Pointers (Slow and Fast Pointer)** pattern. This is the optimal strategy for modifying an array in-place to remove duplicates or specific elements.

**2. Time Complexity:**
- **$O(N)$**: where $N$ is the number of elements in the `nums` array.
- The `for` loop iterates over the array exactly once, doing a constant time check `nums[i] != nums[i - 1]` and a possible assignment at each step.

**3. Space Complexity:**
- **$O(1)$**: The problem asks for the duplicates to be removed in-place, which this solution successfully achieves. It only uses two integer variables (`i` and `ptr`), consuming constant extra space.

**4. Edge Cases Handled (and Missed):**
- **Missed Edge Case (Empty Array):** If `nums` is empty (`nums.size() == 0`), `ptr` is initialized to `1`, the loop is skipped, and the function returns `1`. However, an empty array should result in returning `0`. While LeetCode constraints for this problem usually specify `1 <= nums.length`, in a real-world scenario or a FAANG interview, failing to handle the empty array case is a significant oversight.
  *Fix:* Add a quick check at the start:
  ```cpp
  if (nums.empty()) return 0;
  ```

**5. Improvements & Suggestions:**
- **Return Type:** The standard LeetCode signature expects an `int` return type (`int removeDuplicates(vector<int>& nums)`). You changed it to `ll` (`long long`). While it might compile if the internal test runner allows it, it's generally best practice to stick to the requested signature. Using `int` is perfectly fine here since array sizes and indices fit well within standard 32-bit integers.
- **Unsigned to Signed Comparison:** `nums.size()` returns an unsigned integer (`size_t`). Comparing it with `ll i = 1` (a signed integer) could trigger compiler warnings. Using `int` or `size_t` for `i` and `ptr` would be cleaner.
