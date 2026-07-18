# DSA Interview Prep Review

1. **Overall Score: 8/10**
   This would pass an OA and most likely pass a live interview, but an interviewer will immediately push you on space optimization. Your DP logic is flawlessly implemented, but maintaining a full 2D array is technically suboptimal for this specific variation of the Longest Common Substring problem.

2. **Breakdown:**
   * **Correctness & edge cases:** 10/10 - Handles all test cases correctly. 
   * **Time complexity:** 10/10 - $O(N \times M)$ where $N$ and $M$ are lengths of the arrays. This is generally the expected optimal time.
   * **Space complexity:** 5/10 - $O(N \times M)$ via the 2D DP array. This can be strictly improved to $O(\min(N, M))$ using a 1D DP array since you only ever access `dp[i-1][j-1]`.
   * **Code quality:** 8/10 - Clean and easy to follow. 
   * **Pattern recognition:** 9/10 - DP for Longest Common Substring is exactly correct, but missing the space optimization keeps it from being a 10.

3. **Missed Edge Cases / Bugs:**
   No bugs. The logic properly checks bounds with `if(i && j)`.

4. **Would This Pass?**
   * **At an OA:** Pass. The constraints are small ($1000 \times 1000$), so a 10^6 integer array will easily pass memory limits.
   * **At a live interview:** The interviewer will definitely say: *"Great, that works. Can you optimize the space complexity?"* You should instantly recognize that because `dp[i][j]` only relies on `dp[i-1][j-1]`, you can reduce the 2D grid to a single 1D array.

5. **Top 3 Improvements:**
   1. **Optimize space to 1D array:** Since you only need the previous row's values, you can use a 1D array and iterate backwards, or use two rows (current and previous). This is the biggest improvement.
   2. **Avoid `if (i && j)` inside the inner loop:** You can pad the DP table with an extra row/col initialized to zero (size $N+1 \times M+1$). This removes the bounds checking branch from inside the tightest inner loop, making it faster.

   *Corrected Snippet (1D Space Optimized + 1-indexed DP):*
   ```cpp
   class Solution {
   public:
       int findLength(vector<int>& nums1, vector<int>& nums2) {
           int n = nums1.size();
           int m = nums2.size();
           // Optimize space to O(M)
           vector<int> dp(m + 1, 0);
           int ans = 0;
           
           for(int i = 1; i <= n; i++) {
               // Iterate backwards to not overwrite data we need from previous i
               for(int j = m; j >= 1; j--) {
                   if(nums1[i - 1] == nums2[j - 1]) {
                       dp[j] = dp[j - 1] + 1;
                       ans = max(ans, dp[j]);
                   } else {
                       dp[j] = 0; // Must reset since we reuse the 1D array
                   }
               }
           }
           
           return ans;
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N \times M)$
   * Space Complexity: $O(\min(N, M))$ using space-optimized DP.
   * Note: There is an advanced $O((N+M) \log (\min(N, M)))$ approach using Binary Search + Rolling Hash, but $O(N \times M)$ time with $O(M)$ space is the universally expected "optimal" answer for standard interviews.

7. **What to Practice Next:**
   Practice **DP Space Optimization**. Go back to problems like "Longest Common Subsequence", "Edit Distance", and "Knapsack", and force yourself to solve them using only a 1D array. You should reflexively look for space optimizations whenever you write a 2D DP table.
