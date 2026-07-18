# DSA Interview Prep Review

1. **Overall Score: 5/10**
   This code is a classic "works but is mathematically suboptimal" solution. You would likely fail a live interview with this unless you corrected it immediately upon prompting. Sorting an entire array just to find the minimum and maximum elements shows a lack of awareness of time complexity bounds.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Gets the right answer and `__gcd` is used correctly.
   * **Time complexity:** 3/10 - $O(N \log N)$ due to sorting. The optimal time complexity to find the min and max is $O(N)$.
   * **Space complexity:** 8/10 - $O(\log N)$ due to sorting (or $O(1)$ if we ignore standard library internals).
   * **Code quality:** 8/10 - Very short and clean, using standard library functions effectively.
   * **Pattern recognition:** 2/10 - Missed the basic pattern: `min` and `max` can be found in a single linear pass $O(N)$ without sorting.

3. **Missed Edge Cases / Bugs:**
   No functional bugs, it produces the correct output.

4. **Would This Pass?**
   * **At an OA:** Pass. Array length is $1000$, so $O(N \log N)$ easily passes.
   * **At a live interview:** Fail. The interviewer would instantly ask, "Why are you sorting the array to find the minimum and maximum?" If you did this in an interview, they might suspect you don't fully grasp Big-O notation.

5. **Top 3 Improvements:**
   1. **Find Min/Max linearly:** Use `std::minmax_element` or simply iterate through the array once in $O(N)$ to find both values.
   2. **Avoid modifying the input:** Sorting modifies the input `nums` vector, which is generally bad practice in production unless requested (though LeetCode passes it).
   3. **No other changes needed.**

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       int findGCD(vector<int>& nums) {
           int min_val = nums[0];
           int max_val = nums[0];
           
           for(int num : nums) {
               min_val = min(min_val, num);
               max_val = max(max_val, num);
           }
           
           return std::gcd(min_val, max_val); // std::gcd in <numeric> is preferred in modern C++ over __gcd
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N + \log(\text{min\_val}))$. $O(N)$ to find min/max, and $O(\log(\text{min\_val}))$ for the Euclidean GCD algorithm.
   * Space Complexity: $O(1)$.

7. **What to Practice Next:**
   Practice **Time Complexity Analysis**. Before calling `sort()`, always ask yourself: "Do I actually need the entire array sorted, or do I just need one or two specific elements (like min, max, or top K)?" Practice finding elements using $O(N)$ techniques.
