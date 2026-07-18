# DSA Interview Prep Review

1. **Overall Score: 8/10**
   This is a strong passing solution. You correctly identified the state machine DP pattern needed to solve this problem, and your state transitions are perfect. However, an interviewer would push you to optimize the space complexity.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Correctly handles all transitions and initializes the DP table with a large enough value (`1000000000`) to act as infinity.
   * **Time complexity:** 10/10 - $O(N)$. We iterate through the arrays exactly once. This is optimal.
   * **Space complexity:** 5/10 - $O(N)$ due to the `vector<array<int, 2>> dp` array. This can be optimized to $O(1)$ because the state at step `i` only depends on the state at step `i - 1`.
   * **Code quality:** 8/10 - Very readable. Using `array<int, 2>` is a nice modern C++ touch over raw 2D vectors.
   * **Pattern recognition:** 9/10 - You correctly recognized 1D State Machine DP, but missed the immediate space optimization that usually accompanies it.

3. **Missed Edge Cases / Bugs:**
   No logical bugs. It perfectly covers the two conditions (straight increasing and cross increasing).

4. **Would This Pass?**
   * **At an OA:** Pass. The $O(N)$ space and time will easily run within limits.
   * **At a live interview:** The interviewer would ask: "Can we do better on space?" You should immediately recognize that you only need two variables to keep track of the previous `swap` and `no_swap` states.

5. **Top 3 Improvements:**
   1. **Space Optimization:** Reduce the $O(N)$ DP array to just two variables (`swap` and `not_swap`), since you only ever look at `i-1`.
   2. **Use `<algorithm>` constants:** Instead of `1000000000`, use `1e9` or `INT_MAX / 2` (to prevent overflow if you add to it).
   3. **Variable Names:** `dp[i][0]` and `dp[i][1]` are less readable than explicitly naming the states `swap` and `keep`.

   *Corrected Snippet (O(1) Space):*
   ```cpp
   class Solution {
   public:
       int minSwap(vector<int>& nums1, vector<int>& nums2) {
           int n = nums1.size();
           int prev_keep = 0;
           int prev_swap = 1;
           
           for (int i = 1; i < n; i++) {
               int curr_keep = 1e9, curr_swap = 1e9;
               
               if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                   curr_keep = prev_keep;
                   curr_swap = prev_swap + 1;
               }
               if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                   curr_keep = min(curr_keep, prev_swap);
                   curr_swap = min(curr_swap, prev_keep + 1);
               }
               
               prev_keep = curr_keep;
               prev_swap = curr_swap;
           }
           
           return min(prev_keep, prev_swap);
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N)$
   * Space Complexity: $O(1)$
   The optimal solution is exactly your state machine DP approach, just with the space optimized to $O(1)$.

7. **What to Practice Next:**
   Practice **DP State Machine Space Optimization**. Review problems like "House Robber", "Best Time to Buy and Sell Stock with Cooldown", and "Paint House" and solve them strictly in $O(1)$ space.
