# DSA Interview Prep Review

1. **Overall Score: 9/10**
   This would pass both an OA and a live interview. You correctly recognized the optimal mathematical approach to achieve $O(1)$ space and $O(N)$ time, avoiding the less optimal hash set or sorting methods. It shows strong problem-solving skills and careful consideration of integer overflow.

2. **Breakdown:**
   * **Correctness & edge cases:** 9/10 - Handles general cases correctly. The use of `long long` correctly prevents overflow for sum of squares up to $N=10^4$.
   * **Time complexity:** 10/10 - $O(N)$. Optimal.
   * **Space complexity:** 10/10 - $O(1)$. Optimal.
   * **Code quality:** 8/10 - Math logic is condensed and correct, but variable names `s1` and `s2` could be more descriptive (e.g., `sum_diff`, `sq_sum_diff`).
   * **Pattern recognition:** 10/10 - Mathematical approach for finding missing/duplicate numbers is exactly what top-tier interviewers look for when they ask for $O(1)$ space.

3. **Missed Edge Cases / Bugs:**
   No functional bugs. Your logic `s2 /= s1` relies on the fact that `s1` (the difference between duplicate and missing) can never be zero since the numbers must be distinct. This is mathematically sound.

4. **Would This Pass?**
   * **At an OA:** Pass. It will comfortably run within the time limit.
   * **At a live interview:** The interviewer will love this, but they might ask you to explain the algebra out loud or ask how you would solve it if the numbers could be negative (not applicable here, but common follow-up), or how to do it using XOR.

5. **Top 3 Improvements:**
   1. **Variable naming:** Use more explicit names like `diff` and `squareDiff` instead of `s1` and `s2`.
   2. **Preallocate answer vector:** Returning `{ (int)((s2 + s1) / 2), (int)((s2 - s1) / 2) }` inline avoids multiple `push_back` calls.
   3. **Be prepared to explain the XOR approach:** While math is $O(1)$ space, the XOR approach avoids integer overflow entirely, which is sometimes preferred in languages without arbitrary precision integers.

   *Corrected Snippet:*
   ```cpp
   class Solution {
   public:
       vector<int> findErrorNums(vector<int>& nums) {
           long long diff = 0, sqDiff = 0;
           for(long long i = 0; i < nums.size(); i++) {
               long long expected = i + 1;
               diff += nums[i] - expected;
               sqDiff += (long long)nums[i] * nums[i] - expected * expected;
           }
           long long sum = sqDiff / diff;
           return {(int)(sum + diff) / 2, (int)(sum - diff) / 2};
       }
   };
   ```

6. **Optimal Solution:**
   * Time Complexity: $O(N)$
   * Space Complexity: $O(1)$
   The math approach you used is optimal. Alternatively, using bit manipulation (XOR) achieves the same optimal bounds without the risk of integer overflow (though $10^4$ constraints fit perfectly in a 64-bit integer).

7. **What to Practice Next:**
   Practice bit manipulation patterns. Try solving this exact same problem using XOR, as it's a common variation asked by interviewers to see if you can avoid overflow risks entirely. Problems like "Single Number III" are great for this.
